#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5,M = 998244353;
long long dp[N][N];
int f[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
        cin >> f[i];
    sort(f+1,f+n+1);
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<=5000;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= f[i])
                dp[i][j] = (dp[i][j]+dp[i-1][j-f[i]])%M;
        }
        dp[i][5001] = dp[i-1][5001];
        for(int j = 5001-f[i];j<=5001;j++)
            dp[i][5001] = (dp[i][5001]+dp[i-1][j])%M;
    }
    long long s = 0;
    for(int i = 1;i<=n;i++)
        for(int j = f[i]+1;j<=5001;j++)
            s = (s+dp[i-1][j])%M;
    cout << s <<"\n";
    return 0;
}
