#include <bits/stdc++.h>
using namespace std;
int n, k, ans, t, x;
int a[500005];
int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) t++;
            if (a[i] == 0) x++;
    }
    if (t == n) {
        if (k == 0) ans = t / 2;
        else if (k == 1) ans = t;
        else ans = 0;
    }
    else if (x + t == n) {
        if (k == 0) {
            for (int i = 1; i < n; i++)
                if (a[i] == 0 || a[i] == 1 && a[i-1] == 1) ans++;
            if (a[n] == 0) ans++;
        }
        else if (k == 1) ans = t;
    }
    cout << ans;
    return 0;
}
