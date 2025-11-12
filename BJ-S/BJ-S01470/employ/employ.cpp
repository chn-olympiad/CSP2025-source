#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, s[505], c[505], p[15], sss;
long long ans;
const int MOD = 998244353;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%1d", s+i), sss += s[i];
    for (int i = 1; i <= n; ++i) scanf("%d", c+i);
    if (n <= 10) {
        for (int i = 1; i <= n; ++i) p[i] = i;
        do {
            int c1 = 0, c2 = 0;
            for (int i = 1; i <= n; ++i)
                if (!s[i]) ++c1;
                else if (c1 >= c[p[i]]) ++c1;
                else ++c2;
            if (c2 >= m) ++ans;
        } while (next_permutation(p+1, p+n+1));
        printf("%lld\n", ans);
    } else if (sss == n) {
        ans = 1;
        for (int i = 1; i <= n; ++i) ans = ans * i % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
