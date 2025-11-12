#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,s=0,ans=0,a[5010],dp[5000010];
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s+=a[i];
    }
    if(n>500&&s==n)
    {
        ans=1;
        for(int i=0;i<n;i++)
            ans=ans*2%mod;
        printf("%lld",(ans+mod-n*(n-1)/2-n-1)%mod);
        return 0;
    }
    sort(a+1,a+n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=s;j>=a[i];j--)
        {
            if(j>a[i]&&dp[j])ans=(ans+dp[j])%mod;
            if(dp[j-a[i]])dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    printf("%lld",ans);
    return 0;
}
