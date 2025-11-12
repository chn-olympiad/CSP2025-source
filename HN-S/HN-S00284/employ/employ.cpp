#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

constexpr int MAXN = 500 + 10;
constexpr int MOD = 998244353;

int n, m;
int f[MAXN][MAXN];

int solve();

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;

    int ans = solve();

    std::cout << ans << '\n';

    return 0;
}

int solve() {
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i][1] = 1;
        for (int j = 1; j <= std::min(m, i); j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            f[i][j] %= MOD;
        }
    }
    long long prod = 1;
    for (long long i = 2; i <= m; i++) {
        prod *= i;
        prod %= MOD;
    }
    long long ans = f[n][m] * prod;
    ans %= MOD;
    return static_cast<int>(ans);
}
