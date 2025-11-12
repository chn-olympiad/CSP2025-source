#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;
const int maxk = 20;
struct node
{
    int x, c[maxn];
}a[maxk];
struct edge
{
    int u, v, w;
    bool operator < (const edge &p) const
    {
        return w < p.w;
    }
}e[maxm];
int n, m, k, Min[maxn], Mn[maxk], dep[maxk][maxn], p[maxn], idx[maxk];
bool flag[maxn];
int fa[maxn];
vector<edge> l;
vector<int> G[maxn];
int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void kru()
{
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        u = find(u);
        v = find(v);
        if (u != v)
        {
            cnt++;
            l.push_back(e[i]);
            G[e[i].u].push_back(e[i].v);
            G[e[i].v].push_back(e[i].u);
            fa[u] = v;
            if (cnt == n - 1) return;
        }
    }
}
void dfs(int u, int fa, int id)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == fa) continue;
        dep[id][v] = dep[id][u] + 1;
        dfs(v, u, id);
    }
}
signed main ()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(Min, 0x3f, sizeof(Min));
    memset(Mn, 0x3f, sizeof(Mn));
    memset(p, 0x3f, sizeof(p));
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(e + 1, e + m + 1);
    kru();
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i].x;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i].c[j];
            p[j] = min(p[j], a[i].c[j]);
            if (Mn[i] > a[i].c[j]) {Mn[i] = a[i].c[j];idx[i] = j;}
        }
    }
    int summ = 0;
    for (int i = 0; i < l.size(); i++) summ += l[i].w;
    if (k == 0)
    {
        cout << summ << endl;
        return 0;
    }
    int ans = 1e18;
    for (int i = 1; i <= k; i++) dfs(idx[i], -1, i);
    for (int i = 0; i < (1 << k); i++)
    {
        int sum = summ;
        for (int j = 1; j <= k; j++)
        {
            if (i & (1 << j - 1)) sum += a[j].x + Mn[j];
        }
        for (int j = l.size() - 1; j >= 0; j--)
        {
            int minn = 1e18;
            for (int q = 1; q <= k; q++)
            {
                if (i & (1 << q - 1))
                {
                    minn = min(minn, a[q].c[dep[q][l[j].u] < dep[q][l[j].v] ? l[j].v : l[j].u]);
                }
            }
            if (l[j].w > minn) sum -= l[j].w - minn;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
