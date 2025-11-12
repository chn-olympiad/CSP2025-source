#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

const int N = 2e4 + 5, M = 2e6 + 5, K = 15;

struct EDGE {
    int u, v, w;

    bool operator < (const EDGE &b) const {
        return w < b.w;
    }
};

int n, m, k, c[N], a[K][N], fa[N];
EDGE g[M], gg[M];

int fnd(int x) {
    if(fa[x] == x) {
        return x;
    }
    return fa[x] = fnd(fa[x]);
}

LL kruskal(int cntNode, int cntEdge, bool type) {
    LL res = 0, cnt = 0;

    for(int i = 1; i <= cntNode; i++) {
        fa[i] = i;
    }

    sort(g + 1, g + cntEdge + 1);

    for(int i = 1; i <= cntEdge; i++) {
        int u = g[i].u, v = g[i].v, w = g[i].w;

        if(fnd(u) == fnd(v)) {
            continue;
        }

        fa[fnd(u)] = fnd(v);
        if(type) {
            gg[++cnt] = g[i];
        }
        res += w;

        if(cnt == cntNode - 1) {
            break;
        }
    }

    return res;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    LL ans = kruskal(n, m, 1);

    for(int s = 1; s < (1 << k); s++) {
        for(int i = 1; i < n; i++) {
            g[i] = gg[i];
        }

        LL res = 0;
        int cntNode = n, cntEdge = n - 1;

        for(int i = 1; i <= k; i++) {
            if((s >> (i - 1)) & 1) {
                res += c[i];
                cntNode++;
                for(int j = 1; j <= n; j++) {
                    g[++cntEdge] = EDGE{cntNode, j, a[i][j]};
                }
            }
        }

        if(res >= ans) {
            continue;
        }

        res += kruskal(cntNode, cntEdge, 0);

        ans = min(ans, res);
    }

    cout << ans << '\n';
}