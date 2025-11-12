#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10, M = 1e6 + 10;
struct node{
    ll u, v, w;
}e[M];
bool cmp(const node &x, const node &y){
    return x.w < y.w;
}
ll n, m, k, ct[15][N], c[15];
ll p[N], ans;
bool xzA = 1;
ll find(ll x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void kruskal(){
    sort(e+1, e+m+1, cmp);
    for(int i=1; i<=n; i++) p[i] = i;
    for(int i=1; i<=m; i++){
        ll u = find(e[i].u);
        ll v = find(e[i].v);
        if(u != v){
            ans += e[i].w;
            p[u] = p[v];
        }
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i=1; i<=m; i++){
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    }
    for(int i=1; i<=k; i++){
        scanf("%lld", &c[i]);
        if(c[i] != 0) xzA = 0;
        for(int j=1; j<=n; j++){
            scanf("%lld", &ct[i][j]);
            if(ct[i][j] != 0) xzA = 0;
        }
    }
    if(k == 0){
        kruskal();
        printf("%lld", ans);
        return 0;
    }
    if(xzA){
        printf("0");
        return 0;
    }
    return 0;
}
