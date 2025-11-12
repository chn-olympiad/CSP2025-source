#include <bits/stdc++.h>

using namespace std;
int n, m, k;
int u, v, w;
int c;
int a[10005];

vector<pair<int,int>> adj[10005];
int vis[10005];
long long ans;
queue<pair<int,int>> q;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &c);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
    }

    q.push({0, 1});
    vis[1] = 1;
    while (!q.empty()) {
        pair<int,int> cur = q.front();
        ans += cur.first;
        q.pop();

        for (auto id : adj[cur.second]) {
            if (vis[id.second]) continue;
            q.push({id.first, id.second});
            vis[id.second] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
