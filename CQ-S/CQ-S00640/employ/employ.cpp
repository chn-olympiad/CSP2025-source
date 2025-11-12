#include <bits/stdc++.h>

void IO(const std::string & s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;

constexpr int N = 505;
constexpr int mod = 998244353;

int n, m, c[N];
std::string s;

namespace sol1 {
    i64 f[20][1 << 18];

    void solve() {
        f[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int S = 0; S < (1 << n); S++) {
                if (__builtin_popcount(S) == i - 1) {
                    for (int j = 0; j < i; j++) {
                        for (int k = 1; k <= n; k++) {
                            if ((S >> k - 1) & 1) continue;
                            int x = (s[i] == '1' && c[k] >= i - j);
                            (f[j + x][S ^ (1 << k - 1)] += f[j][S]) %= mod;
                        }
                    }
                }
            }
        }

        i64 ans = 0;
        for (int i = m; i <= n; i++) {
            (ans += f[i][(1 << n) - 1]) %= mod;
        }

        std::cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    IO("employ");

    std::cin >> n >> m >> s;
    s = " " + s;

    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
    }

    sol1::solve();
    return 0;
}