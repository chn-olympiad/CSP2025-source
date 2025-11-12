#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, t[11], dist[10015], d[11][10015], dp[11];
vector<pair<int, int>> g[10015];
bool vis[10015];

priority_queue<pair<int, int>> pq;

int solve(){
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    pq.push({0, 1});
    int ans = 0;
    while (!pq.empty()){
        int p = pq.top().second, d = pq.top().first;
        pq.pop();
        if (vis[p])
            continue;
        vis[p] = true;
        ans -= d;
        for (auto x: g[p]){
            if (x.second < dist[x.first]){
                dist[x.first] = x.second;
                pq.push({-x.second, x.first});
            }
        }
    }
    return ans;
}

int dfs(int p, int s){
    int ans = solve() + s;
    if (p == k)
        return ans;
    if (m >= 100000)
        for (int i = 1; i <= p; i++)
            if (ans > dp[i])
                return ans;
    dp[p] = ans;
    for (int i = p + 1; i <= k; i++){
        for (int j = 1; j <= n; j++)
            g[j].push_back({n + i, d[i][j]});
        ans = min(ans, dfs(i, s + t[i]));
        for (int j = 1; j <= n; j++)
            g[j].pop_back();
    }
    return ans;
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    bool flag = true;
    for (int i = 1; i <= k; i++){
        cin >> t[i];
        if (t[i])
            flag = false;
        for (int j = 1; j <= n; j++)
            cin >> d[i][j], g[n + i].push_back({j, d[i][j]});
    }
    memset(dp, 0x3f, sizeof dp);
    if (flag || k == 0){
        for (int i = 1; i <= k; i++){
            for (int j = 1; j <= n; j++){
                g[j].push_back({n + i, d[i][j]});
                g[n + i].push_back({j, d[i][j]});
            }
        }
        cout << solve();
    }
    else
        cout << dfs(0, 0);
    return 0;
}
