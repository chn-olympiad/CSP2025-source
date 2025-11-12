#include <bits/stdc++.h>
#define llong long long
#define N 100005
#define M 1000006
using namespace std;

struct Edge{
    int u, v, w;
} a[M];

int n, m, k;

int fa[N];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

llong ans;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
    for(int i = 1; i <= m; ++i)
        scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
    sort(a+1, a+m+1, [&](Edge a, Edge b) -> bool{return a.w<b.w;});
    for(int i = 1; i <= m; ++i){
        int u = find(a[i].u), v = find(a[i].v), w = a[i].w;
        if(u == v) continue;
        fa[v] = u;
        ans += w;
    }
    printf("%lld", ans);
    return 0;
}
