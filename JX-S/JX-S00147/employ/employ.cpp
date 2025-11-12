#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
int n, m;
string s;
int c[N], a[N];
int ans;
int solve () {
    int no_win = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        // cout << a[i] << ' ';
        if (cnt + (n - i + 1) < m) break;
        if (no_win >= c[a[i]] || s[i - 1] == '0') {
            ++ no_win;
            continue;
        }
        ++ cnt;
    }
    return cnt;
}
int main () {
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    cin >> n >> m;
    /*
    YXY, i like you.
    */
    cin >> s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) a[i] = i;
    int x = solve ();
    if (x >= m) ++ ans;
    while (next_permutation (a + 1, a + 1 + n)) {
        int cnt = solve ();
        if (cnt >= m) ans = (ans + 1) % mod;
    }
    cout << ans % mod << "\n";
    return 0;
}
