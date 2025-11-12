#include <bits/stdc++.h>
using namespace std;
const int N = 5010, mod = 998244353;
int n;
int a[N], ans;
bool hefa (long long x) {
    int sum = 0, maxx = 0;
    for (long long i = n - 1; i >= 0; i--) {
        if (x >= pow (2, i)) {
            x -= pow (2, i);
            sum += a[i + 1];
            maxx = max (maxx, a[i + 1]);
        }
    }
    return (sum > (maxx * 2));
}
void solve () {
    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans = (ans + 1) % mod;
        }
    }
    cout << ans << "\n";
}
int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    cin >> n;
    bool f = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) f = false;
    }
    if (f) {
        solve ();
        return 0;
    }
    for (long long i = pow (2, 3) - 1; i <= pow (2, n) - 1; i++) {
        ans = (hefa (i) + ans) % mod;
        // if (hefa (i)) cout << i << "\n";
    }
    cout << ans << "\n";
    return 0;
}

