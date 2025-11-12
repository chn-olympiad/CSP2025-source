#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int n, m, k;
int head[10039], to[N], nxt[N];
long long w[N];
int fa[10039];
long long ww[10039];
long long dis[10039];
bool vis[10039];
int tot = 0;
int ans = 0;
inline void add(int x, int y, long long z)
{
    nxt[++tot] = head[x], head[x] = tot, to[tot] = y, w[tot] = z;
}
int tong[20];
void bfs(int x)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[x] = 0;
    q.push(make_pair(0, x));
    while (q.size())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;

        for (int i = head[u]; i; i = nxt[i])
        {
            int v = to[i];
            // cout << v << " " << dis[u] + w[i] + ww[v] << " " << dis[v] << "     ";
            if (dis[v] > dis[u] + w[i] + ww[v])
            {
                dis[v] = dis[u] + w[i] + ww[v];
                fa[v] = u;
                if (!vis[v])
                    q.push(make_pair(dis[v], v));
            }
        }
        // cout << "\n";
    }
}
void dfs(int x, int fat)
{
    dis[x] = 0;
    int ffff=0;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = to[i];
        if (fa[y] != x || y == fat)
            continue;
        dfs(y, x);
        ffff=1;
        if (x == 0)
        {
            dis[x] += dis[y];
        }
        else
        {
            dis[x] += dis[y] + w[i];
        }
    }
    dis[x] += ww[x];
    if(ffff==0)
        dis[x]-=ww[x];
}
int flag = 0;
struct Node
{
    int x, y;
    long long w;
} E[N];
bool cmp(Node A, Node B)
{
    return A.w < B.w;
}
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void work1()
{
    for (int i = 1; i <= m; i++)
    {
        cin >> E[i].x >> E[i].y >> E[i].w;
    }
    sort(E + 1, E + 1 + m, cmp);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int nnum = 0;
    long long aans=0;
    for (int i = 1; i <= m; i++)
    {
        int x=E[i].x,y=E[i].y;
        x=find(x),y=find(y);
        if(x==y)
            continue;
        aans+=E[i].w;
        nnum++;
        fa[x]=y;
        if(nnum==n-1)
            break;
    }
    cout<<aans;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    if (k == 0)
    {
        work1();
        return 0;
    }
    int x, y, z;
    while (m--)
    {
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    for (int i = 1; i <= k; i++)
    {
        flag = 0;
        cin >> ww[i + n];
        if (ww[i + n])
            flag = 1;
        for (int j = 1; j <= n; j++)
        {
            cin >> z;
            if (z)
                flag = 1;
            add(i + n, j, z);
            add(j, i + n, z);
        }
        if (flag == 0)
        {
            cout << 0;
            return 0;
        }
    }

    for (int i = 1; i <= n + k; i++)
        add(0, i, 1e9), dis[i] = 1e17;

    bfs(1);
    dfs(0, -1);
    cout << dis[0];
    return 0;
}