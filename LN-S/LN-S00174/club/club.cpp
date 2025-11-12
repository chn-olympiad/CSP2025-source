#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int half;
struct p
{
    int a1,a2,a3;
};
int n,ans=0;
p a[N];
int c1[N],c2[N],c3[N];
int len1,len2,len3;
inline int max_(int u,int v,int w)
{
    return max(u,max(v,w));
}
bool cmp1(const p u,const p v)
{
    return u.a1<v.a1;
}
bool cmp2(const p u,const p v)
{
    return u.a2<v.a2;
}
bool cmp3(const p u,const p v)
{
    return u.a3<v.a3;
}
void f(int dep,int sum)
{
    if(dep==n) ans=max(ans,sum);
    if(len1<half)
    {
        len1++;
        f(dep+1,sum+a[dep].a1);
        len1--;
    }
    if(len2<half)
    {
        len2++;
        f(dep+1,sum+a[dep].a2);
        len2--;
    }
    if(len3<half)
    {
        len3++;
        f(dep+1,sum+a[dep].a3);
        len3--;
    }
}
void solve()
{
    len1=len2=len3=ans=0;
    scanf("%d",&n);//n<=100005
    half=n>>1;
    if(n<=10)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
        }
        f(0,0);
        printf("%d\n",ans);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
        int tmp=max_(a[i].a1,a[i].a2,a[i].a3);
        if(a[i].a1==tmp)
        {
            c1[++len1]=i;
            ans+=a[i].a1;
        }
        else if(a[i].a2==tmp)
        {
            c2[++len2]=i;
            ans+=a[i].a2;
        }
        else
        {
            c3[++len3]=i;
            ans+=a[i].a3;
        }
    }
    if(len1>half)
    {
        sort(a+1,a+1+n,cmp1);
        for(int i=half;i<=len1;i++)
        {
            if(a[i].a2>a[i].a3)
            {
                ans-=a[i].a1-a[i].a2;
                len2++;
            }
            else
            {
                ans-=a[i].a1-a[i].a3;
                len3++;
            }
        }
    }
    if(len2>half)
    {
        sort(a+1,a+1+n,cmp2);
        for(int i=half;i<=len2;i++)
        {
            if(a[i].a1>a[i].a3)
            {
                ans-=a[i].a2-a[i].a1;
                len2++;
            }
            else
            {
                ans-=a[i].a2-a[i].a3;
                len3++;
            }
        }
    }
    if(len3>half)
    {
        sort(a+1,a+1+n,cmp3);
        for(int i=half;i<=len3;i++)
        {
            if(a[i].a1>a[i].a2)
            {
                ans-=a[i].a3-a[i].a1;
                len2++;
            }
            else
            {
                ans-=a[i].a3-a[i].a2;
                len3++;
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;// t <=5
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}
/*





*/
