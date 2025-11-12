#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a[10005];
int ans;
void dfs(int p, int c, int mx, int sum) {
    if (p == n + 1) {
        if (c < 3 || sum <= 2 * mx) return;
        ans++;
        return;
    }
    dfs(p + 1, c, mx, sum);
    dfs(p + 1, c + 1, max(mx, a[p]), sum + a[p]);
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], mx = max(mx, a[i]);
    }
    dfs(1, 0, 0, 0);
    cout << ans << "\n";
    return 0;
}