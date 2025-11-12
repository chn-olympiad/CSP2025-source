#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
}e[1000010];
int c[15],a[15][10010],fa[10010];
int check(int u){
    if(fa[u] == u) return u;
    return check(fa[u]);
}
int ans = 0;
void kruskal(){
    for(auto noww : e){
        int t_u = noww.u,t_v = noww.v;
        if(check(t_u) == check(t_v)) continue;
        fa[check(t_v)] = t_u;
        ans += noww.w;
    }
}
bool cmp(edge x,edge y){
    return x.w < y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    sort(e+1,e+m+1,cmp);
    kruskal();
    if(k == 0) cout << ans;
    else cout << ans - k * n;
    return 0;
}
