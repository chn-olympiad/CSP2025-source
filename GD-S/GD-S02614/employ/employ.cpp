#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 507;
constexpr int P = 998244353;

int n, m, ans;
int p[N], c[N];

std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    std::cin >> n >> m;
    std::cin >> s; s = "$" + s;
    std::iota(p + 1, p + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
    }
    do {
        int ct = 0, nt = 0;
        for (int i = 1; i <= n; i++) {
            if (nt >= c[p[i]]) { nt++; continue; }
            if (s[i] == '1')
                ct++;
            else
                nt++;
        }
        if (ct >= m) {
            ans = (ans + 1) % P;
        }
    } while (std::next_permutation(p + 1, p + n + 1));
    std::cout << ans % P << "\n";
    return 0;
}
