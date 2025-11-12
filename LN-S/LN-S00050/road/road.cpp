#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 15, M = 1e6 + 15 + 1e5 + 15;
ll n, m, k, c[15], a[15][N], fa[N];
struct edge{
    ll u, v, w;
}e[M];
bool cmp(edge a, edge b){
    return a.w < b.w;
}
void init(){
    for(int i = 1; i <= n + k; i++)
        fa[i] = i;
    return;
}
inline ll find(ll x){
    if(fa[x] == x){
        return fa[x];
    }
    return fa[x] = find(fa[x]);
}
inline void read(ll& x){
    ll s = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        f = (ch == '-' ? -1 : 1);
        ch = getchar();
    }
    while(isdigit(ch)){
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    x = s * f;
}
inline void write(ll x){
    if(x < 0)
        x = -x, putchar('-');
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
ll kruskal(){
    ll res = 0;
    for(int i = 1; i < n; i++){
        ll u = e[i].u, v = e[i].v, w = e[i].w;
        ll fu = find(u), fv = find(v);
        if(fu == fv)
            continue;
        res += w;
        fa[fu] = fv;
    }
    return res;
}
ll ex_kruskal(ll sitcode){
    init();
    bool isbuild[15];
    for(int i = 0; i < 15; i++)
            isbuild[i] = false;
    ll cntbuild = 0, res;
    for(int i = 0;  i < k; i++){
        isbuild[i + 1] = (sitcode >> i) & 1;
        cntbuild += isbuild[i + 1];
    }
    printf("cntbuild%lld\n", cntbuild);
    for(int i = 1; i <= n + cntbuild - 1; i++){
        ll u = e[i].u, v = e[i].v;
        if(u <= n && v <= n){
            ll fu = find(u), fv = find(v);
            if(fu == fv)
                continue;
            fa[fu] = fv;
            res += e[i].w;
        }else if(u > n){
            if(isbuild[u - n] == false)
                continue;
            if(v > n){
                if(isbuild[v - n] == false)
                    continue;
            }
            ll fu = find(u), fv = find(fv);
            if(fu == fv)
                continue;
            fa[fu] = fv;
            res += e[i].w;
        }else if(v > n){
            if(isbuild[v - n] == false)
                continue;
            if(u > n){
                if(isbuild[u - n] == false)
                    continue;
            }
            ll fu = find(u), fv = find(v);
            if(fu == fv)
                continue;
            fa[fu] = fv;
            res += e[i].w;
        }else{
            ll fu = find(u), fv = find(v);
            if(fu == fv)
                continue;
            fa[fu] = fv;
            res += e[i].w;
        }
    }
    for(int i = 1; i <= k; i++)
        res += c[i] * isbuild[i];
    return res;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n), read(m), read(k);
    init();
    for(int i = 1; i <= m; i++)
        read(e[i].u), read(e[i].v), read(e[i].w);
    bool f = true;
    for(int i = 1; i <= k; i++)
        read(c[i]), f &= (c[i] == 0);
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            read(a[i][j]), f &= (a[i][j] == 0);
        }
    }
    if(k == 0){
        sort(e + 1, e + 1 + n, cmp);
        ll ans = kruskal();
        write(ans);
        putchar('\n');
        return 0;
    }
    if(f){
        printf("0\n");
        return 0;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            ++m;
            int idx = (int)m;
            e[m] = (edge){n + i, j, a[i][j]};
        }
    }
    sort(e + 1, e + 1 + m, cmp);
    ll sit = (1 << k) - 1, mi = LONG_LONG_MAX;
    printf("%lld\n", sit);
    for(int i = 0; i <= sit; i++){
        printf("%lld ", i);
        mi = min(mi, ex_kruskal(i));
    }
    printf("%lld\n", mi);
    return 0;
}
