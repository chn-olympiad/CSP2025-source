#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],ans,dp[25000005],cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i];
    }
    dp[0]=1;
    for(long long i=1;i<n;i++)
    {
        for(long long j=b[i];j>=a[i];j--)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%998244353;
        }
        if(i>=2)
        {
            for(long long j=b[i];j>a[i+1];j--)
            {
                ans=(ans+dp[j])%998244353;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
