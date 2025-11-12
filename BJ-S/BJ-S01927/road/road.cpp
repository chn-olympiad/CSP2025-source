#include <bits/stdc++.h>
using namespace std;
#define int long long

const int NR = 1e4 + 5, MR = 1e6 + 5;
int n, m, k;
struct Edge{
    int u, v, w;
    bool operator <(const Edge &a) const{
        return w < a.w;
    }
}e[MR], g[MR], t[MR];

int cur;
int f[NR], mst;
int c[15], a[15][NR];

int find(int x){
    if(f[x] == x) return f[x];
    return f[x] = find(f[x]);
}

void kruskal()
{
    for(int i = 1; i <= n; i ++) f[i] = i;
    sort(e+1, e+m+1);
    int cnt = 0;
    for(int i = 1; i <= m; i ++){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(find(u) == find(v)) continue;
        f[find(u)] = find(v);
        cnt ++, mst += w;
        g[++cur] = {u,v,w};
        if(cnt == n-1) break;
    }
}

int Kruskal(int n, int m)
{
    int ret = 0;
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) t[i] = g[i];
    sort(t+1, t+m+1);
    int cnt = 0;
    for(int i = 1; i <= m; i ++){
        int u = t[i].u, v = t[i].v, w = t[i].w;
        if(find(u) == find(v)) continue;
        f[find(u)] = find(v);
        cnt ++, ret += w;
        if(cnt == n-1) break;
    }
    return ret;
}

int ans;

void dfs(int x, int cnt, int sum){
    if(sum > ans) return ;
    if(x > k){
        ans = min(ans, Kruskal(cnt+n, cur)+sum);
        return ;
    }
    for(int i = 1; i <= n; i ++) g[++cur] = {i, n+x, a[x][i]};
    dfs(x+1, cnt+1, sum + c[x]);
    cur -= n;
    dfs(x+1, cnt, sum);
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    if(k == 0){
        cout << mst << endl;
        return 0;
    }
    for(int i = 1; i <= k; i ++){
        cin >> c[i];
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
    ans = mst;
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
