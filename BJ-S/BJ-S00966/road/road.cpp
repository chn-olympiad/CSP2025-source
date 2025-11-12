#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4 + 15;
const int maxm = 1e6 + 5;
struct navi{
    int u, v;
    ll w;
}edge[maxm];
int tot, ufs[maxn];
void add(int u, int v, ll w){
    edge[++tot].u = u;
    edge[tot].v = v;
    edge[tot].w = w;
}
int fnd(int x){
    if(ufs[x] == x) return x;
    return ufs[x] = fnd(ufs[x]);
}
void mrg(int x, int y){
    ufs[fnd(x)] = ufs[fnd(y)];
}
bool cmp(navi a, navi b){
    return a.w < b.w;
}
int n, m, k;
int kruskal(){
    ll ans = 0;
    for(int i = 1; i <= m + n * k; i++){
        if(fnd(edge[i].u) == fnd(edge[i].v)){
            continue;
        }
        if(edge[i].u > n || edge[i].v > n){
            mrg(edge[i].u, edge[i].v);
            continue;
        }
        ans += edge[i].w;
        mrg(edge[i].u, edge[i].v);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for(int i = 1; i <= n; i++) ufs[i] = i;
    sort(edge + 1, edge + 1 + m, cmp);
    if(k == 0){
        cout << kruskal();
        return 0;
    }
    else{
        for(int i = 1, pr; i <= k; i++){
            cin >> pr;
            for(int v = 1, w; v <= n; v++){
                cin >> w;
                add(v, i + n, w + pr), add(i + n, v, pr);
            }
        }
    }
    sort(edge + 1, edge + 1 + m + n * k, cmp);
    cout << kruskal();
    return 0;
}
