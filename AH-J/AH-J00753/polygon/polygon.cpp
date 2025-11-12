#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N = 5000;
int n, ans, a[N + 5], s[N + 5];
void dfs(int x, int r, int sum) {
    if (x > r) {
        if (sum > 2 * s[r])
            ans ++;
        return;
    }
    for (int i = x; i <= n; i++) {
        s[i] = a[i];
        dfs(x + 1, r, sum + a[i]);
    }
}
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (n == 3) {
        int x = a[1], y = a[2], z = a[3];
        if (x + y + z > 2 * z)
            cout << 1;
        else
            cout << 0;
    }
    for (int i = 3; i <= n; i++) {
        dfs(1, i, 0);
    }
    cout << ans % mod;
    return 0;
}
