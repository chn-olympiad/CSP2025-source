#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 1;
const int M = 1e6 + 1;
const int K = 11;

int c[K], a[K][N], cost[N][N];
bool vis[N];
int ans = 1e9;

struct Node {
    int e, x;
};

vector<Node> g[N];

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    memset(cost, 0x3f, sizeof cost);
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(Node{v, w});
        g[v].push_back(Node{w, v});
        cost[u][v] = cost[v][u] = w;
        sum += w;
    }
    for (int j = 1; j <= k; ++j) {
        cin >> c[j];
        for (int i = 1; i <= n; ++i) {
            cin >> a[j][i];
        }
    }
    if (k == 0) {
        cout << sum << endl;
        return 0;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) { //以i为交点
        int sum = 0;
        for (int j = 1; j <= n; ++j) { //从j到i
            int minn = cost[i][j]; 
            for (int l = 1; l <= k; ++l)
                minn = min(minn, a[l][i] + a[l][j]);
            sum += minn;
        }
        ans = min(ans, sum);    
    }
    cout << ans << endl;
    return 0;
}