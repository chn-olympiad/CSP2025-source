#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long

struct Edge
{
    int u, v, w;
    Edge(int _u = -1, int _v = -1, int _w = 0): u(_u), v(_v), w(_w) {}
    bool operator < (const Edge &ed) const
    {
        return w < ed.w;
    }
};

vector<Edge> Edges;
int top[20010], siz[20010];

int read()
{
    int ret = 0;
    bool neg = false;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
        {
            neg = !neg;
        }
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    if (neg)
    {
        ret = -ret;
    }
    return ret;
}

int Find(int u)
{
    if (u == top[u])
    {
        return u;
    }
    return top[u] = Find(top[u]);
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n = read(), m = read(), k = read();
    while (m--)
    {
        int u = read(), v = read(), w = read();
        Edges.push_back(Edge(u, v, w));
    }
    for (int i = 1; i <= k; ++i)
    {
        int c = read();
        for (int j = 1; j <= n; ++j)
        {
            int w = read();
            Edges.push_back(Edge(j, n + i, w));
        }
    }
    n += k;
    sort(Edges.begin(), Edges.end());
    for (int i = 1; i <= n; ++i)
    {
        top[i] = i;
        siz[i] = 1;
    }
    int ans = 0;
    for (Edge ed: Edges)
    {
        int u = ed.u, v = ed.v, w = ed.w;
        int tu = Find(u), tv = Find(v);
        if (tu != tv)
        {
            ans += w;
            if (siz[u] < siz[v])
            {
                siz[v] += siz[u];
                top[tu] = tv;
            }
            else
            {
                siz[u] += siz[v];
                top[tv] = tu;
            }
        }
    }
    cout << ans << EOL;
    return 0;
}
