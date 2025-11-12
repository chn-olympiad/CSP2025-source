#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
int t;
int n;
long long ans;
struct node
{
    long long a;int b;int c;
    long long maxp,midp;
    int lmax;
    long long maxmid;
}p[maxn];
int amax,bmax,cmax;
bool cmp(node a,node b)
{
    return a.maxmid<b.maxmid;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int T=1;T<=t;T++)
    {
        cin>>n;
        ans=0;
        amax=0;bmax=0;cmax=0;
        int c0=0;
        for(int i=1,a1,b1,c1;i<=n;i++)
        {
            cin>>a1>>b1>>c1;
            p[i].a=a1;p[i].b=b1;p[i].c=c1;
            if(a1>b1&&a1>c1){p[i].maxp=a1;p[i].lmax=1;amax++;}
            if(b1>a1&&b1>c1){p[i].maxp=b1;p[i].lmax=2;bmax++;}
            if(c1>a1&&c1>b1){p[i].maxp=c1;p[i].lmax=3;cmax++;}
            if(a1==b1&&a1>c1&&b1>c1){p[i].maxp=a1;p[i].lmax=1;amax++;}
            if(a1==c1&&a1>b1&&c1>b1){p[i].maxp=a1;p[i].lmax=1;amax++;}
            if(b1==c1&&b1>a1&&c1>a1){p[i].maxp=b1;p[i].lmax=2;bmax++;}
            p[i].midp=a1+b1+c1-max(a1,max(b1,c1))-min(a1,min(b1,c1));
            p[i].maxmid=p[i].maxp-p[i].midp;
        }
        int lim=n/2;
        for(int i=1;i<=n;i++)
            ans+=p[i].maxp;
        int goout=0;
        sort(p+1,p+n+1,cmp);
        if(amax>lim)
        {
            for(int i=1;i<=n&&goout<amax-lim;i++)
            {
                if(p[i].lmax==1)
                {
                    ans-=p[i].maxmid;
                    goout++;
                }
            }
        }
        if(bmax>lim)
        {
            for(int i=1;i<=n&&goout<bmax-lim;i++)
            {
                if(p[i].lmax==2)
                {
                    ans-=p[i].maxmid;
                    goout++;
                }
            }
        }
        if(cmax>lim)
        {
            for(int i=1;i<=n&&goout<cmax-lim;i++)
            {
                if(p[i].lmax==3)
                {
                    ans-=p[i].maxmid;
                    goout++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
