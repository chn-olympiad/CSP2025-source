#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e4 + 5, M = 1e6 + 5, K = 13, INT = 1e9 + 5;
const ll INF = 1e16;

int n, m, k, c[K], gt[K][N], tot, id[K][N];
ll ans = INF, sum;

struct edge{
    int u, v, w;
}d[M], g[M];
vector<edge> p[K * N];
vector<int> v;

bool cmp(const edge &ad, const edge &bd){
    return ad.w < bd.w;
}

struct DSU{
    int fa[N], sz[N], cnt;
    ll res;
    void init(int op){
        cnt = n + op, res = 0;
        for(int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
    }
    int fi(int x){
        return fa[x] == x ? x : fa[x] = fi(fa[x]);
    }
    bool Merge(int x, int y, int w){
        int a = fi(x), b = fi(y);
        if(a == b) return 0;
        if(sz[a] > sz[b]) swap(a, b);
        res += w, cnt--;
        fa[a] = b, sz[b] += sz[a];
        return 1;
    }
}l;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(register int i = 1; i <= m; i++) cin >> d[i].u >> d[i].v >> d[i].w;
    for(register int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> gt[i][j], v.push_back(gt[i][j]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(register int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++) id[i][j] = lower_bound(v.begin(), v.end(), gt[i][j]) - v.begin() + 1;
    }
    if(n == 1){
        cout << 0;
        return 0;
    }
    l.init(0);
    sort(d + 1, d + m + 1, cmp);
    for(register int i = 1; i <= m; i++){
        if(l.Merge(d[i].u, d[i].v, d[i].w)) tot++, g[tot] = d[i];
    }
    for(register int i = 0; i < (1 << k); i++){
        int cnt = 0;
        sum = 0;
        for(register int j = 0; j < k; j++){
            if((i >> j) & 1){
                cnt++, sum += c[j + 1];
                for(int y = 1; y <= n; y++){
                    p[id[j + 1][y]].push_back({j + 1 + n, y, gt[j + 1][y]});
                }
            }
        }
        l.init(cnt);
        for(register int ld = 1, rd = 1; ld <= tot && l.cnt != 1; ){
            while(rd <= v.size() && p[rd].size() == 0) rd++;
            if(rd > v.size() || (ld <= tot && g[ld].w < v[rd - 1])){
                l.Merge(g[ld].u, g[ld].v, g[ld].w), ld++;
            }else{
                edge e = p[rd].back();
                l.Merge(e.u, e.v, e.w), p[rd].pop_back();
            }
        }
        for(int j = 1; j <= v.size(); j++) p[j].clear();
        ans = min(ans, l.res + sum);
    }
    cout << ans;
    return 0;
}

