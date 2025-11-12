#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 10;
const int M = 1e7 + 10;
inline int read(){
    int x = 0, neg = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') neg = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x<<1) + (x<<3) + c - '0';
        c = getchar();
    }
    return x * neg;
}
int n, m, k;
int f[N], a[15][N], c[N];
ll ans = 1e18;
int Find(int x){
    return x == f[x] ? x : f[x] = Find(f[x]);
}
struct edge{
    int u, v;
    ll w;
    bool operator < (const edge &A) const{
        return w < A.w;
    }
} e[M];
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1; i <= m; i++) e[i] = {read(), read(), read()};
    for(int i = 1; i <= k; i++) {
        c[i] = read();
        for(int j = 1; j <= n; j++) a[i][j] = read();
    }
    int tm = m;
    for(int sta = 0; sta < (1 << k); sta++){
        ll tmp = 0;
        m = tm;
        for(int i = 1; i <= k; i++){
            if(sta & (1 << (i-1))) {
                tmp += c[i];
                for(int u = 1; u < n; u++)
                    for(int v = u+1; v <= n; v++)
                    e[++m] = {u, v, a[i][u] + a[i][v]};
            }
        }
        sort(e + 1, e + m + 1);
        for(int i = 1; i <= n; i++) f[i] = i;
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            int u = e[i].u, v = e[i].v;
            ll w = e[i].w;
            int fu = Find(u), fv = Find(v);
            if(fu != fv){
                tmp += w;
                f[fv] = fu;
                cnt++;
            }
            if(cnt == n-1) break;
        }
        ans = min(tmp, ans);
    }
    printf("%lld", ans);
}
