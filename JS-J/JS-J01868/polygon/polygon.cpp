#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
const ll M = 998244353;

ll n, ans = 0, cnt, a[N], f[N];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    if (n < 3) {
        cout << 0;
        return 0;
    }
    if (n == 3) {
        if (a[1] + a[2] > a[3]) cout << 1;
        else cout << 0;
        return 0;
    }

    f[1] = 1, f[2] = 2;
    for (ll i = 3; i <= 5000; ++i) f[i] = f[i - 1] * i % M;
    for (int i = 3; i <= n; ++i) ans = (ans + (f[n] / f[n - i]) / f[i]) % M;
    cout << ans;
    return 0;
}
