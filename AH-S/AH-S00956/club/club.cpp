#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
ll n, fa[N], fb[N], fc[N], ans;
void dfs(int i, int ap,int bp, int cp, ll z) {
    if (i == n + 1) {
        if (z > ans) ans = z;
    }
    if (ap < n / 2) dfs(i + 1, ap + 1, bp, cp, z + fa[i]);
    if (bp < n / 2) dfs(i + 1, ap, bp + 1, cp, z + fb[i]);
    if (cp < n / 2) dfs(i + 1, ap, bp, cp + 1, z + fc[i]);
}
int main() {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ans = INT_MIN;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf ("%d %d %d", &fa[i], &fb[i], &fc[i]);
        }
        dfs(1, 0, 0, 0, 0);
        cout << ans;
    }
    return 0;
}
