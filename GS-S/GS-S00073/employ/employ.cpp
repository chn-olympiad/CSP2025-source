#include <bits/stdc++.h>
#define MAXN (signed)(600)
#define int long long
#define MOD 998244353
using namespace std;
int n,m;
int c[MAXN],dp[MAXN][MAXN];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)dp[i][1]=i;
    //dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i&&j<=m;j++)
        {
            if(i!=j&&j!=1)dp[i][j]=dp[i-1][j];
            if(j-1<c[i])
            {
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j]=dp[i][j]%998244353;
            }
            cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][m];
}
