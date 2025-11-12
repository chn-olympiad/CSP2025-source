# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 1e4 + 20;
const int M = 1e6 + 100;
//my last csp s
struct edge
{
    int u, v, w;
}E[M], Elife[M];
bool operator < (edge a, edge b)
{
    return a.w < b.w;
}
int fa[N];
int getfa(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);
}
int cnt;
int c[N];
int cost[15][N];
int min_[15];
int ans = 4e18;
signed main()
{
    ios::sync_with_stdio(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin  >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    for(int j = 1; j <= k; j++)
    {
        cin >> c[j];
        for(int i = 1; i <= n; i++)
        {
            cin >> cost[j][i];

        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) fa[i] = i;
    sort(E + 1, E + m + 1);
    for(int i = 1; i <= m; i++)
    {
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if(getfa(u) == getfa(v)) continue;
        else
        {
            fa[getfa(u)] = getfa(v);
            Elife[++cnt] = E[i];
            ans += w;
        }
    }
    for(int i = 0; i < (1 << k); i++)
    {
        int cnt0 = cnt;
        int tot = 0;
        for(int i = 1; i <= cnt0; i++)
            E[i] = Elife[i];
        for(int j = 0; j < k; j++)
        {
            if((1 << j) & i)
            {
                tot += c[j + 1];
                for(int k = 1; k <= n; k++)
                {
                    E[++cnt0] = {n + j + 1, k, cost[j + 1][k]};
                }
            }
        }
        for(int i = 1; i <= n; i++) fa[i] = i;
        sort(E + 1, E + cnt0 + 1);
        for(int i = 1; i <= cnt0; i++)
        {
            int u = E[i].u, v = E[i].v, w = E[i].w;
            if(getfa(u) == getfa(v)) continue;
            else
            {
                fa[getfa(u)] = getfa(v);
                Elife[++cnt] = E[i];
                tot += w;
            }
        }
        ans = min(ans, tot);
    }
    cout << ans << endl;
    return 0;
}
