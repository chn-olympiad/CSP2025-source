#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
constexpr int mod = 998244353, N = 5e3 + 10;
int n, ans, a[N], jc[N];
bool flag = true;
int qpow(int x, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= x) %= mod;
        b >>= 1, (x *= x) %= mod;
    }
    return res;
}
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) continue;
        if (a[i] != a[i - 1]) flag = false;
    }
    if (n == 3) {
        int s = a[1] + a[2] + a[3];
        if (s > a[1] * 2) ans++;
        else if (s > a[2] * 2) ans++;
        else if (s > a[3] * 2) ans++;
    } else if (flag) {
        jc[1] = 1;
        for(int i = 2; i <= n; i++) {
            jc[i] = i * jc[i - 1] % mod;
        }
        for (int i = 3; i < n; i++) {
            ans += jc[n] * qpow(jc[n - i], mod - 2) % mod * qpow(jc[i], mod - 2) % mod;
        }
        ans += 1;
    } else {
        for (int i = (1 << n) - 1; i >= 0; i--) {
            int s  = 0, mx = 0, cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if ((1 << j) & i) {
                    cnt ++, s += a[j + 1], mx = max(mx, a[j + 1]);
                }
            }
            if (s > mx * 2) ans++;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}