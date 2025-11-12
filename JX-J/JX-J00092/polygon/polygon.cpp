#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353, INF = 1e9;

long long qpow (long long x, long long y, long long p) {
    long long res = 1;
    while (y) {
        if (y & 1) (res *= x) %= p;
        (x *= x) %= p;
        y >>= 1;
    }
    return res;
}

int main () {

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mx = 0;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (mx == 1) {
        cout << (qpow(2, n, MOD) - 1 - n - (n * (n - 1) >> 1) + MOD) % MOD;
        return 0;
    }
    int ans = 0;
    for (int i = 7; i < 1 << n; i++) {
        int mxx = 0, sum = 0;
        for (int j = 1; j <= n; j++) if (i >> j - 1 & 1) {
            mxx = max(mxx, a[j]);
            sum += a[j];
        }
        if (sum > mxx << 1) ans++;
    }
    cout << ans;
    return 0;
}
