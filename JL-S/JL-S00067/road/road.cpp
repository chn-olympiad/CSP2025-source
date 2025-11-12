#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[20], a[20][10010], fa[10010], num, ans;

int findset(int i) {
    if (fa[i] == i)
        return i;
    return fa[i] = findset(fa[i]);
}

struct EDGE {
    int u, v, w;
    bool operator < (const EDGE &lll) const {
        return w < lll.w;
    }
} edge[1000010];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    num = n;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m; i++) {
        int uu = edge[i].u, vv = edge[i].v, ww = edge[i].w;
        if (findset(uu) == findset(vv))
            continue;
        fa[uu] = vv;
        ans += ww;
        num--;
        if (num == 1)
            break;
    }
    printf("%d\n", ans);
    return 0;
}
