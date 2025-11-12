#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int mod = 998244353;
int n, m, c[N];
char s[N];
namespace sub10 {
    int id[15];
    inline void solve() {
        for (int i = 1; i <= n; i++) id[i] = i;
        int ans = 0;
        do {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt >= c[id[i]]) cnt++;
                else if (s[i] == '0') cnt++;
            }
            ans += (cnt <= n - m);
        } while (next_permutation(id + 1, id + n + 1));
        cout << ans << endl;
    }
}
namespace sub18 {
    int dp[1 << 18][20];
    inline void solve() {
        dp[0][0] = 1;
        for (int sta = 1; sta < (1 << n); sta++) {
            int cnt = __builtin_popcount(sta);
            for (int k = 0; k <= cnt; k++) {
                for (int i = 0; i < n; i++) {
                    if (sta >> i & 1) {
                        if (s[cnt] == '1' && cnt - k < c[i+1])
                            dp[sta][k] += dp[sta ^ (1 << i)][k-1];
                        if (s[cnt] == '0' || cnt - k - 1 >= c[i+1]) dp[sta][k] += dp[sta ^ (1 << i)][k];
                        dp[sta][k] %= mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = m; i <= n; i++)
            ans = (ans + dp[(1 << n) - 1][i]) % mod;
        cout << ans << endl;
    }
}
namespace subC {
    inline void solve() {
        int res = 1;
        for (int i = 1; i <= n; i++)
            if (s[i] == '0' || c[i] == 0)
                res = 0;
        for (int i = 2; i <= n; i++)
            res = res * i % mod;
        cout << res << endl;
    }
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (n <= 10) sub10::solve();
    else if (n <= 18) sub18::solve();
    else if (m == n) subC::solve();
    else cout << 0 << endl;
    return 0;
}
