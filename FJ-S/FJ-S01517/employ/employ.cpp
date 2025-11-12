#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int N = 18, mod = 998244353;

int n, m, c[N], f[1 << N][N + 1];
std::string s;

void add(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) cin >> c[i];
    // std::cerr << "ok";
    f[0][0] = 1;
    for (int i = 0; i < 1 << n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) cnt += i >> j & 1;
        // std::cerr << cnt << "\n";
        for (int j = 0; j < n; j++) if (!(i >> j & 1)) {
            for (int k = 0; k < n; k++) {
                add(f[i | 1 << j][k + (c[j] <= k || s[cnt] == '0')], f[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n - m; i++) add(ans, f[(1 << n) - 1][i]);
    cout << ans << "\n";
    return 0;
}