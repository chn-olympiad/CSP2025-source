#include <bits/stdc++.h>
using namespace std;
#define int long long
void read(int &x) {
    x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch <= '9' && ch >= '0'){
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
}
const int maxn = 1e4 + 20, maxm = 1e6 + 5;
int n, m, k, root[maxn], c[maxn];
vector<int> a[maxn];
int fid(int x){
    return x == root[x] ? x : root[x] = fid(root[x]);
}
void init(){
    for(int i = 1; i <= n + k; i ++) root[i] = i;
}
struct Edge{
    int u, v, w;
    Edge(int a = 0, int b = 0, int c = 0): u(a), v(b), w(c){}
    friend bool operator < (Edge e1, Edge e2){
        return e1.w < e2.w;
    }
} edge[maxm << 1];
bool Merge(int u, int v){
    int fu = fid(u), fv = fid(v);
    if(fu == fv) return false;
    root[fu] = fv;
    return true;
}
int siz[15], dis[15];
void solve1(){
    int cnt = m;
    for(int i = 1; i <= k; i ++){
        for(int j = 0, w; j < n; j ++){
            w = a[i][j];
            edge[++ cnt] = Edge(i + n, j + 1, w);
        }
    }
    int ans = 0;
    sort(edge + 1, edge + cnt + 1);
    for(int i = 1, u, v, w; i <= cnt; i ++){
        u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if(Merge(u, v)) ans += w;
        if(u < v) swap(u, v);
        if(u > n){
            siz[u - n] ++;
            dis[u - n] += w;
        }
    }
    for(int i = 1; i <= k; i ++) if(siz[i] == 1) ans -= dis[i];
    printf("%lld\n", ans);
}
main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n), read(m), read(k);
    //printf("%lld --\n", n);
    init();
    //printf("%lld %lld\n", n, k);
    for(int i = 1, u, v, w; i <= m; i ++){
        read(u), read(v), read(w);
        edge[i] =  Edge(u, v, w);
    }
    if(!k){
        int ans = 0;
        sort(edge + 1, edge + m + 1);
        for(int i = 1, u, v, w; i <= m; i ++) {
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if(Merge(u, v)) ans += w;
        }
        printf("%lld\n", ans);
        return 0;
    }
    bool flag = true;
    for(int i = 1; i <= k; i ++){
        read(c[i]);
        if(c[i]) flag = false;
        for(int j = 1, x; j <= n; j ++) {
            read(x);
            a[i].push_back(x);
        }
    }
    if(flag == true){
        solve1();
        return 0;
    }
    return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
