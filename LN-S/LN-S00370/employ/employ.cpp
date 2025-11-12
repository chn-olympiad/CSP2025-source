#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
char qq[999];
long long n, m, ans = 1, a[560], ling;
int main () {
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> qq[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            ling++;
        }
    }
    n -= ling;
    for (int i = 1; i <= n; i++) {
        ans = (ans * (i % mo)) % mo;
    }
    if (n < m)cout << 0;
    else cout << ans % mo;
    return 0;
}
