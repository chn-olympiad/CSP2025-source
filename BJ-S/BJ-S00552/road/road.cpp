#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e4+5, M = 2e6+5;
struct Edge {
    ll u, v, w;
    bool operator<(const Edge& b) const {
        return w < b.w;
    }
} e[M];
ll a[20][N];
int n, m, k;

int fa[N];
int find(int u) {
    return (fa[u] == u ? u : fa[u] = find(fa[u]));
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= k; i++) {
        int c, u = 0;
        cin >> c;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                u = j;
        }
        for (int j = 1; j <= n; j++)
            if (j != u)
                e[++m] = {u, j, a[i][j]};
    }
    iota(fa+1, fa+1+n, 1);
    sort(e+1, e+1+m);
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt == n-1) break;
        ll u = find(e[i].u), v = find(e[i].v), w = e[i].w;
        if (u != v) {
            fa[u] = v;
            cnt++;
            ans += w;
        }
    }
    cout << ans << endl;
    return 0;
}