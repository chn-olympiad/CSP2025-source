#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
const int M = 2e6 + 10;
struct Edge{
    int u, v, w;
}edge[N];
int f[N], c[N], cnt;
bool flag[N];
bool cmp(Edge x, Edge y){
    return x.w < y.w;
}
void init(){
    for(int i = 1;i < N;i++){
        f[i] = i;
    }
}
int find(int x){
    if(f[x] == x){
        return x;
    }
    return f[x] = find(f[x]);
}
void unite(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu != fv){
        f[fu] = fv;
        cnt--;
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    int tot = 1;
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            int w;
            cin >> w;
            edge[tot + m].u = i + n;
            edge[tot + m].v = j;
            edge[tot + m].w = w + c[i];
            tot++;
        }
    }
    init();
    int ans = 0;
    cnt = n;
    sort(edge + 1, edge + m + tot + 1, cmp);
    int i = 1;
    while(cnt > 1){
        if(edge[i].u > n && flag[edge[i].u - n]){
            ans -= c[edge[i].u - n];
        }
        if(edge[i].u > n && flag[edge[i].u - n] == 0){
            flag[edge[i].u - n] = 1;
            cnt++;
        }
        unite(edge[i].u, edge[i].v);
        ans += edge[i].w;
        i++;
    }
    cout << ans << '\n';
    return 0;
}
