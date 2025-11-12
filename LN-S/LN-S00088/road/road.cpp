#include<bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int n, m, k, tot, head[N], fa[N], mi[15], hd[N], flag = 0;
long long ans = 1e18;
struct edge{ int nxt, from, to, w; }e[N], g[N];
struct node{ int c, a[N]; }t[15];
void addedge1(int u, int v, int w){
    e[++tot] = {head[u], u, v, w };
    head[u] = tot;
}
void addedge2(int u, int v, int w){
    g[++tot] = {hd[u], u, v, w };
    hd[u] = tot;
}
bool cmp1(edge x, edge y){ return x.w < y.w; }
bool cmp2(node x, node y){ return x.c < y.c; }
int find_(int x){ return fa[x]==x ? x : fa[x] = find_(fa[x]); }
long long kruskal(){
    long long ans = 0;
    sort(g+1, g+tot+1, cmp1);
    for(int i = 1; i <= tot; i++){
        int u = g[i].from, v = g[i].to;
        if(find_(u) != find_(v)){
            fa[find_(u)] = find_(v);
            ans += g[i].w;
        }
    }
    return ans;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    mi[0] = 1;
    for(int i = 1; i <= k+1; i++) mi[i] = mi[i-1] * 2;
    for(int i = 1; i <= m; i++){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        addedge1(u, v, w); addedge1(v, u, w);
    }
    for(int i = 1; i <= k; i++){
        scanf("%d", &t[i].c);
        if(t[i].c) flag = 1;
        for(int j = 1; j <= n; j++){
            scanf("%d", &t[i].a[j]);
        }
    }
    if(flag){
        for(int i = 0; i <= mi[k+1]-1; i++){
            long long res = 0;
            tot = 2*m;
            for(int i = 1; i <= n+k; i++) fa[i] = i;
            for(int j = 1; j <= 2*m; j++) g[j] = e[j];
            for(int j = 1; j <= k; j++){
                if((1<<(j-1)) & i){
                    res += t[j].c;
                    for(int q = 1; q <= n; q++){
                        addedge2(j+n, q, t[j].a[q]); addedge2(q, j+n, t[j].a[q]);
                    }
                }
            }
            ans = min(ans, kruskal() + res);
        }
        printf("%lld", ans);
    }else{
        for(int i = 1; i <= tot; i++) g[i] = e[i];
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                addedge2(i+n, j, t[i].a[j]);
                addedge2(j, i+n, t[i].a[j]);
            }
        }
        for(int i = 1; i <= n+k; i++) fa[i] = i;
        printf("%lld", kruskal());
    }
return 0;
}
