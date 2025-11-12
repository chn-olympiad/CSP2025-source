#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout); 
#define ll long long
const int N = 1e4 + 15;
const int M = 1e6 + 15;
ll a[12][N];
int n,m,k,sz[N];
bool flg = 1;
struct edge{
    int u,v; ll d;
}e[M<<1];
int fa[N];
ll ans = 1e18;
inline int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
inline void unionn(int x,int y){
    x = find(x); y = find(y);
    if(x == y) return ;
    if(sz[x] > sz[y]) swap(x,y);
    fa[x] = y;
}
signed main(){
    FILE("road");
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++) {
        cin>>e[i].u>>e[i].v>>e[i].d;
    }
    for(int i=1;i<=n+k;i++) fa[i] = i, sz[i] = 1;
    for(int i=1;i<=k;i++) {
        cin>>a[i][0];
        flg &= a[i][0] == 0 ? 1 : 0;
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
            flg &= a[i][j] == 0 ? 1 : 0;
        }
    }
    if(flg) return cout<<0,0;
    for(int i = 0;i<(1<<k);i++) {
        int len = m; ll res = 0;
        for(int j = k;~j;j--) {
            if(i >> j & 1) {
                int v= j+1;
                res += a[v][0];
                for(int p=1;p<=n;p++) e[++len] = {v+n,p,a[v][p]};
            }
        }
        stable_sort(e+1,e+len+1,[&](edge p1,edge p2){
            return p1.d < p2.d;
        });
        for(int j=1;j<=n+k;j++) fa[j] = j, sz[j] = 1;
        for(int j=1;j<=len;j++) {
            int x = find(e[j].u), y = find(e[j].v);
            if(x == y) continue;
            unionn(x,y); res += e[j].d;
        }
        ans = min(ans,res);
    }
    cout<<ans;
    return 0;
}