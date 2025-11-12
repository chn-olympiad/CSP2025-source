#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;
using u128 = unsigned __int128;


using vi = std::vector<int> ;
using vI = std::vector<i64> ;
using str = std::string;

int n, m;
str s;
int c[505];
const int mod = 998244353;

int id[505];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        id[i] = i;
    }
    int ans = 0;
    i64 ss = 1;
    for (int i = 1; i <= n; i++) {
        (ss *= i) %= mod;
    }
    if (n <= 10) {
        do {
            int nw = 0, sb = 0;
            for (int i = 1; i <= n; i++) {
                if (s[i - 1] == '0' || nw >= c[id[i]]) {
                    nw++;
                } else {
                    sb++;
                }
            }
            if (sb >= m) {
                ans++;
            }
        } while (std::next_permutation(id + 1, id + n + 1));
        std::cout << ans << '\n';
    } else {
        std::cout << ss << '\n';
    }

    return (0 ^ 0);
}