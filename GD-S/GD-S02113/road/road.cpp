#include <bits/stdc++.h>

using namespace std;

struct node {
    int u, v, w;
    bool operator<(const node &x) const {
        return w < x.w;
    }
};

const int N = 10010;
int n, m, k;
priority_queue<node> G;
int c[20], a[20][N];
long long ret = 0x3f3f3f3f3f3f3f3f;
bool vis[N];

long long kruskal(priority_queue<node> g) {
    memset(vis, 0, sizeof(vis));
    long long dis = 0;
    while (!g.empty()) {
        node f = g.top();
        g.pop();
        if (vis[f.u] && vis[f.v]) continue;
        vis[f.u] = vis[f.v] = 1;
        dis += f.w;
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) break;
    }
    return dis;
}

void dfs(int now, long long cst, priority_queue<node> g) {
    if (now > k) {
        ret = min(ret, cst + kruskal(g));
        return;
    }
    dfs(now + 1, cst, g);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            g.push({i, j, a[now][i + 1] + a[now][j + 1]});
        }
    }
    dfs(now + 1, cst + c[now], g);
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.push({u, v, w});
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, 0, G);
    cout << ret;
	return 0;
}
