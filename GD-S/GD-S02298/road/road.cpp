#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10, N = 1e4 + 10;

int n, m, k;
int c[15], a[15][N];

struct edge {
    int u, v, w;
    bool operator<(const edge &x) const {
        return w < x.w;
    }
} E[M], P[N * 15];

struct dsu {
    int fa[N * 2];

    void clear() {
        memset(fa, -1, sizeof(fa));
    }

    int get(int x) {
        if(fa[x] < 0) return x;
        return fa[x] = get(fa[x]);
    }

    void merge(int x, int y) {
        x = get(x), y = get(y);

        if(fa[x] < fa[y]) fa[x] += fa[y], fa[y] = x;
        else fa[y] += fa[x], fa[x] = y;
    }
} d;

bool flag[15];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }

    sort(E + 1, E + m + 1);

    d.clear();
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        auto [u, v, w] = E[i];

        if(d.get(u) == d.get(v)) continue;

        P[++cnt] = {u, v, w}; 
        d.merge(u, v);
    }

    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];

            P[++cnt] = {j, n + i, a[i][j]};
        }
    }

    sort(P + 1, P + cnt + 1);

    long long ans = 2e18;
    for(int S = 0; S < (1 << k); S++) {
        long long tot = 0;

        memset(flag, 0, sizeof(flag));
        for(int i = 1; i <= k; i++) {
            if((S >> (i - 1)) & 1) {
                flag[i] = 1;
                tot += c[i];
            }
        }
        d.clear();
        
        for(int i = 1; i <= cnt; i++) {
            auto &[u, v, w] = P[i];
            if((v > n && !flag[v - n]) || d.get(u) == d.get(v)) continue;
            d.merge(u, v);

            tot += w;
        }

        ans = min(ans, tot);
    }

    cout << ans << '\n';
} 