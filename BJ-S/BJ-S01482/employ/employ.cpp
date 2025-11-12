#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    vector<vector<int>> dp(1<<n,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int pos=__builtin_popcount(mask);
        for(int h=0;h<=n;h++)
        {
            if(dp[mask][h]==0) continue;
            for(int k=0;k<n;k++)
            {
                if(mask>>k&1) continue;
                int f=pos-h;
                if(f>=c[k]) dp[mask|(1<<k)][h]=(dp[mask|(1<<k)][h]+dp[mask][h])%MOD;
                else
                {
                    if(s[pos]=='1') dp[mask|(1<<k)][h+1]=(dp[mask|(1<<k)][h+1]+dp[mask][h])%MOD;
                    else dp[mask|(1<<k)][h]=(dp[mask|(1<<k)][h]+dp[mask][h])%MOD;
                }
            }
        }
    }
    int ans=0;
    for(int h=m;h<=n;h++)
    {
        ans=(ans+dp[(1<<n)-1][h])%MOD;
    }
    cout<<ans;
    return 0;
}
