#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, m, k;
struct node {
    int u;
    long long w;
};
vector<node> g[N];
int c[15];
int a[11][N];
priority_queue<pair<int, long long>> q;
long long dis[N];
bool vis[N];

long long dijk() {
    memset(dis, 0x3f, sizeof(dis));
    q.push(make_pair(1, 0));
    dis[1] = 0;
    while (!q.empty()) {
        pair<int, long long> u = q.top();
        q.pop();
        if (vis[u.first]) continue;
        vis[u.first] = true;
        for (int i = 0; i < g[u.first].size(); i++) {
            int v = g[u.first][i].u, w = g[u.first][i].w;
            if (vis[v]) continue;
            if (dis[u.first] + w < dis[v]) {
                dis[v] = dis[u.first] + w;
                q.push(make_pair(v, -dis[v]));
            }
        }
    }
    return dis[n];
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    bool flag = true;
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        if (c[i]) flag = false;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j]) flag = false;
        }
    }
    if (flag && k) {
        cout << 0;
        return 0;
    }
    cout << dijk();
  return 0;
}