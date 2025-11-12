//LMY bao you zheng jie bie gua!!!~~~
#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define lop(i, x, y) for (int i = x; i >= y; i--)
using namespace std;
typedef long long ll;
const int MR = 1e6 + 5;
const int NR = 2e4 + 5;
inline int read();
int n, m, k;
int c[15];
int w[15][NR];
struct Edge{
    int u, v, w;
    bool operator<(Edge y) const{
        return w < y.w;
    }
}in[MR], p[MR];
int cnt;
int fa[NR];
int fd(int k){
    if (k == fa[k]) return k;
    return fa[k] = fd(fa[k]);
}
ll ans;
bool xuan[15];
void init(){
    rep(i, 1, n + k){
        fa[i] = i;
    }
}
void dfs(int step){
    if (step > k){
        init();
        ll re = 0;
        rep(i, 1, cnt){
            int u = p[i].u, v = p[i].v, w = p[i].w;
            if (u > n){
                if (xuan[u - n] == false){
                    continue;
                }
            }
            int fu = fd(u), fv = fd(v);
            if (fu != fv){
                fa[fu] = fv;
                re += 1ll * w;
            }
        }
        rep(i, 1, k){
            if (xuan[i] == true){
                re += 1ll * c[i];
            }
        }
        ans = min(ans, re);
        return;
    }
    xuan[step] = true;
    dfs(step + 1);
    xuan[step] = false;
    dfs(step + 1);
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    rep(i, 1, m){
        in[i].u = read(), in[i].v = read(), in[i].w = read();
    }
    cnt = 0;
    rep(j, 1, k){
        c[j] = read();
        rep(i, 1, n){
            w[j][i] = read();
            p[++cnt] = (Edge){n + j, i, w[j][i]};
        }
    }
    sort(in + 1, in + m + 1);
    ans = 0;
    init();
    rep(i, 1, m){
        int u = in[i].u, v = in[i].v, w = in[i].w;
        int fu = fd(u), fv = fd(v);
        if (fu != fv){
            fa[fu] = fv;
            ans += 1ll * w;
            p[++cnt] = in[i];
        }
    }
    sort(p + 1, p + cnt + 1);
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}
inline int read(){
    int s = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9'){
        s = s * 10 + c - '0';
        c = getchar();
    }
    return s * f;
}
