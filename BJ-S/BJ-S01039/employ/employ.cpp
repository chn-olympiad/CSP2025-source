#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
namespace pnl{
    #define reg register
    typedef long long LL;
    constexpr LL N = 510;
    LL n, m, tmp = 1, res = 0;
    int a[N], b[N], c[N];
    int main() {
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
        scanf("%lld%lld", &n, &m);
        string s;
        cin >> s;
        for (reg int i = 1; i <= n; ++i) {
            if (s[i - 1] == '0') a[i] = 0;
            else a[i] = 1;
        }

        for (reg int i = 1; i <= n; ++i) {
            scanf("%lld", &c[i]);
        }

        for (reg int i = 1; i <= n; ++i) {
            b[i] = i;
            tmp = tmp * i;
        }

        for (reg int _ = 1; _ <= tmp; ++_) {
            reg int k = 0;
            for (reg int i = 1, j = 0; i <= n; ++i) {
                if (a[i] == 0 || j >= c[b[i]]) {
                    ++j;
                } else {
                    ++k;
                }
            }

            if (k >= m) ++res;
            next_permutation(b + 1, b + n + 1);
        }

        printf("%lld\n", res);
        return 0;
    }
}

int main() {
    // Cogito ergo sum
    pnl::main();
    return 0;
}