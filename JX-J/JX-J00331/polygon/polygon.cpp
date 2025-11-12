#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5037],ans,m,q[5037],suma[5037];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        suma[i]=suma[i-1]+a[i];
    }
    q[2]=1;
    for(int i=3;i<=5000;i++)
    {
        q[i]=q[i-1]*2+1;
        q[i]%=mod;
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        for(int j=1;i-j>=2;j++)
        {
            int sum=a[i];
            for(int l=i-j;l>=1;l--)
            {
                sum+=a[l];
                if(sum>a[i]*2)
                {
                    ans++;
                    if(l>=2)
                    {
                        ans+=q[l];
                    }
                    sum-=a[l];
                }
            }
        }
    }
    ans%=mod;
    printf("%d",ans);
    return 0;
}
