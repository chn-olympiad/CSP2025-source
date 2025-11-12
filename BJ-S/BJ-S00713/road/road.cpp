#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 20;
#define int long long
int n, m, k, ans = 0;
bool vis[N];
struct road {
    int to, dist;
};
int d[N], b[20];
vector<road> g[N];
int go(int x, int c, int fa) {
    if(vis[x] == true) return c;
    int minn = 1e18;
    int pos = 0;
    for(auto t : g[x]) {
        if(t.to == fa) continue;
        int p = go(t.to, t.dist + c, x);
        if(minn > p) {
            minn = p;
            pos = t.to;
        }
    }
    vis[pos] = true;
    return minn;
}
void bfs() {
    queue<int> q;
    q.push(1);
    d[1] = 0;
    vis[1] = true;
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        for(auto x : g[f]) {
            if(d[x.to] > d[f] + x.dist) {
                d[x.to] = d[f] + x.dist;
                if(x.to > n) d[x.to] += b[x.to - n];
                vis[x.to] = true;
                q.push(x.to);
            }
        }
    }
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    memset(d, 0x3f3f3f3f, sizeof(d));
    for(int i = 1; i <= k; i++) {
        cin >> b[i];
        for(int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            g[i + n].push_back({j, w});
            g[j].push_back({i + n, w});
        }
    }
    memset(vis, false, sizeof(vis));
    bfs();
    for(int i = 1; i <= n + k; i++) {
        if(i <= n && vis[i] == false) {
            int num = go(i, 0, -1);
            ans += num;
            vis[i] = true;
        } else if(i > n && vis[i] == true) ans += b[i - n];

    }
    cout << d[n] + ans;
    return 0;
}
