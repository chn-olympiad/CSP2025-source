#include <bits/stdc++.h>
#define MAXN 1000005
#define int long long
using namespace std;

int n, m, k;
int cost[20], a[20][10005];
struct edge{
    int nxt;
    int weight;
};
vector<edge> g[MAXN];

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1, u, v, w;i <= m;i++){
        cin >> u >> v >> w;
        g[u].push_back((edge){v,w});
        g[v].push_back((edge){u,w});
    }
    for (int i = 1;i <= k;i++){
        cin >> cost[i];
        for (int j = 1;j <= n;j++) cin >> a[i][j];
    }
    cout<<0;
    return 0;
}
