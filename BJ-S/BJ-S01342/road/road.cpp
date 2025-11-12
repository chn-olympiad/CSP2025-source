#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 10001;
const int M = 1000001;
const int K = 11;

struct edge
{
    int x, val;
};
vector<edge> e[N];
int cost[K], newe[K][N], dist[N];
bool vis[N];
int n, m, k;
ifstream fin;
ofstream fout;

struct city
{
    int id;
    bool const operator< (city a)const&
    {
        return dist[id] > dist[a.id];
    }
};

int solve(int u, int v, int bd)
{
    int ans = 2147483647;
    for (int i = 1; i <= k; i++)
    {
        if (((bd >> (i - 1)) & 1) == 0) continue;
        ans = min(ans, newe[i][u] + newe[i][v]);
    }
    return ans;
}

int main()
{
    fin.open("road.in");
    fout.open("road.out");
    fin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++)
    {
        fin >> cost[i];
        for (int j = 1; j <= n; j++)
        {
            fin >> newe[i][j];
        }
    }

    long long ans = 0;
    memset(dist, 0x3f, sizeof(dist));
    vis[1] = true;
    priority_queue<city> _q;
    for (int i = 0; i < e[1].size(); i++)
    {
        int v = e[1][i].x;
        dist[v] = e[1][i].val;
        _q.push({v});
        vis[v] = true;
    }
    while (!_q.empty())
    {
        int u = _q.top().id;
        _q.pop();
        vis[u] = true;
        ans += dist[u];
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].x;
            dist[v] = min(dist[v], e[u][i].val);
            if (!vis[v])
            {
                _q.push({v});
                vis[v] = true;
            }
        }
    }

    for (int bd = 1; bd < (1 << k); bd++)
    {
        long long _ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(dist, 0x3f, sizeof(dist));
        vis[1] = true;
        priority_queue<city> q;
        for (int i = 2; i <= n; i++)
        {
            dist[i] = solve(1, i, bd);
            q.push({i});
        }
        for (int i = 0; i < e[1].size(); i++)
        {
            int v = e[1][i].x;
            dist[v] = min(dist[v], e[1][i].val);
        }
        while (!q.empty())
        {
            int u = q.top().id;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            _ans += dist[u];
            for (int i = 0; i < e[u].size(); i++)
            {
                int v = e[u][i].x;
                dist[v] = min(dist[v], e[u][i].val);
                q.push({v});
            }
            for (int i = 1; i <= n; i++)
            {
                if (vis[i]) continue;
                dist[i] = min(dist[i], solve(u, i, bd));
                q.push({i});
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (((bd >> (i - 1)) & 1) != 0) _ans += cost[i];
        }
        ans = min(ans, _ans);
    }
    fout << ans << endl;
}
