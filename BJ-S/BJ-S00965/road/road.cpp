#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e6 + 5;
struct Node{
    int u, v, w;
}edge[MAXN];
bool cmp(Node x, Node y){
    return x.w < y.w;
}
int father[10005], c[15], adj[15][10005];
bool use[MAXN];
int find(int u){
    if(father[u] == u)return u;
    return father[u] = find(father[u]);
}
void Merge(int u, int v){
    father[find(u)] = find(v);
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, nn, nw;
    cin >> n >> m >> k;
    nn = n;
    nw = m;
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
    }
    for(int i = 1; i <= k; i ++){
        cin >> c[i];
        for(int j = 1; j <= n; j ++){
            int v;
            cin >> v;
            adj[i][j] = v;
        }
    }
    sort(edge + 1, edge + 1 + m, cmp);
    int ans = 0;
    for(int i = 1; i <= n; i ++)father[i] = i;
    for(int i = 1; i <= m; i ++){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if(find(u) != find(v)){
            Merge(u, v);
            ans += w;
            use[i] = true;
        }
    }
    cout << ans << "\n";
    return 0;
}