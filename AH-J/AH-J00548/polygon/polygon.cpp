#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long dp[5005][5005];
const long long M=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=5000;j++)
        {
            dp[i][j]%=M;
            dp[i+1][min(j+a[i+1],5000)]+=dp[i][j];
            dp[i+1][j]+=dp[i][j];
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(a[i]+1,5000);j<=5000;j++)
        {
            ans=(ans+dp[i-1][j])%M;
        }
    }
    cout<<ans;
    return 0;
}
