#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using ll = long long;
namespace IO{
constexpr int SIZE = 1<<20;
char in[SIZE],*p1 = in,*p2=in;
#define getchar() (p1==p2 && (p2 = (p1=in) + fread(in, 1, sizeof(in), stdin),p1==p2) ? EOF : *p1++)
template<typename T>
void read(T &x){
    x = 0;
    char ch = getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x = (x<<1) + (x<<3) + (ch^48), ch=getchar();
}
};
using namespace IO;
constexpr int N = 1e4 + 15;
constexpr ll LLINF = 9e18;
struct Edge{
    int u, v;
    ll w;
    Edge (int _u, int _v, ll _w):
        u(_u), v(_v), w(_w){}
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};
vector<Edge> e;
int n, m, K;

int c[15], id[15];
ll a[15][N], minn[15];

ll ans = LLINF;

int dfa[N];

void init(int n){
    for (int i = 1; i <= n; i++) dfa[i] = i;
}

int getfa(int x){return x == dfa[x] ? x : dfa[x] = getfa(dfa[x]);}

vector<int> g[N], g2[N];
int fa[N];
void dfs(int u,int f){
    fa[u] = f;
    for (int v : g[u]){
        if(v == f) continue;
        dfs(v,u);
    }
}

using pii = pair<int,int>;
int getId(int u, int v){
    return u<<10 | v;
}
__gnu_pbds::gp_hash_table<int,ll> dis;
int rt = 1;
bool exi[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n), read(m), read(K);
    e.reserve(m);
    int u, v;
    ll w;
    for (int i = 1; i <= m; ++i) read(u), read(v), read(w), e.emplace_back(u,v,w);

    for (int i = 1; i <= K; ++i){
        read(c[i]);
        for (int j = 1; j <= n; ++j) {
            read(a[i][j]);
        }
    }

    sort(e.begin(),e.end());

    ll res = 0;
    init(n);
    int fu, fv, cnt = 0;
    for (auto [u,v,w] : e){
        fu = getfa(u), fv = getfa(v);
        if (fu == fv) continue;
        res += w, dfa[fv] = fu;
        g2[u].push_back(v), g2[v].push_back(u);
        dis[getId(u,v)] = dis[getId(v,u)] = w;
        if(++cnt == n-1) break;
    }
    ans = min(ans,res);

    for (int i=1;i<=n;i++) g[i] = g2[i], exi[i] = true;

    dfs(1,0);

    int lk= (1 << K) - 1;
    for (int k = 1; k <= lk; ++k){
        ll kres = res;
        for (int i = 1; i <= K; ++i) exi[i+n] = false;
        for (int i = 1; i <= K; ++i){
            if (!((k >> (i-1)) & 1)) continue;
            id[i] = -1;
            ll maxx = 0;
            for (int u = 1; u <= n; u++){
                if (u == rt || (!exi[u])) continue;
                int f = fa[u];
                ll d = dis[getId(u,f)] - a[i][u];
                if (d > maxx) maxx = d, id[i] = u;
            }

            if(id[i] == -1) continue;

            vector<int> cf,cu;
            vector<bool> vis(n + K + 1, false);
            bool flag = false, bz = true;
            int nrt = -1, u = id[i];
            ll delta = 0;

            while(u != rt){
                vis[u] = true;
                int f = fa[u];
                ll d = dis[getId(u,f)];
                if(d > a[i][f]) delta += d - a[i][f], cf.push_back(u);
                u = f;
            }

            for (int u = 1; u <= n + K; u++){
                if(vis[u] || (!exi[u])) continue;
                int f = fa[u];
                ll d = dis[getId(u,f)];
                if(d > a[i][u]) delta += d - a[i][u], cu.push_back(u);
            }

            if (delta < c[i] + a[i][id[i]]) continue;
            
            for (int u : cf){
                int f = fa[u];
                flag = true;
                g[f].erase(lower_bound(g[f].begin(),g[f].end(),u));
                g[u].erase(lower_bound(g[u].begin(),g[u].end(),f));
                g[n+i].push_back(f), g[f].push_back(n+i);
                dis[getId(i+n,f)] = dis[getId(f,i+n)]= a[i][f];
                if(bz) {
                    nrt = u, bz = false;
                }
            }

            for (int u : cu){
                int f = fa[u];
                flag = true;
                g[f].erase(lower_bound(g[f].begin(),g[f].end(),u));
                g[u].erase(lower_bound(g[u].begin(),g[u].end(),f));
                g[n+i].push_back(u), g[u].push_back(n+i);
                dis[getId(i+n,u)] = dis[getId(u,i+n)]= a[i][u];
            }
            
            if(!bz){
                g[id[i]].push_back(i+n), g[i+n].push_back(id[i]);
                dis[getId(id[i],i+n)] = dis[getId(i+n,id[i])] = a[i][id[i]];
                dfs(rt = nrt, 0);
            }

            if(bz && flag){
                g[id[i]].push_back(i+n), g[i+n].push_back(id[i]);
                dis[getId(id[i],i+n)] = dis[getId(i+n,id[i])] = a[i][id[i]];
                fa[i+n] = id[i];
            }

            kres += (c[i] + a[i][id[i]]);
            kres -= delta;
            exi[i + n] = true;
        }
        ans = min(ans,kres);
        for (int i=1; i<=n; i++) g[i] = g2[i];
        
    }

    cout << ans << endl;
    return 0;
}