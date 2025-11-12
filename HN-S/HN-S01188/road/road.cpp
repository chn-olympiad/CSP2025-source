#include <bits/stdc++.h>
using std::cin;

namespace solution {
    using i64 = long long;
    const int N = 1e4 + 25;
    int n, m, k;
    struct edge {
        int u, v, w;
        edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
        bool operator<(const edge& x) const {
            return w < x.w;
        }
    } A[N * 15], B[N * 15];
    std::vector<edge> egs, tree;
    int fa[N], siz[N], c[N], a[15][N];
    std::pair<int, int> pt[N * 15];
    int find(int x){ return fa[x] == x ? x :fa[x] = find(fa[x]); }
    i64 mst(int cnt, int pcnt){
        std::iota(fa + 1, fa + n + k + 1, 1);
        std::fill(siz + 1, siz + n + k + 1, 1);
        i64 ans = 0;
        for(int i=1;i<=cnt;i++){
            edge e = A[i];
            if(find(e.u) == find(e.v)) continue;
            if(siz[find(e.u)] > siz[find(e.v)]) std::swap(e.u, e.v);
            siz[find(e.v)] += siz[find(e.u)], fa[find(e.u)] = find(e.v);
            ans += e.w, pcnt--;
            if(!pcnt) break;
        }
        return ans;
    }
    void solve(){
        cin >> n >> m >> k, std::iota(fa + 1, fa + n + 1, 1);
        egs.reserve(m), tree.reserve(n - 1);
        for(int i=1,u,v,w;i<=m;i++){
            cin >> u >> v >> w;
            egs.emplace_back(u, v, w);
        }
        std::sort(egs.begin(), egs.end());
        for(int i=0;i<m;i++){
            int u = egs[i].u, v = egs[i].v;
            if(find(u) == find(v)) continue;
            tree.push_back(egs[i]), fa[find(u)] = find(v);
        }
        for(int i=1;i<=k;i++){
            cin >> c[i];
            for(int j=1;j<=n;j++) cin >> a[i][j], pt[(i - 1) * n + j] = {i, j};
        }
        std::sort(pt + 1, pt + k * n + 1, [](auto x, auto y){
            return a[x.first][x.second] < a[y.first][y.second];
        });
        i64 ans = LLONG_MAX;
        for(int S=0;S<(1<<k);S++){
            i64 ret = 0; int tot = 0, nd = 0;
            for(int i=1;i<=k;i++){
                if(!((S >> (i - 1)) & 1)) continue;
                ret += c[i], nd++;
            }
            for(int i=1;i<=n*k;i++){
                if((S >> (pt[i].first - 1)) & 1) B[++tot] = edge(pt[i].first + n, pt[i].second, a[pt[i].first][pt[i].second]);
            }
            std::merge(tree.begin(), tree.end(), B + 1, B + tot + 1, A + 1);
            ans = std::min(ans, mst(tot + n - 1, n + nd) + ret);
        }
        std::cout << ans << '\n';
    }
}

signed main(){
    #ifndef LOCAL
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    solution::solve();
    return 0;
}

// think twice, code once
// Writting by xiezheyuan
