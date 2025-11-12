#include <bits/stdc++.h>

void Freopen() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
}

using namespace std;
const int N = 2e5 + 10, M = 2e5 + 10, inf = 1e9, mod = 998244353;

int n, m;
char s[N];
int c[N];

int dp[1 << 18][19];

signed main() {
    Freopen();

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> (s + 1);

    for ( int i = 1; i <= n; i ++) cin >> c[i];

    dp[0][0] = 1;
    for ( int S = 0; S < (1 << n); S ++) {
        int res = __builtin_popcount(S);

        for ( int k = 0; k <= res; k ++)
            for ( int i = 1; i <= n; i ++) {
                if ((S >> (i - 1)) & 1) continue ;
                int T = S + (1 << (i - 1));

                if (s[res + 1] == '0') {
                    dp[T][k + 1] = (dp[T][k + 1] + dp[S][k]) % mod;
                } else {
                    if (k >= c[i]) dp[T][k + 1] = (dp[T][k + 1] + dp[S][k]) % mod;
                    else dp[T][k] = (dp[T][k] + dp[S][k]) % mod;
                }
            }
    }

    int ans = 0;
    for ( int k = 0; k <= n - m; k ++) {
        ans = (ans + dp[(1 << n) - 1][k]);
    }

    cout << ans << '\n';

    return 0;
}

/*

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/