#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
namespace pnl{
    #define reg register
    typedef long long LL;
    constexpr LL N = 1010;
    LL n, m;
    int c[N], d[N];
    string a[N], b[N];
    int main() {
        freopen("replace.in", "r", stdin);
        freopen("replace.out", "w", stdout);
        scanf("%lld%lld", &n, &m);
        for (reg int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }

        for (reg int i = 1; i <= m; ++i) {
            string s, t;
            cin >> s >> t;
            LL res = 0;
            c[0] = 1;
            for (reg int j = 1; j <= s.size(); ++j) {
                if (s[j - 1] == t[j - 1]) c[j] = c[j - 1];
                else c[j] = 0;
            }

            d[s.size() + 1] = 1;
            for (reg int j = s.size(); j >= 1; --j) {
                if (s[j - 1] == t[j - 1]) d[j] = d[j + 1];
                else d[j] = 0;
            }            

            for (reg int j = 1; j <= n; ++j) {
                for (reg int k = 1; k <= s.size() - a[j].size() + 1; k++) {
                    if (!c[k - 1]) break;
                    if (!d[k + a[j].size()]) continue;
                    bool flg = 1;
                    for (reg int _ = 1; _ <= a[j].size(); ++_) {
                        if (s[k + _ - 2] != a[j][_ - 1]) {
                            flg = 0;
                            break;
                        }

                        if (t[k + _ - 2] != b[j][_ - 1]) {
                            flg = 0;
                            break;
                        }
                    }

                    if (flg) ++res;
                }
            }

            printf("%lld\n", res);
        }

        return 0;
    }
}

int main() {
    // Cogito ergo sum
    pnl::main();
    return 0;
}