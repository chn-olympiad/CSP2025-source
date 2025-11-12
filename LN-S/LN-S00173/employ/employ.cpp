#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n,m;
    cin >> n >> m;

    vector<int> c(n + 1),s(n + 1);

    bool fd0 = 0;

    for (int i = 1;i <= n;i++){
        char ch;
        cin >> ch;

        if (!(s[i] = ch - 48))
            fd0 = 1;
    }

    for (int i = 1;i <= n;i++)
        cin >> c[i];

    if (n <= 20){
        vector<vector<int>> dp(1 << n,vector<int>(n + 1));

        dp[0][0] = 1;

        int ans = 0;

        for (int i = 0;i < 1 << n;i++){
            int p = __builtin_popcount(i);

            for (int j = 0;j <= p;j++){
                for (int k = 1;k <= n;k++){
                    if (~i & 1 << k - 1){
                        if (c[k] > p - j&&s[p + 1])
                            dp[i | 1 << k - 1][j + 1] += dp[i][j],dp[i | 1 << k - 1][j + 1] %= mod;
                        else
                            dp[i | 1 << k - 1][j] += dp[i][j],dp[i | 1 << k - 1][j] %= mod;
                    }
                }
            }
        }

        for (int i = m;i <= n;i++)
            ans += dp[(1 << n) - 1][i],ans %= mod;

        cout << ans << '\n';

        return 0;
    }
    int ans = 1;

    for (int i = n;i;i--)
        ans = ans * 1LL * i % mod;

    cout << ans << '\n';

    return 0;
}
