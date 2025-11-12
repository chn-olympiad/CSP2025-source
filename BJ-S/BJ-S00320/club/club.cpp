#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long t,n,a[100005][3],p[100005],b[100005],c[100005],s[100005],cnt,ans,x,y,z;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=0;
        x=y=z=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);

            if(a[i][0]<=a[i][1] && a[i][1]<=a[i][2])
                p[i]=2,b[i]=a[i][2],c[i]=a[i][2]-a[i][1],++z;

            else if(a[i][0]<=a[i][2] && a[i][2]<=a[i][1])
                p[i]=1,b[i]=a[i][1],c[i]=a[i][1]-a[i][2],++y;

            else if(a[i][1]<=a[i][0] && a[i][0]<=a[i][2])
                p[i]=2,b[i]=a[i][2],c[i]=a[i][2]-a[i][0],++z;

            else if(a[i][1]<=a[i][2] && a[i][2]<=a[i][0])
                p[i]=0,b[i]=a[i][0],c[i]=a[i][0]-a[i][2],++x;

            else if(a[i][2]<=a[i][0] && a[i][0]<=a[i][1])
                p[i]=1,b[i]=a[i][1],c[i]=a[i][1]-a[i][0],++y;

            else if(a[i][2]<=a[i][1] && a[i][1]<=a[i][0])
                p[i]=0,b[i]=a[i][0],c[i]=a[i][0]-a[i][1],++x;

            ans += b[i];
        }
        cnt=0;
        if(x>n/2)
        {
            for(int i=1;i<=n;++i)
                if(p[i]==0)
                    s[++cnt]=c[i];
            sort(s+1,s+cnt+1);
            for(int i=1;i<=x-n/2;++i)
                ans -= s[i];
            printf("%lld\n",ans);
        }
        else if(y>n/2)
        {
            for(int i=1;i<=n;++i)
                if(p[i]==1)
                    s[++cnt]=c[i];
            sort(s+1,s+cnt+1);
            for(int i=1;i<=y-n/2;++i)
            {
                ans -= s[i];
            }
            printf("%lld\n",ans);
        }
        else if(z>n/2)
        {
            for(int i=1;i<=n;++i)
                if(p[i]==2)
                    s[++cnt]=c[i];
            sort(s+1,s+cnt+1);
            for(int i=1;i<=z-n/2;++i)
                ans -= s[i];
            printf("%lld\n",ans);
        }
        else
        {
            printf("%lld\n",ans);
        }
    }
    return 0;
}
