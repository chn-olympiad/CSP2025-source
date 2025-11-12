#include <bits/stdc++.h>
#define int long long
using namespace std;
int n = 0;
int m = 0;
int k = 0;
struct ed{
    int u;
    int v;
    int w;
    int id;
}e1[1000010];
ed e[500010];
bool cmp(ed one, ed two){return one.w < two.w;}
int fa[10050];int bs = 0;
int Find(int x){
    if(x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}
int c[20];
int slv(int msk){ int sm = 0;
    for(int i = 1; i <= n + k; i++) fa[i] = i;
    int ct = 0; int lim = n + __builtin_popcount(msk) - 1;
    for(int i = 1; i <= bs; i++){
        if(e[i].id != 0){
            if((msk & (1 << (e[i].id - 1))) == 0) continue;
        }
        int u = e[i].u; int v = e[i].v;
        
        int fu = Find(u); int fv = Find(v);
        if(fu != fv){
            fa[fu] = fv; sm += e[i].w; ct ++;
            // cout << u << " " << v << " " << e[i].id << " " << e[i].w << '\n';
            if(ct == lim) break;
        }
    } return sm;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    // int bs = m;
    for(int i = 1;i <= m; i++){
        int u,v,w; cin >> e1[i].u >> e1[i].v >> e1[i].w;
        e1[i].id = 0; 
    } sort(e1 + 1, e1 + 1 + m,cmp);
    for(int i = 1; i <= n; i++) fa[i] = i;
    
    for(int i = 1; i <= m; i++){
        int u = e1[i].u; int v = e1[i].v;
        int fu = Find(u); int fv = Find(v);
        if(fu != fv){
            fa[fu] = fv;
            e[++ bs] = e1[i]; //cout << u << " " << v << " nb\n";
            if(bs == n - 1) break;
        }
    }
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            int v; cin >> v;
            bs ++; e[bs].id = i; e[bs].u = i + n; e[bs].v = j; e[bs].w = v;
        }
    } int as = 1e18; sort(e + 1, e + 1 + bs, cmp);
    // for(int i = 1; i <= bs; i++){
        // cout << e[i].u << " " << e[i].v << " " << e[i].w << " " << e[i].id << '\n';
    // }
    for(int i = 0; i < (1 << k); i++){
        int cr = slv(i);
        for(int j = 1; j <= k; j++){
            if(i & (1 << (j - 1))) cr += c[j];
        }
        as = min(cr, as);
    }
    cout << as << '\n';
    return 0;
}