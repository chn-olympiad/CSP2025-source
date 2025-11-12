#define dps 799
#define I dryer
#include<bits/stdc++.h>
using namespace std;
#define r0 return 0;
#define int long long
const int N = 4000500;
struct node{
    int a,b,w;
    bool operator <(node x) const{return w < x.w;}
}g[N],h[N];
int c[N],a[13][20020];
int f[N];
int nn,m,n;
inline int find(int x){
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}
int ans = 1ll * dps << 52;
inline int kk(int nm){
    int res = 0;
    for(int i = 1; i <= nm; ++ i) h[i] = g[i];
    sort(h + 1, h + 1 + nm);
    for(int i = 1; i <= nn; ++ i) f[i] = i;
    for(int i = 1; i <= nm; ++ i){
        int aa = h[i].a, b = h[i].b, w = h[i].w;
        int fa = find(aa), fb = find(b);
        if(fa != fb){
            f[fa] = fb;
            res += w;
            //cout << aa << ' ' << b << ' ' << w << ';';
        }
    }
    return res;
}
int k, bin[202];
inline void dfs(int now){
    if(now == k + 1){
        int idx = m;
        int res = 0;
        for(int i = 1; i <= k; ++ i){
            if(bin[i]) for(int j = 1; j <= nn; ++ j) g[++idx] = {i + n,j,a[i][j]};
            if(bin[i])res += c[i];
        }
        ans = min(ans, res + kk(idx));
        //for(int i = 1; i <= k; ++ i)cout << bin[i] << ' '; cout << res << ' ' << kk(idx) << endl;
        return;
    }
    dfs(now + 1);
    bin[now] = 1;
    dfs(now + 1);
    bin[now] = 0;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k; nn = n + k;
    for(int i = 1; i <= m; ++ i){
        int aa,b,w; scanf("%lld%lld%lld", &aa, &b, &w);
        g[i] = {aa,b,w};
    }
    int A = 0;
    for(int i = 1; i <= k; ++ i){
        cin >> c[i]; A |= c[i];
        for(int j = 1; j <= n; ++ j) scanf("%lld", &a[i][j]);
    }
    if(!A){
        int idx = m;
        for(int i = 1; i <= k; ++ i){
            for(int j = 1; j <= n; ++ j){
                g[++idx] = {i + n,j,a[i][j]};
            }
        }
        cout << kk(idx) << endl;
        return 0;
    }
    dfs(1);
    cout << ans << endl;
}
