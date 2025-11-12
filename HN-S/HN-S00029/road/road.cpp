#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 20, M = 2e6 + 1e5 + 2, K = 12;
int n, m, k;
struct Edge{
    int u, v, w;
}e2[M], e3[M];
int c[N];
int a[K][N];

bitset <M> Can;

int fa[N], siz[N];

inline int Find(int x){
    if(fa[x] == x) return x;
    fa[x] = Find(fa[x]);
    return fa[x];
}

inline void change(int x, int y){
    x = fa[x], y = fa[y];
    if(x == y) return;
    if(siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    fa[y] = x;
}

inline ll kk(int n, int m){
    sort(e2 + 1, e2 + 1 + m, [](const Edge &x, const Edge &y){ return x.w < y.w; });
    for(int i = 1; i <= n; i ++){
        fa[i] = i, siz[i] = 1;
    }

    ll ans = 0;
    int cnt = 0;
    for(int i = 1, u, v, w; i <= m; i ++){
        u = e2[i].u, v = e2[i].v, w = e2[i].w;
        if(Find(u) != Find(v)){
            change(u, v);
            ans += w;
            cnt ++;
            Can[i] = 1;
        }
        if(cnt == n - 1){
            return ans;
        }
    }
    return 1e18;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        e2[i] = {u, v, w};
    }
    for(int i = 1; i <= k; i ++){
        cin >> c[i];
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
        }
    }
    ll ans = kk(n, m), ans2;

    for(int i = 1, cnt = 0; i <= m; i ++){
        if(Can[i]){
            cnt ++;
            e3[cnt] = e2[i];
        }
    }
    m = n - 1;

    for(int i = 1, cnt, cnt1; i < (1 << k); i ++){
        cnt1 = 0;
        ans2 = 0;
        cnt = m;
        for(int i = 1; i <= m; i ++){
            e2[i] = e3[i];
        }
        for(int j = 1; j <= k; j ++){
            if(((i >> j - 1) & 1) ^ 1) continue;
            cnt1 ++;
            for(int l = 1; l <= n; l ++){
                cnt ++;
                e2[cnt] = {n + cnt1, l, a[j][l]};
            }
            ans2 += c[j];
        }
        ans = min(ans, kk(n + cnt1, cnt) + ans2);
    }

    cout << ans;

    return 0;
}
