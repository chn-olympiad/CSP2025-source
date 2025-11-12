#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
struct node
{
    int pos, dis;
    bool operator <(const node &w)const
    {
        return w.dis < dis;
    }
};
struct edge
{
    int to, next, dis;
}e[1000005];
int b[15], head[1000005], cnt, dis[1000005], g[10005];
bool vis[1000005], v[15];
void addedge(int u, int v, int w)
{
    cnt++;
    e[cnt].to = u;
    e[cnt].next = v;
    e[cnt].dis = w;
    head[u] = cnt;
}
priority_queue<node> q;
int n, m, k;
void dijsktra(int s)
{
    for (int i = 1; i <= n + k; i++)
    {
        dis[i] = inf;
    }
    dis[s] = 0;
    vis[s] = 1;
    q.push((node){s, 0});
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, y = tmp.dis;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (y > n && !v[y - n]) continue;
            if (dis[y] > e[i].dis)
            {
                dis[y] = e[i].dis;
                if (!vis[y])
                {
                    vis[y] = 1;
                    q.push({y, dis[y]});
                }
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (!v[i] && dis[i + n] > e[i].dis + b[i])
            {
                dis[i + n] = e[i].dis + b[i];
                v[i] = 1;
                if (!vis[x])
                {
                    vis[x] = 1;
                    q.push({x, dis[i + n]});
                }
            }
        }
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
        g[u]++;
        g[v]++;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            addedge(n + i, j, w);
            addedge(j, n + i, w);
            g[n + i]++;
            g[j]++;
        }
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i] > g[pos])
        {
            pos = i;
        }
    }
    dijsktra(pos);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += dis[i];
    }
    cout << sum << endl;
    return 0;
}
