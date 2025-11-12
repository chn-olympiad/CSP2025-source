#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int INF=0x3f3f3f3f;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int n;cin>>n;vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.begin()+1+n);

    vector<vector<int>> dp(n+5,vector<int>(5010,-INF));
    int s=0;int ans=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int cnt=2;cnt<i;cnt++)
        {
            for(int sum=a[i]+1;sum<=s;sum++)
            {
                if(dp[cnt][sum]==-INF) continue ;
                ans=(ans+dp[cnt][sum])%mod;
            }
        }

        s+=a[i];
        for(int cnt=i-1;cnt>=0;cnt--)
        {
            for(int sum=s;sum>=0;sum--)
            {
                if(dp[cnt][sum]==-INF) continue ; 
                if(dp[cnt+1][sum+a[i]]==-INF) dp[cnt+1][sum+a[i]]=0;
                dp[cnt+1][sum+a[i]]=(dp[cnt+1][sum+a[i]]+dp[cnt][sum])%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
