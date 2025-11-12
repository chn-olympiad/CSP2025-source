#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, m, k, ans, fa[10005];
struct node
{
    int u, v, w;
};
vector<node> e;

bool operator< (node x, node y)
{
    return x.w < y.w;
}

int fnd(int x)
{
    if(fa[x] == x)
    {
        return x;
    }
    fa[x] = fnd(fa[x]);
    return fa[x];
}

void un(int x, int y)
{
    int fx = fnd(x);
    int fy = fnd(y);
    fa[fx] = fy;
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    e.push_back({0, 0, 0});
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n + 1; j++)
        {
            int x;
            cin >> x;
        }
    }
    sort(++e.begin(), e.end());
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for(int i = 1; i <= m; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        if(fnd(u) != fnd(v))
        {
            ans += w;
            un(u, v);
        }
    }
    cout << ans << endl;

    return 0;
}

/*
CSP-S 2025 RP+=1e20
mengleo 872662
2025.10.30.
*/