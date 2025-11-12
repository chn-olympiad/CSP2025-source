#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef short srt;
#define MAXN 10015
#define MAXK 15
#define lbw(x) ((x) & -(x))

int n, m, k; ll ans; int a[MAXK][MAXN], c[MAXK], id[MAXK][MAXN], f[MAXN], siz[MAXN]; struct Edge{srt u, v; int w;}; vector<Edge> vec[1<<10];
int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}
void meg(int x, int y){int fx(find(x)), fy(find(y)); if (fx == fy) return; siz[f[fx]=fy] += siz[fx];}

vector<Edge> kruskal(vector<Edge> egs){
    iota(f+1, f+n+k+1, 1); fill(siz+1, siz+n+k+1, 1); vector<Edge> ans;
    for (auto [u, v, w]: egs) if (find(u) ^ find(v)) ans.push_back({u, v, w}), meg(u, v); return ans;
}
int urd(){int x(0); char c; while ((c=getchar())<48); do x = (x<<1)+(x<<3)+(c^48); while ((c=getchar())>47); return x;}

signed main(){
    freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
    n = urd(); m = urd(); k = urd(); for (int u, v, w; m; --m) u = urd(), v = urd(), w = urd(), vec[0].push_back({(srt)u, (srt)v, w});
    for (int i(0); i<k; ++i){
        c[i] = urd(); for (int j(1); j<=n; ++j) a[i][j] = urd(); iota(id[i]+1, id[i]+n+1, 1);
        sort(id[i]+1, id[i]+n+1, [&](int x, int y){return a[i][x] < a[i][y];});
    }
    sort(vec[0].begin(), vec[0].end(), [](Edge a, Edge b){return a.w < b.w;}); vec[0] = kruskal(vec[0]); for (auto [u, v, w]: vec[0]) ans += w;
    // cerr << ans << '\n';
    // for (int i(1); i<=n; ++i) cerr << id[0][i] << ' '; cerr << '\n';
    for (int i(1); i<(1<<k); ++i){
        int p(0), nw(__lg(lbw(i)));
        for (int ps(1); ps<=n; ++ps){
            for (; p<vec[i^lbw(i)].size() && vec[i^lbw(i)][p].w<a[nw][id[nw][ps]]; ++p) vec[i].push_back(vec[i^lbw(i)][p]);
            vec[i].push_back({(srt)id[nw][ps], (srt)(n+nw+1), a[nw][id[nw][ps]]});
        }
        for (; p<vec[i^lbw(i)].size(); ++p) vec[i].push_back(vec[i^lbw(i)][p]);
        // for (auto [u, v, w]: vec[i]) cerr << u << ' ' << v << ' ' << w << '\n';
        vec[i] = kruskal(vec[i]); ll res(0); for (auto [u, v, w]: vec[i]) res += w;
        for (int j(0); j<k; ++j) if (i>>j&1) res += c[j]; ans = min(ans, res);
        // cerr << i << ' ' << ans << '\n'; if (i == 1) return 0;
    }
    cout << ans;

    return 0;
}