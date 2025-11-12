#include <bits/stdc++.h>

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    constexpr int MOD = 998'244'353;

    int n, m; std::cin >> n >> m;
    std::string s; std::cin >> s; s = ' ' + s;
    std::vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) { std::cin >> c[i]; }
    std::sort(c.begin() + 1, c.begin() + n + 1);

    auto Add = [&](int &x, int y) {
        x += y; if (x >= MOD) { x -= MOD; }
    };

    if (n <= 18) {
        std::vector<std::vector<int>> f(1 << n, std::vector<int>(n + 1));
        f[0][0] = 1;
        for (int i = 1; i < (1 << n); i++) {
            int w = __builtin_popcount(i);
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) { continue; }
                int I = i ^ (1 << j);
                for (int k = 0; k < w; k++) {
                    if (f[I][k]) { Add(f[i][k + (s[w] == '0' || k >= c[j + 1])], f[I][k]); }
                }
            }
        }
        int Ans = 0;
        for (int i = 0; i <= n - m; i++) { Add(Ans, f[(1 << n) - 1][i]); }
        std::cout << Ans << '\n';
        return 0;
    }

    if (m == 1) {
        int Ans = 1, pre = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') { continue; }
            int k = 0;
            while (k + 1 <= n && c[k + 1] <= i - 1) { k++; }
            Ans = 1ll * Ans * (k - pre) % MOD; pre++;
        }
        for (int i = 1; i <= n - pre; i++) { Ans = 1ll * Ans * i % MOD; }
        int Fac = 1;
        for (int i = 1; i <= n; i++) { Fac = 1ll * Fac * i % MOD; }
        std::cout << (Fac - Ans + MOD) % MOD << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == '0' || !c[i]) { std::cout << "0\n"; return 0; }
    }

    int Fac = 1;
    for (int i = 1; i <= n; i++) { Fac = 1ll * Fac * i % MOD; }
    std::cout << Fac << '\n';

    return 0;
}