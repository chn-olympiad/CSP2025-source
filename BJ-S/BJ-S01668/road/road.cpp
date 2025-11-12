#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

const int N = 1e4 + 15;
int n, m, k, cnt;
ll ans;
bool vis[N];
struct No
{
    int v, w;
};
struct Node
{
    vector<No> e;
    int c;
} g[N];

void dfs(int u, ll lim)
{
    if (vis[u]) return;
    vis[u]=1;
    if (u <= n) cnt++;
    else if (g[u].c <= lim) lim -= g[u].c;
    else return;
    for (int i = 0; i < g[u].e.size(); i++)
    {
        No p = g[u].e[i];
        if (p.w <= lim) dfs(p.v, lim - p.w);
        if (cnt >= n) return;
    }
    vis[u]=0;
    if (u <= n) cnt--;
}

bool check(ll lim)
{
    for (int i = 1; i <= n + k; i++)
    {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        dfs(1, lim);
        if (cnt >= n) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) g[i].c = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].e.push_back({v, w});
        g[v].e.push_back({u, w});
    }
    for (int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        g[n + i].c = c;
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            g[n + i].e.push_back({j, x});
            g[j].e.push_back({n + i, x});
        }
    }
    ll l = 0, r = 1e18;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
