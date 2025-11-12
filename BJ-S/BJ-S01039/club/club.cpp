#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
namespace pnl{
    #define reg register
    typedef long long LL;
    constexpr LL N = 100010;
    int t;
    LL n, m, res;
    LL a[3][N], b[N], f[N], g[3], h[N];
    int main() {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
        scanf("%d", &t);
        while (t--) {
            m = 0;
            res = 0;
            scanf("%lld", &n);
            for (reg int i = 1; i <= n; ++i) {
                scanf("%lld%lld%lld", &a[0][i], &a[1][i], &a[2][i]);
            }

            for (reg int i = 1; i <= n; ++i) {
                if (a[0][i] >= a[1][i] && a[0][i] >= a[2][i]) {
                    res += a[0][i];
                    f[i] = min(a[0][i] - a[1][i], a[0][i] - a[2][i]);
                    ++g[0];
                    h[i] = 0;
                } else if (a[1][i] >= a[0][i] && a[1][i] >= a[2][i]){
                    res += a[1][i];
                    f[i] = min(a[1][i] - a[0][i], a[1][i] - a[2][i]);
                    ++g[1];
                    h[i] = 1;
                } else {
                    res += a[2][i];
                    f[i] = min(a[2][i] - a[0][i], a[2][i] - a[1][i]);
                    ++g[2];
                    h[i] = 2;
                }
            }         

            if (g[0] > n / 2) {
                for (reg int i = 1; i <= n; ++i) {
                    if (h[i] == 0) b[++m] = f[i];
                }

                sort(b + 1, b + m + 1);
                for (reg int i = 1; i <= g[0] - n / 2; ++i) {
                    res -= b[i];
                }
            }

            if (g[1] > n / 2) {
                for (reg int i = 1; i <= n; ++i) {
                    if (h[i] == 1) b[++m] = f[i];
                }

                sort(b + 1, b + m + 1);
                for (reg int i = 1; i <= g[1] - n / 2; ++i) {
                    res -= b[i];
                }
            }

            if (g[2] > n / 2) {
                for (reg int i = 1; i <= n; ++i) {
                    if (h[i] == 2) b[++m] = f[i];
                }

                sort(b + 1, b + m + 1);
                for (reg int i = 1; i <= g[2] - n / 2; ++i) {
                    res -= b[i];
                }
            }

            printf("%lld\n", res);
            g[0] = 0;
            g[1] = 0;
            g[2] = 0;
        }

        return 0;
    }
}

int main() {
    // Cogito ergo sum
    pnl::main();
    return 0;
}