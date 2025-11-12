#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e4 + 13, MAXM = 1e6 + 5;
int n, m, k; ll ans;
struct edge{ int u, v, w; }eg[MAXM], b[1 << 10][MAXN], e[MAXN * 2];
int c[11], now[1 << 10]; ll val[1 << 10];
pair<int, int> a[11][MAXN];
int fa[MAXN], siz[MAXN];
int find(int x){ return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y){
	int p = find(x), q = find(y);
	if(siz[p] < siz[q]) swap(p, q);
	fa[q] = p, siz[p] += siz[q];
}

ll solve(int s, int N, int M){
    for(int i = 1; i <= n + k; ++i) siz[fa[i] = i] = 1;
    ll res = 0;
    for(int i = 1; i <= M; ++i){
        int u = eg[i].u, v = eg[i].v;
        if(find(u) == find(v)) continue;
        merge(u, v), res += eg[i].w;
        b[s][++now[s]] = {u, v, eg[i].w};
        if(now[s] == N - 1) break;
    }
    return res;
}
ll solve1(int s, int N, int M){
    for(int i = 1; i <= n + k; ++i) siz[fa[i] = i] = 1;
    ll res = 0;
    for(int i = 1; i <= M; ++i){
        int u = e[i].u, v = e[i].v;
        if(find(u) == find(v)) continue;
        merge(u, v), res += e[i].w;
        b[s][++now[s]] = {u, v, e[i].w};
        if(now[s] == N - 1) break;
    }
    return res;
}

signed main(){
    freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k; for(int i = 1; i <= m; ++i) cin >> eg[i].u >> eg[i].v >> eg[i].w;
    sort(eg + 1, eg + m + 1, [](edge p, edge q){ return p.w < q.w; });
    for(int i = 1; i <= k; ++i){
        cin >> c[i];
        for(int j = 1; j <= n; ++j) cin >> a[i][j].first, a[i][j].second = j;
        sort(a[i] + 1, a[i] + n + 1);
    }
    ans = solve(0, n, m);
    for(int i = 1; i < (1 << k); ++i){
        int tot = 0, u = __lg(i & -i) + 1, lst = (i ^ (i & -i));
        for(int i = 1, j = 0; i <= now[lst] + 1; ++i){
            while(j < n && (i == now[lst] + 1 || a[u][j + 1].first < b[lst][i].w)){
                j++; e[++tot] = {u + n, a[u][j].second, a[u][j].first};
            }
            if(i != now[lst] + 1) e[++tot] = b[lst][i];
        }
        val[i] = val[lst] + c[u];
        ans = min(ans, val[i] + solve1(i, n + __builtin_popcount(i), tot));
    }
    cout << ans;

    return 0;
}
