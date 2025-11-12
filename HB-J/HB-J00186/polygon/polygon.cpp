#include <bits/stdc++.h>
using namespace std;
int n, a[1000100], sum;
vector<int> tw;
int dfs(int x, int t, int k) {
    if (x > k) {
        int maxx = 0;
        for (int i = 1; i <= k; i++) {
            maxx = max(maxx, tw[i]);
        }
        if (sum > 2 * maxx) {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for (int i = t; i <= n; i++) {
        sum += a[i];
        tw[x] = a[i];
        ans += dfs(x + 1, i + 1, k);
        sum -= a[i];
        tw[x] = 0;
    }
    return ans;
}
int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    cin >> n;
    tw.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int k = 3; k <= n; k++) {
        ans += dfs(1, 1, k);
    }
    cout << ans;
    return 0;
}
