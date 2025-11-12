#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;
const i64 MAXN = 30, MAXM = (1 << 18) + 10, P = 998244353;
i64 n, m, fr[MAXM][MAXN], cr[MAXN];
std::string s;

void solve(void) {
    std::cin >> n >> m >> s;
    s = ' ' + s;
    for (i64 i = 1; i <= n; ++i) {
        std::cin >> cr[i];
    }
    if (n <= 18) {
        fr[0][0] = 1;
        for (i64 times = 0; times < n; ++times) {
            for (i64 mask = 0; mask < (1ll << n); ++mask) if (__builtin_popcountll(mask) == times) {
                for (i64 i = 0; i <= times; ++i) {
                    for (i64 j = 1; j <= n; ++j) if (!(mask >> (j - 1) & 1)) {
                        i64 nmask = mask ^ (1 << (j - 1));
                        if (s[times + 1] == '0') {
                            fr[nmask][i] = (fr[nmask][i] + fr[mask][i]) % P;
                        }
                        else {
                            i64 ni = i + (times - i < cr[j]);
                            fr[nmask][ni] = (fr[nmask][ni] + fr[mask][i]) % P;
                        }
                    }
    //                for (i64 j = 1; j <= n; ++j) std::cout << (mask >> (j - 1) & 1);
    //                std::cout << ' ' << i << ' ' << fr[mask][i] << '\n';
                }
            }
        }
        i64 ans = 0;
        for (i64 i = m; i <= n; ++i) {
            ans = (ans + fr[(1 << n) - 1][i]) % P;
        }
        std::cout << ans << '\n';
        return;
    }
    if (m == n) {
        auto check = [&] (void) -> bool {
            for (i64 i = 1; i <= n; ++i) {
                if (s[i] != '1') return false;
                if (!cr[i]) return false;
            }
            return true;
        };
        if (check()) {
            i64 ans = 1;
            for (i64 i = 1; i <= n; ++i) {
                ans = ans * i % P;
            }
            std::cout << ans << '\n';
        }
        else {
            std::cout << "0\n";
        }
        return;
    }
    i64 ans = 1;
    for (i64 i = 1; i <= n; ++i) {
        ans = ans * i % P;
    }
    std::cout << ans << '\n';
}

int main() {
    IG = freopen("employ.in", "r", stdin);
    IG = freopen("employ.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}
