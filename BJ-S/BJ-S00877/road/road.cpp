#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    int to, w;
};
vector<node> mp[10005];
int c[15], a[15][10005], n, m, k;
ll ans = 2e9;
bool v[10005];
void dfs(int x, ll y, int z) {
    v[x] = 1;
    if (z == n) {
        ans = min(ans, y);
        return;
    }
    for (node i : mp[x]) {
        if (!v[i.to]) {
            dfs(i.to, y + i.w, z + 1);
        }
    }
    v[x] = 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int u, v, w; cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++) {
        bool flag = 1;
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) flag = 0;
        }
        if (flag && c[i] == 0) {
            cout << 0;
            return 0;
        }
    }
    dfs(1, 0, 1);
    cout << ans;
    return 0;
}
