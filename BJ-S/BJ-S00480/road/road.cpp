#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 1e6 + 15;
//vector<pair<int, int> >ve[N];
int p[N];
int n, m, k, ans;
struct node
{
    int cost;
    bool used;
}ne[N];
struct egde
{
    int a, b, w;
}ve[2 * N];
int found(int x)
{
    if(p[x] == x)
        return p[x];
    return p[x] = found(p[x]);
}
bool cmp(egde x, egde y)
{
    return x.w < y.w;
}
int solve()
{
    int ans = 0, cnt = 0;
    sort(ve + 1, ve + m + 1, cmp);
    for(int i = 1;i <= m;i++)
    {
        int a = ve[i].a, b = ve[i].b, w = ve[i].w;
        if(found(a) == found(b))
            continue;
        p[found(a)] = found(b);
        ans += w;
        if(!ne[a].used)
            ans += ne[a].cost;
        if(!ne[b].used)
            ans += ne[b].cost;
        ne[a].used = ne[b].used = 1;
    }
    return ans;
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        //int a, b, c;
        //cin >> a >> b >> c;
        //ve[a].push_back({b, c});
        //ve[b].push_back({a, c});
        cin >> ve[i * 2 - 1].a >> ve[i * 2 - 1].b >> ve[i * 2 - 1].w;
        ve[i * 2].a = ve[i * 2 - 1].b;
        ve[i * 2].b = ve[i * 2 - 1].a;
        ve[i * 2].w = ve[i * 2 - 1].w;
    }
    m *= 2;
    int t = n;
    while(--k)
    {
        cin >> ne[++t].cost;
        for(int i = 1;i <= n;i++)
        {
            //cin >> b;
            //ve[++n].push_back({i, a[k].cost + b});
            //ve[i].push_back({n, a[k].cost + b});
            cin >> ve[++m].w;
            ve[m].a = t;
            ve[m].b = i;
            ve[++m].w = ve[m].w;
            ve[m].a = ve[m - 1].b;
            ve[m].b = ve[m - 1].a;
        }
    }
    for(int i = 1;i <= t;i++)
        p[i] = i;
    cout << solve();
    return 0;
}
