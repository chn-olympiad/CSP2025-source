#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
struct edge{
    long long u, v, w;
    bool operator < (const edge &A)const{
        return w < A.w;
    }
} g[2000010], e[2000010];
long long n, m, k, fa[2000010], vis[2000010], ans = inf, c[2000010], d[20][10010];
long long find(long long x){ return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(long long x, long long y){ x = find(x), y = find(y); fa[x] = y; }
long long kruskal(long long x, long long y, long long z){
    long long res = z, cnt = 0;
    for(long long i = 1; i <= y; i++){
        long long u = g[i].u, v = g[i].v;
        if(res + g[i].w >= ans) return inf;
        if(find(u) == find(v)) continue;
        merge(u, v);
        res += g[i].w;
        cnt += 2 - vis[u] - vis[v];
        vis[u] = vis[v] = 1;
        if(cnt == x) return res;
    }
    return inf;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(long long i = 1; i <= m; i++){
        long long x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        g[i] = e[i] = edge{x, y, z};
    }
    sort(g+1, g+m+1);
    int flag = 1;
    for(long long i = 1; i <= k; i++){
        scanf("%lld", &c[i]);
        if(c[i]) flag = 0;
        for(long long j = 1; j <= n; j++){
            scanf("%lld", &d[i][j]);
        }
    }
    if(flag){
        long long _ = (1 << k) - 1;
        long long res = 0, cnt = 0;
        for(long long i = 1; i <= n+k; i++) fa[i] = i, vis[i] = 0;
        for(long long i = 1; i <= k; i++){
            if(_ & (1 << (i-1))){
                res += c[i], cnt++;
                for(long long j = 1; j <= n; j++){
                    e[m+(cnt-1)*n+j] = edge{n+i, j, d[i][j]};
                }
            }
        }
        for(long long i = 1; i <= m+cnt*n; i++){
            g[i] = e[i];
        }
        sort(g+1, g+m+cnt*n+1);
        ans = min(ans, kruskal(n+cnt, m+cnt*n, res));
    }
    for(long long i = 1; i <= n; i++) fa[i] = i;
    ans = kruskal(n, m, 0);
    for(long long _ = 1; _ < (1 << k); _++){
        long long res = 0, cnt = 0;
        for(long long i = 1; i <= n+k; i++) fa[i] = i, vis[i] = 0;
        for(long long i = 1; i <= k; i++){
            if(_ & (1 << (i-1))){
                res += c[i], cnt++;
                for(long long j = 1; j <= n; j++){
                    e[m+(cnt-1)*n+j] = edge{n+i, j, d[i][j]};
                }
            }
        }
        for(long long i = 1; i <= m+cnt*n; i++){
            g[i] = e[i];
        }
        sort(g+1, g+m+cnt*n+1);
        ans = min(ans, kruskal(n+cnt, m+cnt*n, res));
    }
    printf("%lld", ans);
    return 0;
}
/*
风把我不想知道的事情告诉我
河把我不想忘记的故事也带走
我摘下我的翅膀 它变成白鸟
白鸟我的白鸟 逆着风去吧
飞过河滩
挥一挥一去不回还
一去不回还
风起水起难靠岸
白鸟白鸟不要回头望
你要替我飞去那地方
一去那地方
那是你我共同故乡
抓住和抓不住的照片 哪张更美
去过和没去过的地方 哪里更远
白鸟我的白鸟
你要飞得更高不要回来
若还想与我相见
就来我的梦里边
白鸟过河滩
挥一挥一去不回还
一去不回还
风起水起难靠岸
白鸟白鸟不要回头望
你要替我飞去那地方
一去那地方
那是你我共同故乡
别回来
我将终究顺流入大海
顺流入大海
海不问我从何处来
长风长风飘在山海间
白鸟白鸟展翅入苍天
一去入苍天
苍天远比海更远
一去入苍天
苍天远在海对面
*/