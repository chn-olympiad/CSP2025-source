#include <bits/stdc++.h>

using namespace std;

const int N = 1.5e4 + 10, M = 1.2e6 + 10;

int n, m, k;

struct DSU {
    int f[N];
    void init(int n)  {
        for (int i = 1; i <= n; i++) f[i] = i;
    }

    int findfa(int x) {
        if (f[x] == x) return x;
        return f[x] = findfa(f[x]);
    }

    void unionfa(int x, int y) {
        x = findfa(x); y = findfa(y);
        if (x != y) f[x] = y;
    }
};

DSU d;

struct edge {
    int u, v, w;
};
edge e[M], e2[M], ee[11][N];
int sp[N];
int now[N];
int cnt = 0;

inline bool U(edge x) {
    // cout << x.u << ' ' << x.v << ' ' << (d.findfa(x.u) != d.findfa(x.v)) << '\n';
    if (d.findfa(x.u) != d.findfa(x.v)) {
        d.f[d.f[x.u]] = d.f[x.v];
        return 1;
    }
    return 0;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    
    for (int i = 1; i <= k; i++) {
        cin >> sp[i];
        for (int j = 1; j <= n; j++) {
            ee[i][j].u = i+n;
            ee[i][j].v = j;
            cin >> ee[i][j].w;
        }
        sort(ee[i] + 1, ee[i] + n + 1, [](edge x, edge y) {
            return x.w < y.w;
        });
    }
    sort(e + 1, e + m + 1, [](edge x, edge y) {
        return x.w < y.w;
    });
    d.init(n+k);
    long long s = 0;
    for (int i = 1; i <= m; i++) {
        if (d.findfa(e[i].u) != d.findfa(e[i].v)) {
            s += e[i].w;
            d.unionfa(e[i].u, e[i].v);
            e2[++cnt] = e[i];
        }
    }
    // cout << s << ' ' << cnt << '\n';
    long long ans = s;
    for (int S = 1; S < (1 << k); S++) {
        long long t = 0;
        for (int i = 1; i <= k; i++) now[i] = 1;
        for (int i = 1; i <= k; i++) if ((S >> (i - 1)) & 1) t += sp[i];
        d.init(n + k);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                while (((S >> (j - 1)) & 1) && now[j] <= n && ee[j][now[j]].w <= e2[i].w) {
                    if (U(ee[j][now[j]])) 
                        t += ee[j][now[j]].w;
                    ++now[j];
                }
            }
            if (U(e2[i])) t += e2[i].w;
        }
        // cerr << S <<  ' ' << t << '\n';
        ans = min(ans, t);
    }
    cout << ans;

    return 0;
}