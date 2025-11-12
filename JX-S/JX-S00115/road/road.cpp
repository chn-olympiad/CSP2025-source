#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

long long read()
{
    char ch;
    int num = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') num = num * 10 + (ch - '0'), ch = getchar();
    return num;
}
const int MAXN = 1e4 + 15;
const int INF = 0x3f3f3f3f;
vector<pair<int, int> > edges[MAXN];
int n, m, k, p[15][MAXN], c[20], dis[MAXN];
bool vis[MAXN], cn[MAXN];
void dij(int s)
{
    priority_queue<pair<int, int> > pq;
    dis[s] = 0;
    pq.push({-dis[s], s});
    while(!pq.empty())
    {
        auto[_, u] = pq.top();
        pq.pop();
        for(auto[v, w] : edges[u])
        {
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({-dis[v], v});
            }
        }
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1, u, v, w; i <= m; i++)
    {
        u = read(), v = read(), w = read();
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    for(int i = 1; i <= k; i++)
    {
        c[i] = read();
        for(int j = 1; j <= n; j++)
        {
            p[i][j] = read();
            edges[n + i].push_back({j, p[i][j]});
        }
    }
    memset(dis, INF, sizeof(dis));
    dij(1);

    return 0;
}
