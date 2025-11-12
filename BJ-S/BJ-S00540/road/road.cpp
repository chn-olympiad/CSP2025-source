#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
int n, m, k, ans = 0x3f3f3f3f;
int u, v, w, c[N];
bool st[N];
struct node{
    int to, val;
};
vector<node> g[N];
void dfs(int u, int res, int cnt) {
    if (cnt >= n) {
        ans = min(ans, res);
    }
    for (const auto &it : g[u]) {
        if (!st[it.to]) {
            st[it.to] = true;
            dfs(it.to, res + it.val, cnt + 1);
        }
    }
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    st[1] = true;
    dfs(1, 0, 1);
    cout << ans << '\n';
    return 0;
}