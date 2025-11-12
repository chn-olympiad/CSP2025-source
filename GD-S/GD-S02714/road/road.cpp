#include <bits/stdc++.h>
using namespace std;

namespace IMC {
    typedef long long i64;
    constexpr int N = 1e4 + 20, M = 1e6 + 5, M2 = 1.5e5;
    int n, m, k;
    int fa[N];
    int a[13][N], c[13];
    i64 ans = 0;
    void init(int x) {
        for (;x;--x) fa[x] = x;
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    struct Edge {
        int u, v, w;
        bool operator<(const Edge &p) const {
            return w < p.w;
        }
    } e[M], e2[M2], e3[M2];
    void main() {
        cin >> n >> m >> k;
        init(n);
        for (int i = 1; i <= m; ++i) {
            int u, v, w; cin >> u >> v >> w;
            e[i] = {u, v, w};
        }
        sort(e+1,e+1+m);
        for (int i = 0; i < k; ++i) {
            cin >> c[i];
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        }
        i64 res = 0;
        int se = 0;
        for (int i = 1; i <= m; ++i) {
            int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
            if (u != v) {
                res += w;
                e2[++se] = {e[i].u, e[i].v, e[i].w};
                fa[v] = u;
            }
        }
        ans = res;
        for (int i = 1; i < (1 << k); ++i) {
            for (int j = 1; j <= se; ++j) e3[j] = e2[j]; //copy
            int tp = se;
            i64 res = 0;
            for (int j = 0; j < k; ++j)
                if ((i >> j) & 1) {
                    res += c[j];
                    for (int v = 1; v <= n; ++v)
                        e3[++tp] = {n+1+j, v, a[j][v]};
                }
            init(n + 11);
            sort(e3+1,e3+1+tp);
            for (int j = 1; j <= tp; ++j) {
                int u = find(e3[j].u), v = find(e3[j].v), w = e3[j].w;
                if (u != v) {
                    res += w;
                    fa[v] = u;
                }
            }
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    IMC::main();
    return 0;
}