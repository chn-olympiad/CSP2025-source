#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
struct node {
    int u, v, w;
    bool operator < (const node &x) const {
        return w < x.w;
    }
} e[N*100], e2[11][N], p[N*20], tmp[N*20];
int sz[N+10], pa[N+10], c[N];

int get_fa(int x) {
    return pa[x] == x ? x : pa[x] = get_fa(pa[x]);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) cin >> e2[i][j].w, e2[i][j].u = n+i, e2[i][j].v = j;
        sort(e2[i]+1, e2[i]+n+1);
    }
    sort(e+1, e+m+1);
    int cnt = 0;
    for (int i = 1; i <= n+k; i++) pa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) {
        int u = get_fa(e[i].u);
        int v = get_fa(e[i].v);
        if (u != v) {
            if (sz[u] < sz[v]) pa[u] = pa[v], sz[v] = max(sz[v], sz[u]+1);
            else pa[v] = pa[u], sz[u] = max(sz[u], sz[v]+1);
            e[++cnt] = e[i];
        }
    }
    long long ans = 1e18;
    for (int s = 0; s < (1 << k); s++) {
        int m = n-1;
        long long res = 0;
        for (int i = 1; i <= m; i++) p[i] = e[i];
        for (int i = 1; i <= k; i++) if (s & (1 << (i-1))) {
            res += c[i];
            for (int j = 1; j <= m; j++) tmp[j] = p[j];
            int cnt = 0, t = 1;
            for (int j = 1; j <= m; j++) {
                while (t <= n && e2[i][t].w <= tmp[j].w) p[++cnt] = e2[i][t], ++t;
                p[++cnt] = tmp[j];
            }
            while (t <= n) p[++cnt] = e2[i][t], ++t;
            m += n;
        }
        for (int i = 1; i <= n+k; i++) pa[i] = i, sz[i] = 1;
        for (int i = 1; i <= m; i++) {
            int u = get_fa(p[i].u);
            int v = get_fa(p[i].v);
            if (u != v) {
                if (sz[u] < sz[v]) pa[u] = pa[v], sz[v] = max(sz[v], sz[u]+1);
                else pa[v] = pa[u], sz[u] = max(sz[u], sz[v]+1);
                res += p[i].w;
            }
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
    return 0;
}