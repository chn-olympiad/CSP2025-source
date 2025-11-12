#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
int n,a[N],b[N],c[N];
int x[N],y[N],z[N],xx,yy,zz,ans;


signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%lld",&T);
    while(T--)
    {
        xx=yy=zz=0;
        ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=b[i])
            {
                if(a[i]>=c[i])//a
                {
                    if(b[i]>=c[i])//abc
                    {
                        x[++xx]=b[i]-a[i];
                        ans+=a[i];
                    }
                    else//acb
                    {
                        x[++xx]=c[i]-a[i];
                        ans+=a[i];
                    }
                }
                else//cab
                {
                    z[++zz]=a[i]-c[i];
                    ans+=c[i];
                }
            }
            else
            {
                if(b[i]>=c[i])//b
                {
                    if(a[i]>=c[i])//bac
                    {
                        y[++yy]=a[i]-b[i];
                        ans+=b[i];
                    }
                    else//bca
                    {
                        y[++yy]=c[i]-b[i];
                        ans+=b[i];
                    }
                }
                else//cba
                {
                    z[++zz]=b[i]-c[i];
                    ans+=c[i];
                }
            }
        }
        int dd=n/2;
        if(xx>dd)
        {
            sort(x+1,x+1+xx);
            for(int i=xx;i>dd;i--)
                ans+=x[i];
        }
        else if(yy>dd)
        {
            sort(y+1,y+1+yy);
            for(int i=yy;i>dd;i--)
                ans+=y[i];
        }
        else if(zz>dd)
        {
            sort(z+1,z+1+zz);
            for(int i=zz;i>dd;i--)
                ans+=z[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
