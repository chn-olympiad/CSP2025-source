#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#define int long long
using namespace std;
const int maxn = 1e4+100, maxm = 1e6+100;
int ans = 1e17;
int n, m, k;
int c[15], a[15][maxn];
vector<pair<int, int>> r[maxn];
signed main() {
    freopen("road2.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        r[u].push_back(make_pair(v, w));
        r[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < 1<<k; i++) {
        int now = i, s[15], cnt = 0;
        int res = 0;
        for (int j = k; j > 0; j--) {
            if (now & 1) {
                cnt++;
                s[cnt] = j;
                res+=c[j];
            }
            now>>=1;
        }
        vector<pair<int, int>> rr[maxn];
        for (int u = 1; u <= n; u++) {
            for (auto p : r[u]) {
                int v = p.first, w = p.second;
                rr[u].push_back(make_pair(v, w));
            }
        }
        for (int j = 1; j <= cnt; j++) {
            for (int v = 1; v <= n; v++) {
                rr[n+s[j]].push_back(make_pair(v, a[s[j]][v]));
                rr[v].push_back(make_pair(n+s[j], a[s[j]][v]));
            }
        }
        int vis[maxn+100];
        memset(vis, 0, sizeof(vis));
        priority_queue<pair<int, int>> q;
        q.push(make_pair(0, 1));
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int u = p.second;
            if (vis[u]) continue;
            res-=p.first;
            vis[u] = 1;
            for (auto p : rr[u]) {
                int v = p.first, w = p.second;
                if (!vis[v])
                    q.push(make_pair(-w, v));
            }
        }
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
