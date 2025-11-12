#include <bits/stdc++.h>
using namespace std;
const int F = 998244353;
int n, t, ans, k;
int a[5005];
int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {

        cin >> a[i];
        if (a[i] == 1) t++;
        k += a[i];
    }
    sort (a+1, a+n+1);
    if (n == 3)
    {
        if (a[1] + a[2] > a[3]) cout << 1;
        else if (a[1] + a[2] <= a[3]) cout << 0;
        return 0;
    }
    if (t == n) {
        cout << (n - 2) % F;
        return 0;
    }
    if (n == 4) {
        if (a[1] + a[2] > a[3]) ans++;
        if (a[1] + a[3] > a[4]) ans++;
        if (a[2] + a[3] > a[4]) ans++;
        if (k > 2 * a[4]) ans++;
    }
    if (n == 5) {
        if (a[1] + a[2] > a[3]) ans++;
        if (a[1] + a[2] > a[4]) ans++;
        if (a[1] + a[2] > a[5]) ans++;
        if (a[1] + a[3] > a[4]) ans++;
        if (a[1] + a[3] > a[5]) ans++;
        if (a[1] + a[4] > a[5]) ans++;
        if (a[2] + a[3] > a[4]) ans++;
        if (a[2] + a[3] > a[5]) ans++;
        if (a[2] + a[4] > a[5]) ans++;
        if (a[3] + a[4] > a[5]) ans++;
        if ((k - a[1]) > a[5] * 2) ans++;
        if ((k - a[2]) > a[5] * 2) ans++;
        if ((k - a[3]) > a[5] * 2) ans++;
        if ((k - a[4]) > a[5] * 2) ans++;
        if ((k - a[5]) > a[4] * 2) ans++;
        if (k > a[5] * 2) ans++;
    }
    cout << ans % F;
    return 0;
}
