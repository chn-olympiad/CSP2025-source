#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;

struct Edge
{
    ll u, v, w;
    bool operator > (const Edge & e) const
    {
        return w > e.w;
    }
};

ll n, m, k, c, a;

ll ans;

priority_queue < Edge, vector < Edge >, greater < Edge > > q;

int fa[N + 5];

int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

ll kru()
{
    ll res = 0;
    while (!q.empty())
    {
        ll u = q.top().u, v = q.top().v, w = q.top().w;
        q.pop();
        u = find(u);
        v = find(v);
        if (u == v) continue;
        fa[v] = u;
        res += w;
    }
    return res;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++) fa[i] = i;
    for (int i = 1 ; i <= m ; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        q.push({u, v, w});
    }
    if (k == 0)
    {
        ans = kru();
        cout << ans << "\n";
        return 0;
    }
    cout << 0 << "\n";
    return 0;
}
