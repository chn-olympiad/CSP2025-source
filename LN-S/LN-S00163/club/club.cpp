#include <bits/stdc++.h>
using namespace std;
const int Z=1e5+1919;
int a[Z],b[Z],c[Z];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,ans=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        if(n==2)
        {
            int a1=max(a[1]+b[2],a[1]+c[2]);
            int a2=max(a[2]+b[1],a[2]+c[1]);
            int a3=max(b[1]+a[2],b[1]+c[2]);
            int a4=max(b[2]+a[1],b[2]+c[1]);
            int a5=max(c[1]+a[2],c[1]+b[2]);
            int a6=max(c[2]+a[1],c[2]+b[1]);
            printf("%d\n",max(max(max(a1,a2),max(a3,a4)),max(a5,a6)));
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                int r=max(max(a[i],b[i]),c[i]);
                ans+=r;
            }
            printf("%d\n",ans);
        }
        ans=0;
    }
    return 0;
}
