#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e4 + 5, M = 2e6 + 5, K = 15;
const LL INF = 2e18;

int n, m, k;
LL c[K], a[K][N];

struct Edge {
    int u, v;
    LL w;
} E[M];

struct DSU {
    int fa[N + K], siz[N + K];

    void init(int _n) {
        for (int i = 1; i <= _n; i++) {
            fa[i] = i;
            siz[i] = 1;
        }
    }

    int find(int x) {
        return (fa[x] == x ? x : fa[x] = find(fa[x]));
    }

    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return 0;
        if (siz[fx] > siz[fy]) swap(fx, fy);
        fa[fx] = fy;
        siz[fy] += siz[fx];
        return 1;
    }
} D;

namespace Code1 {
    Edge E2[M];

    LL work(int s) {
        LL res = 0;
        for (int i = 1; i <= m; i++) {
            E2[i] = E[i];
        }
        int idx = m;
        for (int i = 1; i <= k; i++) {
            if ((s >> i - 1) & 1) {
                res += c[i];
                for (int j = 1; j <= n; j++) {
                    E2[++idx] = {n + i, j, a[i][j]};
                }
            }
        }
        sort(E2 + 1, E2 + 1 + idx, [&](auto i, auto j) {
            return i.w < j.w;
        });
        D.init(n + k);
        for (int i = 1; i <= idx; i++) {
            auto [u, v, w] = E2[i];
            if (!D.merge(u, v)) continue;
            res += w;
        }
        return res;
    }

    void solve() {
        LL ans = INF;
        for (int i = 0; i < (1 << k); i++) {
            ans = min(ans, work(i));
        }
        printf("%lld\n", ans);
    }
}

namespace Code2 { // A
    void solve() {
        int idx = m;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == 0) {
                    for (int t = 1; t <= n; t++) {
                        if (t == j) continue;
                        E[++idx] = {j, t, a[i][t]};
                    }
                }
            }
        }
        LL res = 0;
        sort(E + 1, E + 1 + idx, [&](auto i, auto j) {
            return i.w < j.w;
        });
        D.init(n);
        for (int i = 1; i <= idx; i++) {
            auto [u, v, w] = E[i];
            if (!D.merge(u, v)) continue;
            res += w;
        }
        printf("%lld\n", res);
    }
}

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        E[i] = {u, v, w};
    }
    int maxc = 0, mina, cnt = 0;
    for (int i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
        maxc = max(maxc, (int)c[i]);
        mina = 1;
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]);
            mina = min(mina, (int)a[i][j]);
        }
        cnt += !mina;
    }

    if (maxc == 0 && cnt == k) {
        Code2::solve();
        return;
    }

    Code1::solve();
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    solve();
    return 0;
}