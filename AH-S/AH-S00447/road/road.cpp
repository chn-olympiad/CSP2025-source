#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    ll u, v, w;
    bool operator<(const node & b) const
    {
        return this->w > b.w;
    }
} edge[1000005];
ll fa[10005], siz[10005];
ll find(ll x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void hebin(ll x, ll y)
{
    x = find(x);
    y = find(y);
    if (x == y) return ;
    if (siz[x] > siz[y]) swap(x, y);
    {
        fa[x] = y;
        siz[y] += siz[x];
    }
}
ll n, m, k;
ll kruskal()
{
    priority_queue<node> pq;
    ll ans = 0;
    for (int i = 1; i <= m; i++) pq.push(edge[i]);
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        ll u = t.u, v = t.v, w = t.w;
        if (find(u) == find(v)) continue ;
        ans += w;
        hebin(u, v);
    }
    return ans;
}
void solve()
{
    //
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        siz[i] = 1;
    }
    for (int i = 1; i <= m; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
    cout << kruskal();
    //
    cout << '\n';
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}