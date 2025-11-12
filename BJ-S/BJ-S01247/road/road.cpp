#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e4 + 15;

struct Edge
{
    int u, v, w;
    bool operator < (const Edge &b)const { return w < b.w; }
};
vector<Edge> E[11], M[1 << 10];
int val[11], fa[maxn], siz[maxn];
ll sum[1 << 10];

int findfa(int x) { return x == fa[x] ? x : fa[x] = findfa(fa[x]); }

void merge(int x, int y)
{
    E[0].clear();
    int i = 0, j = 0, A = E[x].size(), B = M[y].size();
    while (i < A || j < B)
    {
        if (j == B || (i < A && E[x][i].w < M[y][j].w)) E[0].emplace_back(E[x][i]), i++;
        else E[0].emplace_back(M[y][j]), j++;
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        E[0].emplace_back((Edge){u, v, w});
    }
    sort(E[0].begin(), E[0].end());
    for (int i = 1; i <= k; i++)
    {
        cin >> val[i];
        for (int j = 1; j <= n; j++)
        {
            int w; cin >> w;
            E[i].emplace_back((Edge){j, i + n, w});
        }
        sort(E[i].begin(), E[i].end());
    }
    int K = 1 << k;
    for (int s = 1; s < K; s++)
    {
        int x = __builtin_ctz(s & -s);
        sum[s] = val[x + 1] + sum[s ^ (s & -s)];
    }

    for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for (Edge tmp : E[0])
    {
        int u = findfa(tmp.u), v = findfa(tmp.v);
        if (u == v) continue;
        sum[0] += tmp.w, M[0].emplace_back(tmp);
        if (siz[u] < siz[v]) swap(u, v); fa[v] = u, siz[u] += siz[v];
    }

    ll res = sum[0];
    for (int s = 1; s < K; s++)
    {
        int x = __builtin_ctz(s & -s), p = s ^ (s & -s);
        for (int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;
        merge(x + 1, p);
        for (Edge tmp : E[0])
        {
            int u = findfa(tmp.u), v = findfa(tmp.v);
            if (u == v) continue;
            sum[s] += tmp.w, M[s].emplace_back(tmp);
            if (siz[u] < siz[v]) swap(u, v); fa[v] = u, siz[u] += siz[v];
        }
        res = min(res, sum[s]);
    }
    cout << res;
    return 0;
}