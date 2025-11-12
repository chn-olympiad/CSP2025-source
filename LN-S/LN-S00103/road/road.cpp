#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
};
int e[1000006];
int cost[15][10005];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }
    int sum  = 0;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n + 1; j++) {
            cin >> cost[k][j];
            sum += cost[k][j];
        }
    }
    cout << sum;

    return 0;
}
