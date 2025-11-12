#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5010], ans;
bool check(int m) {
    int maxn = -1;
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += a[i], maxn = max(maxn, a[i]);
    }
    return sum > 2 * maxn;
}
void dfs(int dep, int maxn, int sum, int cnt, bool vis) {
    if (vis == 1) {
        if (cnt >= 3 && (2 * maxn < sum) &&
            dep >= 1 && dep <= n) {
            ans++;
            ans %= mod;
            return;
        }
    }
    dfs(dep + 1, a[dep + 1], a[dep + 1] + sum, cnt + 1, ~vis);
    dfs(dep + 1, a[dep - 1], a[dep - 1] + sum, cnt + 1, vis);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] > 0) {
            flag = 0;
        }
    }
    sort(a + 1, a + n + 1);
    if (flag == 0) {
        dfs(1, -1, 0, 0, false);
    }
    cout << ans;
    return 0;
}
