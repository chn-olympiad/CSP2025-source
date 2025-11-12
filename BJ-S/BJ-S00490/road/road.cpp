#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, u, v, w;
struct edge
{
    ll u, v, w;
    const bool operator < (const edge & oth) const
    {
        return w < oth.w;
    }
};
vector<edge> e;
ll c[15], a[15][10005];
vector<edge> f;
bool us[15];
ll fa[10015], sz[10015];
ll ans = 9e18;
void init()
{
    for (int i = 1; i <= n + k; i++)
        fa[i] = i, sz[i] = 1;
}
ll find(ll u)
{
    if (u == fa[u]) return u;
    else return fa[u] = find(fa[u]);
}
void merge(ll u, ll v)
{
    u = find(u), v = find(v);
    if (u == v) return ;
    if (sz[u] < sz[v]) swap(u, v);
    fa[v] = u;
    sz[u] += sz[v];
}
ll kruskal(ll ak, ll cost = 0)
{
    init();
    ll linked = 1, res = cost;
    ll i = 0, j = 0;
    while (linked < n + ak)
    {
        if (res > ans) return 1e18;
        edge nxt;
        if (i >= e.size() && j >= f.size()) return 1e18;
        if (i >= e.size()) nxt = f[j++];
        else if (j >= f.size()) nxt = e[i++];
        else if (e[i].w <= f[j].w) nxt = e[i++];
        else nxt = f[j++];
        if (find(nxt.u) != find(nxt.v))
        {
            merge(nxt.u, nxt.v);
            res += nxt.w;
            linked++;
        }
    }
    return res;
}
void calc()
{
    ll cost = 0, ak = 0;
    f.clear();
    for (int i = 1; i <= k; i++)
    {
        if (us[i])
        {
            cost += c[i];
            for (int j = 1; j <= n; j++)
                f.push_back({n + i, j, a[i][j]});
            ak++;
        }
    }
    sort(f.begin(), f.end());
    if (cost > ans) return ;
    cost = kruskal(ak, cost);
    ans = min(ans, cost);
}
void dfs(ll now)
{
    if (now == k + 1)
    {
        calc();
        return ;
    }
    us[now] = 0;
    dfs(now + 1);
    us[now] = 1;
    dfs(now + 1);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        e.push_back({u, v, w});
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= k; i++)
    {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j++)
            scanf("%lld", &a[i][j]);
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, u, v, w;
struct edge
{
    ll u, v, w, id;
    const bool operator > (const edge & oth) const
    {
        return w > oth.w;
    }
};
ll c[15], a[15][10005];
priority_queue<edge, vector<edge>, greater<edge> > f[11];
bool used[1100005];
ll fa[10015], sz[10015];
void init()
{
    for (int i = 1; i <= n + k; i++)
        fa[i] = i, sz[i] = 1;
}
ll find(ll u)
{
    if (u == fa[u]) return u;
    else return fa[u] = find(fa[u]);
}
void merge(ll u, ll v)
{
    u = find(u), v = find(v);
    if (u == v) return ;
    if (sz[u] < sz[v]) swap(u, v);
    fa[v] = u;
    sz[u] += sz[v];
}
ll kruskal()
{
    init();
    ll linked = 0, res = 0;
    bool unl[15];
    while (!linked)
    {
        ll minx = f[0].top().w, minp = 0;
        for (int i = 1; i <= k; i++)
        {
            ll co;
            if (!unl[i])
                co = f[i].top().w +c[i];
            else
                co = f[i].top().w;
            if (co <= minx)
            {
                minx = co;
                minp = i;
            }
        }
        cout << minx << ' ' <<minp <<endl;
        ll u = f[minp].top().u, v = f[minp].top().v;
        if (find(u) == find(v)) f[minp].pop();
        else
        {
            merge(u, v);
            res += f[minp].top().w;
            f[minp].pop();
            if (minp != 0)
                unl[minp] = 1;
        }
        linked = 1;
        for (int i = 1; i <= n; i++)
            if (find(i) != find(1))
        {
            linked = 0;
            break;
        }
        /*
        edge nxt;
        if (i >= e.size() && j >= f.size()) return 1e18;
        if (i >= e.size()) nxt = f[j++];
        else if (j >= f.size()) nxt = e[i++];
        else if (e[i].w <= f[j].w) nxt = e[i++];
        else nxt = f[j++];
        if (find(nxt.u) != find(nxt.v))
        {
            merge(nxt.u, nxt.v);
            res += nxt.w;
            linked++;
        }
        *
    }
    return res;
}
int main()
{
    freopen("road1.in", "r", stdin);
    //freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        f[0].push({u, v, w, i});
    }
    ll cm = m;
    for (int i = 1; i <= k; i++)
    {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &a[i][j]);
            //e.push({n + i, j, a[i][j] + c[i], ++cm});
            f[i].push({n + i, j, a[i][j], ++cm});
        }
    }
    printf("%lld\n", kruskal());
    return 0;
}
*/