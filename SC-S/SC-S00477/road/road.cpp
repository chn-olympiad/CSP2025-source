#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e4 + 5, M = 2e6 + 5, inf = 1e18;

struct Node {
    int u, v, w;
    bool operator < (const Node &rhs) const {
        return  w < rhs.w;
    }
} e[M];

int c[N];

int fa[N];

int find(int x) { return (x == fa[x] ? x : fa[x] = find(fa[x])); }

int used[N];

int Kru(int n, int m) {
    int res = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1, fx, fy; i <= m; i++) {
        if (!used[e[i].u] || !used[e[i].v]) continue;
        // printf("%lld %lld %lld %lld %lld\n", e[i].u, used[e[i].u], e[i].v, used[e[i].v], e[i].w);
        fx = find(e[i].u), fy = find(e[i].v);
        if (fx != fy) {
            res += e[i].w;
            fa[fx] = fy;
        }
    }
    return res;
}

int n, m, k;

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%lld%lld%lld", &n, &m, &k);

    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j++) {
            m++;
            scanf("%lld", &e[m].w);
            e[m].u = i + n, e[m].v = j;
        }
    }
    
    sort(e + 1, e + m + 1);

    for (int i = 1; i <= n; i++) used[i] = 1;

    int ans = inf;

    for (int S = 0; S < (1 << k); S++) {
        int res = 0;
        for (int i = 0; i < k; i++) {
            used[n + i + 1] = S >> i & 1;
            if (S >> i & 1) res += c[i + 1];
        }
        res += Kru(n + k, m);
        // printf("%lld\n", res);
        ans = min(ans, res);
    } 

    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
