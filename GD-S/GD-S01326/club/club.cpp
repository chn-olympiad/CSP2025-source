#include <bits/stdc++.h>
constexpr int N = 100'000;
int T, n, a[N + 3][4], c[4], p[N + 3], b[N + 3];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;
    while(T--) {
        std::cin >> n;
        for(int i = 1; i <= n; i++) {
            std::cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        c[1] = c[2] = c[3] = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            p[i] = std::max_element(a[i] + 1, a[i] + 4) - a[i];
            ++c[p[i]], ans += a[i][p[i]];
        }
        int lim = n >> 1;
        int q = std::max_element(c + 1, c + 4) - c;
        if(c[q] > lim) {
            int tot = 0, k = c[q] - lim;
            for(int i = 1; i <= n; i++) {
                if(p[i] == q) {
                    if(q == 1) b[++tot] = a[i][1] - std::max(a[i][2], a[i][3]);
                    if(q == 2) b[++tot] = a[i][2] - std::max(a[i][1], a[i][3]);
                    if(q == 3) b[++tot] = a[i][3] - std::max(a[i][1], a[i][2]);
                }
            }
            std::sort(b + 1, b + tot + 1);
            for(int i = 1; i <= k; i++) {
                ans -= b[i];
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}
