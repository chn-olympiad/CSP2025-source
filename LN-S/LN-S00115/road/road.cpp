#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 11010, M = 2000010;

int n, m1, k, m;
struct Edge{
    int u, v;
    LL w;
    bool operator< (const Edge& B) const {
        return w < B.w;
    }
}e1[M], e[M];
int p[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
LL c[N];
LL ans = 0;

void kruskal1(){
    for(int i = 1; i <= n; i++) p[i] = i;
    sort(e1 + 1, e1 + m1 + 1);
    for(int i = 1; i <= m1; i++){
        int u = e1[i].u, v = e1[i].v;
        int fu = find(u), fv = find(v);
        if(fu != fv){
            p[fu] = fv;
            ans += e1[i].w;
            e[++m] = e1[i];
            if(m == n - 1) break;
        }
    }
}

bool ok[N];
LL kruskal(int mask){
    int cnt = n - 1;
    LL res = 0;
    for(int i = 0; i < k; i++)
        if((mask >> i) & 1)
            cnt++, res += c[i + 1], ok[i + 1] = 1;
        else ok[i + 1] = 0;
    for(int i = 1; i <= n + k; i++) p[i] = i;
    for(int i = 1; i <= m; i++){
        int u = e[i].u, v = e[i].v;
        if(u > n){
            if(ok[u - n] == 0) continue;
        }
        int fu = find(u), fv = find(v);
        if(fu != fv){
            p[fu] = fv;
            res += e[i].w;
            cnt--;
            if(cnt == 0) break;
        }
    }
    return res;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m1, &k);
    for(int i = 1; i <= m1; i++)
        scanf("%d%d%lld", &e1[i].u, &e1[i].v, &e1[i].w);
    kruskal1();
    for(int i = 1; i <= k; i++){
        scanf("%lld", &c[i]);
        for(int j = 1; j <= n; j++){
            LL tmp;
            scanf("%lld", &tmp);
            e[++m] = {i + n, j, tmp};
        }
    }
    sort(e + 1, e + m + 1);
    for(int i = 1; i < 1 << k; i++){
        ans = min(ans, kruskal(i));
    }
    printf("%lld\n", ans);
    /*for(int i = 1; i <= m; i++){
        printf("%d %d %lld\n", e[i].u, e[i].v, e[i].w);
    }*/
    return 0;
}
