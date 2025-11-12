#include <bits/stdc++.h>
using namespace std;
struct node
{
    int f1,f2,f3;
}a[100008];
struct piar
{
    int feel,num,cl;
}maxn[100008];
int t,n,cnt,ans,c[4],res;
bool cmp(node x,node y)
{
    return x.f1>y.f1;
}
bool cmp1(piar x,piar y)
{
    return x.feel>y.feel;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int patb=1;
    while(t--)
    {
        c[1]=0,c[2]=0,c[3]=0;
        res=0;
        cin>>n;
        //int maxx,maxn;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].f1>>a[i].f2>>a[i].f3;
        }
        if(n==2)
            patb=2;
        if(patb==2)
        {
            int q1=a[1].f1+max(a[2].f2,a[2].f3);
            int q2=a[1].f2+max(a[2].f1,a[2].f3);
            int q3=a[1].f3+max(a[2].f2,a[2].f1);
            ans=max(q1,max(q2,q3));
            cout<<ans<<'\n';
        }
        if(patb==1)
        {
            for(int i=1;i<=n;i++)
            {
                maxn[i].feel=max(a[i].f1,max(a[i].f2,a[i].f3));
                maxn[i].num=i;
                if(a[i].f1>=a[i].f2&&a[i].f1>=a[i].f3)
                    maxn[i].cl=1;
                else if(a[i].f2>=a[i].f1&&a[i].f2>=a[i].f3)
                    maxn[i].cl=2;
                else if(a[i].f3>=a[i].f2&&a[i].f3>=a[i].f1)
                    maxn[i].cl=3;
            }
            sort(maxn+1,maxn+n+1,cmp1);
            for(int i=1;i<=n;i++)
            {
                if(c[maxn[i].cl]+1<=(n/2))
                    res+=maxn[i].feel,c[maxn[i].cl]++;
                else{
                        int nn=maxn[i].num;
                    if(a[nn].f1>=a[nn].f2&&a[nn].f3>=a[nn].f1)
                    {
                        res+=a[nn].f1,c[1]++;
                    }
                    else if(a[nn].f3>=a[nn].f2&&a[nn].f1>=a[nn].f3)
                    {
                        res+=a[nn].f3,c[3]++;
                    }
                    else if(a[nn].f2>=a[nn].f1&&a[nn].f3>=a[nn].f2)
                    {
                        res+=a[nn].f2,c[2]++;
                    }
                }
            }
            cout<<res<<"\n";
        }
    }
    return 0;
}
