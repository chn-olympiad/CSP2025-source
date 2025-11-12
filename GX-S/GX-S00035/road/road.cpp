#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, f[N], c[15], a[15][N];
struct edge {
    int u, v, w;
    bool operator < (const edge &oth) const {
        return w < oth.w;
    }
} e[M];
int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
void join(int u, int v) {
    int fu = find(u), fv = find(v);
    f[fu] = fv;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    int flag = 1;
    for (int i = 1; i <= k; i++) {
        cin >> c[k];
        flag &= !c[k];
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
//    if (k <= 0) {
        long long ans = 0;
        sort(e + 1, e + m + 1);
        for (int i = 1; i <= m; i++) {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if (find(u) != find(v)) {
                join(u, v);
                ans += w;
            }
        }
        cout << ans;

        return 0;
//    }
    return 0;
}
