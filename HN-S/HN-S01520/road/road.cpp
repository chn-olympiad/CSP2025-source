#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e4 + 15, K = 15, M = 1e4 + 2;

int n, m, k, c[K], a[K][N], fa[N], siz[N], len;
ll ans;
bool f[K];

struct tp{
    int v;
    ll w;
};
vector<tp> g[N];

struct TP{
    int u, v;
    ll w;
};
vector<TP> t;

bool cmp(const TP &i, const TP &j){
    return i.w < j.w;
}

int Find(int x){
    return (fa[x] == x ? x : fa[x] = Find(fa[x]));
}

void Merge(int x, int y){
    int fx = Find(x), fy = Find(y);
    if(fx != fy){
        if(siz[fx] < siz[fy]){
            swap(fx, fy);
        }
        fa[fy] = fx;
        siz[fx] += siz[fy];
    }
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        t.push_back({u, v, w});
    }
    iota(fa + 1, fa + n + k + 1, 1);
    fill(siz + 1, siz + n + k + 1, 1);
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            Merge(i + n, j);
        }
    }
    sort(t.begin(), t.end(), cmp);
    for(TP it : t){
        cout << Find(it.u) << ' ' << Find(it.v) << '\n';
        if(Find(it.u) != Find(it.v)){
            Merge(it.u, it.v);
            ans += it.w;
        }
    }
    cout << ans;
    return 0;
}
