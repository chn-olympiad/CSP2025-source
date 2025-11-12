#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const int M = 1000005;

int n, m, k, vis[M], dis[M], over[M], c[M], ans;

struct edge {
    int v, w;
};

bool operator<(const edge a, const edge b) {
    return a.w > b.w;
}


priority_queue<edge> q;
vector<edge> e[N];

int dijkstra(int s) {
    while(!q.empty()) q.pop();
    for (int i = 1; i <= 1000000; i++) {
        vis[i] = 0;
        dis[i] = 0x3f3f3f3f;
    }
    dis[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].v;
            int w = e[u][i].w;
            if (dis[v] >= dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (int j = m+1; j <= m+k; j++) {
        cin >> c[j-m];

        for (int i = 1; i <= m; i++) {
            int cost;
            cin >> cost;
            e[j].push_back({i, cost});
            e[i].push_back({j, cost});
        }
    }
    int extra = 0;
    int minn = 0x3f3f3f3f, minpos = 1;
    for (int i = 1; i < n; i++) {
        dijkstra(minpos);
        for (int i = 1; i <= k; i++) {
            extra = c[1];
        }
        over[minpos] = 1;
        minn = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++) {
            if (dis[j] < minn && dis[j] != 0 && over[j] == 0) {
                minpos = j;
                minn = dis[j];
            }
        }
        ans += minn;
    }
    cout << ans + extra;
    return 0;
}
