#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 1e4 + 5;
const int MAXM = 15;
const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
    bool operator< (const Edge y) {
        return w < y.w;
    }
} e[MAXN];

int n, m, k, fa[MAXN], c[MAXM][MAXN], idx;

int find(int u) {
    if(fa[u] == u) {
        return u;
    }
    return fa[u] = find(fa[u]);
}

void adde(int u, int v, int w) {
    e[++idx] = {u, v, w};
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
    }
    for(int i = 1; i <= k; ++i) {
        for(int j = 0; j <= n; ++j) {
            cin >> c[i][j];
        }
    }
    sort(e + 1, e + idx + 1);
    LL ans = 0, cnt = 0;
    for(int i = 1; i <= idx; ++i) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(find(u) == find(v)) continue;
        fa[v] = u;
        ++cnt;
        ans += w;
        if(cnt >= n - 1) {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
