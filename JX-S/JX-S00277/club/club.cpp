#include<bits/stdc++.h>
using namespace std;
struct T
{
    int id,val;
}a[5];
struct V
{
    int v1,v2,v3,s0;
}s[100005];
int cnt[5];
bool cmp(T x,T y)
{
    if(x.val==y.val)return cnt[x.id]<cnt[y.id];
    return x.val>y.val;
}
bool cmp1(V x,V y)
{
    int maxx=max(x.v1,max(x.v2,x.v3)),maxy=max(y.v1,max(y.v2,y.v3));
    int qx=100.0*maxx/(x.v1+x.v2+x.v3)+0.5;
    int qy=100.0*maxy/(y.v1+y.v2+y.v3)+0.5;
    if(maxx>maxy&&qx>qy)return 1;
    if(maxx<maxy&&qx<qy)return 0;
    if(maxx<maxy&&qx>qy)return 1;
    return 0;
}
bool cmpf1(V x,V y)
{
    return x.v1>y.v1;
}
bool cmpf2(V x,V y)
{
    int maxx=max(x.v1,x.v2),maxy=max(y.v1,y.v2);
    int qx=100.0*maxx/(x.v1+x.v2)+0.5;
    int qy=100.0*maxy/(y.v1+y.v2)+0.5;
    if(maxx>maxy&&qx>qy)return 1;
    return 0;
}
long long s1=0,s2=0,s3=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        bool f1=1,f2=1;
        int ans=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&s[i].v1,&s[i].v2,&s[i].v3);
            s[i].s0=(s[i].v1==0)+(s[i].v2==0)+(s[i].v3==0);
            s1+=s[i].v1,s2+=s[i].v2,s3+=s[i].v3;
            if(s[i].v2!=0||s[i].v3!=0)f1=0;
            if(s[i].v3!=0)f2=0;
        }

        //for(int i=1;i<=n;i++)
        //{
        //    printf("v1=%d v2=%d v3=%d s0=%d\n",s[i].v1,s[i].v2,s[i].v3,s[i].s0);
        //}
        if(f1)
        {
            sort(s+1,s+1+n,cmpf1);
            long long ans=0;
            for(int i=1;i<=n/2;i++)
            {
                ans+=s[i].v1;
            }
            printf("%lld",ans);
            return 0;
        }
        if(f2)
        {
            sort(s+1,s+1+n,cmpf2);
            long long ans=0;
            int c1=0,c2=0;
            for(int i=1;i<=n;i++)
            {
                if(c1<n/2&&s[i].v1>=s[i].v2)
                {
                    ans+=s[i].v1;
                    c1++;
                }
                else{
                    ans+=s[i].v2;
                    c2++;
                }
            }
            printf("%lld",ans);
            return 0;
        }
        sort(s+1,s+1+n,cmp1);
        int c=n/2;
        cnt[1]=0,cnt[2]=0,cnt[3]=0;
        for(int i=1;i<=n;i++)
        {
            a[1].id=1,a[1].val=s[i].v1;
            a[2].id=2,a[2].val=s[i].v2;
            a[3].id=3,a[3].val=s[i].v3;
            sort(a+1,a+4,cmp);
            if(cnt[a[1].id]<c)
            {
                ans+=a[1].val;
                cnt[a[1].id]++;
            }
            else if(cnt[a[2].id]<c)
            {
                ans+=a[2].val;
                cnt[a[2].id]++;
            }
            else{
                ans+=a[3].val;
                cnt[a[3].id]++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
