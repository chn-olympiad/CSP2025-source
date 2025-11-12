#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int M = 9e7 + 5;
struct Node{
    int u, v, w;
}e[M];
int n, m, k;
int fa[N + 10];
bool cotry[15];
long long res;
int find_fa(int x){
    if(fa[x] == x){
        return x;
    }else{
        return fa[x] = find_fa(fa[x]);
    }
}
void mergef(int x, int y){
    fa[find_fa(y)] = find_fa(x);
}
bool cmp(Node x, Node y){
    return x.w < y.w;
}
void kluskal(){
    sort(e + 1, e + 1 + m + k * n, cmp);
    for(int i = 1; i <= m + k; i ++){
        int u = e[i].u;
        int v = e[i].v;
        if(find_fa(u) != find_fa(v)){
            mergef(u, v);
            res += e[i].w;
        }
    }
}
void solved(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i] = {u, v, w};
        fa[i] = i;
    }
    for(int i = 1; i <= k; i++){
        int c, a;
        scanf("%d", &c);
        for(int j = 1; j <= n; j++){
            scanf("%d", &a);
            e[(i - 1) * n + m + j] = {i + n, j, a};
        }
    }
    kluskal();
    cout << res;
}
int main(){
    int t = 1;
    while(t --){
        solved();
    }
}
