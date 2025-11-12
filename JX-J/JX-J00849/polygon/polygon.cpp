#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, a[5005], ans;
bool cmp(int x, int y) {
    return x > y;
}
void dfs(int mi, int cnt, int m) {
    cnt += a[m];
    if (cnt >= mi) {
        ans++;
        ans %= mod;
    }
    if (m == n) {
        return;
    }
    for (int i = m + 1; i <= n; i++) {
        dfs(mi, cnt, i);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
            dfs(a[i] + 1, 0, j);
        }
    }
    cout << ans;
    return 0;
}
