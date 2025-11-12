#include<bits/stdc++.h>
using namespace std;
const int N = 510, P = 998244353;
int s[N], c[N];
int dp[1 << 20][20];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string v;
    cin >> v;
    for(int i = 1; i <= n; i++) s[i] = v[i - 1] - '0';
    for(int i = 1; i <= n; i++) cin >> c[i];
    dp[0][0] = 1;
    for(int i = 1; i < (1 << n); i++)
    {
        int cnt = 0;
        for(int j = 1, we = 1; j <= n; j++, we <<= 1)
            if(i & we) cnt++;
        for(int j = 1, we = 1; j <= n; j++, we <<= 1)
        {
            if((i & we) == 0) continue;
            if(s[cnt] == 0)
            {
                for(int k = 0; k <= cnt; k++) dp[i][k] = (dp[i][k] + dp[i ^ we][k]) % P;
                continue;
            }
            //(cnt-1)-c[j]
            for(int k = 0; k <= cnt - c[j] - 1; k++)
                dp[i][k] = (dp[i][k] + dp[i ^ we][k]) % P;
            for(int k = max(1, cnt - c[j] + 1); k <= cnt; k++)
                dp[i][k] = (dp[i][k] + dp[i ^ we][k - 1]) % P;
        }
    }
    int res = 0;
    for(int i = m; i <= n; i++) res = (res + dp[(1 << n) - 1][i]) % P;
    cout << res;
    return 0;
}