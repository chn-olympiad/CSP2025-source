#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, c[510], ans;
string s;
bool vis[510];
void dfs(int cnt, int nm, int now) {
    vis[now] = 1;
    if (s[nm] == '1' && nm - cnt - 1 < c[now]) {
        cnt++;
    }
    if (nm == n) {
        if (cnt >= m) {
            ans++;
            ans %= mod;
        }
        vis[now] = 0;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        dfs(cnt, nm + 1, i);
    }
    vis[now] = 0;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        dfs(0, 1, i);
    }
    cout << ans;
    return 0;
}
