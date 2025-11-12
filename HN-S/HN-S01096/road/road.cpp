#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18 + 1;
template<typename T> inline void chkmax(T& x,T y){ (x < y) && (x = y); }
template<typename T> inline void chkmin(T& x,T y){ (x > y) && (x = y); }
const int N = 10005;
int n,m,k;
struct EDGE { 
    int u,v; ll w;
} e[1000005],g[N],_g[N * 11],G[N * 11];
int t;
inline bool cmp(EDGE x,EDGE y){ return x.w < y.w; }
struct DSU {
    int fa[N + 100],siz[N + 100];
    inline void init(){
        for(int i = 1;i <= n + k;i++) fa[i] = i,siz[i] = 1;
    }
    inline int fid(int x){ return x == fa[x] ? x : fa[x] = fid(fa[x]); }
    inline void merge(int x,int y){
        x = fid(x),y = fid(y);
        if(siz[x] < siz[y]) swap(x,y);
        if(x ^ y) fa[y] = x,siz[x] += siz[y];
    }
} U;
struct node {
    ll v; 
    EDGE e[N]; 
} a[15];
inline void merge(EDGE e[]){
    for(int i = 1;i <= t;i++) _g[i] = G[i];
    int tt = 0;
    for(int i = 1,j = 1;i <= t;i++){
        while(j <= n && e[j].w < _g[i].w) G[++ tt] = e[j],j ++;
        G[++ tt] = _g[i];
    }
    t = tt;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) 
        cin >> e[i].u >> e[i].v >> e[i].w;
    U.init();
    sort(e + 1,e + m + 1,cmp);
    ll ans = 0;
    for(int i = 1,tot = 0;i <= m;i++){
        if(U.fid(e[i].u) == U.fid(e[i].v)) continue;
        ans += e[i].w,U.merge(e[i].u,e[i].v);
        g[++ tot] = e[i];
        if(tot == n - 1) break;
    }
    for(int i = 1;i <= k;i++){
        cin >> a[i].v;
        for(int j = 1;j <= n;j++)
            cin >> a[i].e[j].w,a[i].e[j].u = i + n,a[i].e[j].v = j;
        sort(a[i].e + 1,a[i].e + n + 1,cmp);
    }
    for(int s = 1;s < 1 << k;s++){
        t = 0;
        for(int i = 1;i < n;i++) G[++ t] = g[i];
        int c = 0;ll res = 0; 
        bool fl = 1;
        for(int i = 1;i <= k;i++){
            if(s >> i - 1 & 1 ^ 1) continue;
            c ++,res += a[i].v; if(res >= ans){ fl = 0; break; }
            merge(a[i].e);
        }
        if(!fl) continue;
        U.init();
        for(int i = 1,tot = 0;i <= t;i++){
            if(U.fid(G[i].u) == U.fid(G[i].v)) continue;
            res += G[i].w; if(res >= ans){ fl = 0; break; }
            U.merge(G[i].u,G[i].v),++ tot;
            if(tot == n + c - 1) break;
        }
        if(fl) ans = res;
    }
    cout << ans << "\n";
    return 0;
}
/*
g++ road.cpp -o road -std=c++14 -O2 -static
time ./road
*/