#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
struct edge
{ 
    int u, v, w;
};
int fa[N], si[N];
void init(int n)
{
    for(int i = 1; i <= n; i++)
        fa[i] = i, si[i] = 1;
}
int find(int n)
{
    if(fa[n] != n) 
        return fa[n] = find(fa[n]);
    return n;
}
void merge(int u, int v)
{
    int fu = find(u), fv = find(v);
    if(fu == fv)
        return;
    fa[fu] = fa[fv];
    si[fv] += si[fu];
}
bool cmp(edge x, edge y)
{
    return x.w < y.w;
}
ll ans = 0;
bool vis[N + 20];
bool used[N + 20];
int coin[N];
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<edge> G;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    init(n + k);
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G.push_back({u, v, w});
    }
    si[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        coin[i + n] = c, si[i + n] = 0;
        G.push_back({0, i + n, c});
        for(int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            G.push_back({j, i + n, w});
        }
    }
    sort(G.begin(), G.end(), cmp);
    for(auto val : G)
    {
        int u = val.u, v = val.v, w = val.w;
        // cerr << u << " " << v << " " << w << '\n';
        int fu = find(u), fv = find(v);
        if((u == 0 && v > n) || (v == 0 && u > n)) 
            vis[v] = 1;
        if((u <= n && v > n && vis[v] == 0) || (v <= n && u > n && vis[u] == 0))
            continue;
        if(fu != fv) // 不在同一连通块
        {
//        	cout << u << " " << v << '\n';
            if((u <= n && v > n && u != 0) || (v <= n && u > n && v != 0))
                used[u] = 1, used[v] = 1;
            merge(fu, fv);
            ans += w;
        }
        if(si[find(1)] == n)
            break;
    }
    cout << ans;
    return 0;
}
