#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105, mod = 998244353;
int n, m, s[N], c[N], p[N];

signed main() {
    freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m; bool flg = true;
    for (int i = 1; i <= n; i++) { char c; cin >> c; s[i] = c - '0'; flg &= s[i]; }
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (n <= 10) {
        int ans = 0;
        for (int i = 1; i <= n; i++) p[i] = i;
        do {
            int now = 0, tot = 0;
            for (int i = 1; i <= n; i++) {
                if (now >= c[p[i]]) now++;
                else {
                    if (s[i]) tot++;
                    else now++;
                }
            } if (tot >= m) ans++;
        } while (next_permutation(p + 1, p + n + 1));
        cout << ans;
        return 0;
    }
    // if (flg) {
    //     int cnt = 0;
    //     for (int i = 1; i <= n; i++) cnt += !c[i];
    //     if (n - cnt < m) cout << 0;
    //     else {
    //         int ans = 1;
    //         for (int i = 1; i <= n; i++) (ans *= i) %= mod;
    //         cout << ans;
    //     }
    //     return 0;
    // }
    return 0;
}