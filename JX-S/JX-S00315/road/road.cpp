#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, c, type;
} E[1000010];
bool cmp(Edge a, Edge b) {
    return a.c < b.c;
}
int n, m, k, c[20], a[11][10010];
int fa[10010];
void init() {
    for (int i = 1; i <= n + k; i++) {
        fa[i] = i;
    }
}
int find(int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = find(fa[x]);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].c);
    }
    sort(E + 1, E + m + 1, cmp);
    int nm = 0;
    init();
    for (int i = 1; i <= m; i++) {
        int fu = find(E[i].u), fv = find(E[i].v);
        if (fu != fv) {
            E[++nm] = E[i];
            fa[fu] = fv;
        }
    }
    m = nm;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            E[++m] = {n + i, j, a[i][j], i};
        }
    }
    sort(E + 1, E + m + 1, cmp);
    long long ans = 1e18;
    for (int i = 0; i < (1 << k); i++) {
        int cnt = 0;
        long long res = 0;
        for (int j = 1; j <= k; j++) {
            if ((i >> (j - 1)) & 1) {
                res += c[j];
            }
        }
        init();
        for (int j = 1; j <= m; j++) {
            if (E[j].type && !((i >> (E[j].type - 1)) & 1)) {
                continue;
            }
            int fu = find(E[j].u), fv = find(E[j].v);
            if (fu != fv) {
                res += E[j].c;
                fa[fu] = fv;
                ++cnt;
                if (cnt == n + __builtin_popcount(i) - 1) {
                    break;
                }
            }
        }
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}
