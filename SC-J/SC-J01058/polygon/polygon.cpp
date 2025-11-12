#include <cstdio>
#include <algorithm>
using namespace std;
struct IO {
    IO () {
        freopen("polygon.in", "r", stdin);
        freopen("polygon.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
const int N = 5005;
const int P = 998244353;
typedef long long ll;
int n, mx;
int a[N];
int f[N][N][3], fac[N], ifac[N];
ll qpow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        a = a * a % P, b >>= 1;
    }
    return res;
}
ll C (int n, int m) {
    return (ll)fac[n] * ifac[m] % P * ifac[n - m];
}
int main () {
    scanf("%d", &n);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (ll)fac[i - 1] * i % P;
    ifac[n] = qpow(fac[n], P - 2);
    for (int i = n; i >= 1; i--)
        ifac[i - 1] = (ll)ifac[i] * i % P;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), mx = max(mx, a[i]);
    sort(a + 1, a + n + 1);
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= mx; j++) {
            for (int k = 0; k <= min(2, i); k++) {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= a[i]) (f[i][j][k] += f[i - 1][j - a[i]][k > 0 ? k - 1 : 0]) %= P;
                // printf("f[%d][%d][%d]:%lld\n", i, j, k, f[i][j][k]);
            }
            // puts("");
        }
    ll ans = 0;
    for (int i = 3; i <= n; i++)
        ans = (ans + C(n, i)) % P;
    // printf("ans:%lld\n", ans);
    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= a[i]; j++)
            ans = (ans - f[i - 1][j][2] + P) % P;
    printf("%lld\n", ans);
    return 0;
}