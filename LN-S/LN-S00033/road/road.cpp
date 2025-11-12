#include<bits/stdc++.h>
using namespace std;
//k = 0最小生成树
int n, m, k;
const int maxn = 1e4 + 10;
struct road {
    int v, w;
};
struct line {
    int u, v, w;
    bool operator < (const line &a) const {
        return w > a.w;
    }
};
vector<road> a[maxn];
int c[maxn][maxn];
priority_queue<line> q;
bool vis[maxn] = {false};
int find() {
    int ans = 0, cnt = 0;
    while(!q.empty()) {
        line now = q.top();
        q.pop();
        int u = now.u, v = now.v, w = now.w;
        if(vis[u] && vis[v])
            continue;
        if(!vis[u])
            vis[u] = true, cnt++;
        if(!vis[v])
            vis[v] = true, cnt++;
        ans += w;
        if(cnt == n)
            return ans;
    }
    return ans;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        q.push({u, v, w});
    }
    for(int i = 1; i <= k; i++)
        for(int j = 0; j <= n + 1; j++)
            cin >> c[i][j];
    if(k == 0)
        cout << find();
    return 0;
}
