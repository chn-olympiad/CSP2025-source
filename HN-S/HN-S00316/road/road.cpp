#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

struct Node
{
    int v, w;
};

const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, a[15][N], c[15], fa[N];
vector<Node> G[N];

struct Edge
{
    int u, v, w;
} e[M + 10 * N];

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int u)
{
    if (fa[u] == u) return u;
    else return fa[u] = find(fa[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    fa[u] = v;
}

void solve1()
{
    sort(e + 1, e + m + 1, cmp);
    ll sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (find(u) == find(v)) continue;
        cnt++;
        merge(u, v);
        sum += w;
        if (cnt == n - 1) break;
    }
    cout << sum << '\n';
}

bool checkA()
{
    for (int i = 1; i <= k; i++)
    {
        if (c[i] != 0) return 0;
        bool flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0) flag = 1;
        }
        if (flag == 0) return 0;
    }
    return 1;
}

void solveA()
{
    // cout << 114514 << '\n';
    // cout << k << '\n';
    for (int i = 1; i <= k; i++)
    {
        // // cout << "i = " << i << '\n';
        // for (int j = 1; j <= n; j++)
        // {
        //     for (int p = 1; p <= n; p++)
        //     {
        //         if (j == p) continue;
        //         e[++m] = {j, p, a[i][j] + a[i][p]};
        //     }
        // }
        int p;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                p = j;
                break;
            }
        }
        // cout << p << '\n';
        for (int j = 1; j <= n; j++)
        {
            if (j == p) continue;
            e[++m] = {p, j, a[i][j]};
        }
    }
    // cout << m << '\n';
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
    // }
    sort(e + 1, e + m + 1, cmp);
    ll sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        // cout << "i = " << i << '\n';
        int u = e[i].u, v = e[i].v, w = e[i].w;
        // cout << u << ' ' << v << ' ' << w << '\n';
        if (find(u) == find(v)) continue;
        // cout << "cnt = " << cnt + 1 << '\n';
        cnt++;
        merge(u, v);
        sum += w;
        // cout << sum << '\n';
        if (cnt == n - 1) break;
    }
    cout << sum << '\n';
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    // cout << k << '\n';
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        e[i] = {u, v, w};
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    if (k == 0)
    {
        solve1();
    }
    else if (checkA())
    {
        solveA();
    }
    return 0;
}