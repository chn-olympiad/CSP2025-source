#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int e[maxn][maxn], dis[maxn], a[maxn][12];
bool vis[maxn];
int n, m, k;
int solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) dis[i] = e[1][i];
    vis[1] = true;
    for (int i = 2; i <= n; i++) {
        int min_dis = 0x3f3f3f3f, neo = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (min_dis > dis[i]) {
                min_dis = dis[i];
                neo = i;
            }
        }
        ans += min_dis;
        dis[neo] = 0;
        vis[neo] = true;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (dis[i] > e[neo][i]) {
                dis[i] = e[neo][i];
            }
        }
    }
    return ans;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(e, 0x3f, sizeof(e));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) e[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u][v] = e[v][u] = min(e[u][v], w);
    }
    for (int i = 1; i <= k; i++) {
        int c;
        scanf("%d", &c);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j][i]);
        }
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                e[j][k] = e[k][j] = min(e[j][k], a[j][i] + a[k][i]);
            }
        }
    }
    printf("%d", solve());
    return 0;
}
