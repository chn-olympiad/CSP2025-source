#include<bits/stdc++.h>
#define int long long 
const int mod=998244353;
using namespace std;
int n,m,ans,flag=1,tot;
string s;
int c[505];
int fac[505];
int dp[300005][20];
void add(int &x,int k)
{
    x=x+k;
    if(x>=mod) x-=mod;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fac[0]=1;
    cin>>n>>m>>s;
    for(int i=0;i<n;i++) flag=flag&(s[i]-'0');
    for(int i=1;i<=n;i++) cin>>c[i],fac[i]=fac[i-1]*i%mod;
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++)
    {
        int u=__builtin_popcount(i);
        for(int j=0;j<=u;j++)
        {
            if(j==m)
            {
                if(i==((1<<n)-1)) continue;
                int now=fac[n-u];
                add(dp[(1<<n)-1][m],dp[i][j]*now%mod);
                continue;
            }
            if(!dp[i][j]) continue;
            for(int k=1;k<=n;k++)
            {
                if((i>>(k-1))&1) continue;
                if(c[k]>u-j&&s[u]=='1') add(dp[i|(1<<(k-1))][j+1],dp[i][j]);
                else add(dp[i|(1<<(k-1))][j],dp[i][j]);
            }
        }
    }
    for(int i=m;i<=n;i++) add(ans,dp[(1<<n)-1][i]);//,cout<<i<<" "<<dp[(1<<n)-1][i]<<"\n";
    cout<<ans;
}
/*3 2
101
1 1 2
*/