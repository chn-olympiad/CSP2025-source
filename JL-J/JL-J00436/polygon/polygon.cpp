#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int n;
int a[5010];
ll jc[5010], ny[5010];
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll C(ll a, ll b) {
    if (a < b) return 0;
    return jc[a] * ny[b] % mod * ny[a - b] % mod;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    bool fl = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != 1) fl = 0;
    }
    if (fl) {
        jc[0] = 1;
        for (int i = 1; i <= 5000; i++) jc[i] = jc[i - 1] * i % mod;
        ny[5000] = qpow(jc[5000], mod - 2);
        for (int i = 4999; i >= 0; i--) ny[i] = ny[i + 1] * (i + 1) % mod;
        ll ans = 0;
        for (int i = 3; i <= n; i++) ans = (ans + C(n, i)) % mod;
        printf("%lld\n", ans);
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int s = 0, mx = -1, cnt = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) {
                cnt++;
                s += a[j];
                mx = max(mx, a[j]);
            }
        if (cnt >= 3 and s > 2 * mx) {
            ans++;
            if (ans >= mod) ans -= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
