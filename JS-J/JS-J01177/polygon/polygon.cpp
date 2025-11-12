#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
long long dp[5009];
int a[5009];
long long ans;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i]+1;j<=5001;j++)
        {
            ans=(ans+dp[j])%mod;
        }
        for(int j=5001;j>=1;j--)
        {
            dp[min(5001,j+a[i])]=(dp[min(5001,j+a[i])]+dp[j])%mod;
        }
        for(int j=1;j<i;j++)
        {
            dp[min(5001,a[i]+a[j])]=(dp[min(5001,a[i]+a[j])]+1)%mod;
        }
    }
    cout<<ans;
    return 0;
}
