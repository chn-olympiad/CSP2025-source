#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 15;
int a[N], b[N], c[N], n, ans = 0;
void dfs (int x, int y, int z, int sum, int dep) {
    if (dep == n + 1) {
        ans = max (ans, sum);
    }
    if (x + 1 <= n / 2) {
        dfs (x + 1, y, z, sum + a[dep], dep + 1);
    }
    if (y + 1 <= n / 2) {
        dfs (x, y + 1, z, sum + b[dep], dep + 1);
    }
    if (z + 1 <= n / 2) {
        dfs (x, y, z + 1, sum + c[dep], dep + 1);
    }
}
int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n ;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        dfs (0, 0, 0, 0, 1);
        cout << ans << "\n" ;
        ans = 0;
    }
    return 0;
}
