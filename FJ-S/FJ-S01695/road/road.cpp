#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20;
int n, m, k, kp, cnt[11], nw, fa[N + 15];
int c[11];
struct edge{int x, y, w;}e[N], ex[11][N], ep[11][N * 11];
int find(int x){return x == fa[x] ? x : (fa[x] = find(fa[x]));}
long long ans, res = 1e18;
long long kkk(int n){
    ans = 0, kp = 1;
    for(int i = 1;i <= n + 10;++i)fa[i] = i;
    for(int i = 1;i <= cnt[nw];++i){
        int x = find(ep[nw][i].x), y = find(ep[nw][i].y);
        if(x != y){
            fa[y] = x;
            ++kp, ans += ep[nw][i].w;
            if(kp == n)return ans;
        }
    }
    return -1ll;
}
void kks(int n){
    ans = 0;kp = 1;
    for(int i = 1;i <= n;++i)fa[i] = i;
    for(int i = 1;i <= m;++i){
        int x = find(e[i].x), y = find(e[i].y);
        if(x != y)fa[y] = x, ep[0][++cnt[0]] = e[i], ++kp;
        if(kp == n)return;
    }
}
void dfs(int op, long long zp){
    if(op > k){
        ans = kkk(n + nw);
        if(ans != -1)res = min(ans + zp, res);
        return;
    }
    dfs(op + 1, zp);
    int s = 1, t = 1;
    cnt[nw + 1] = 0;
    while(s <= cnt[nw] && t <= n){
        if(ep[nw][s].w < ex[op][t].w)ep[nw + 1][++cnt[nw + 1]] = ep[nw][s],++s;
        else ep[nw + 1][++cnt[nw + 1]] = ex[op][t], ++t;
    }
    while(s <= cnt[nw])ep[nw + 1][++cnt[nw + 1]] = ep[nw][s],++s;
    while(t <= n)ep[nw + 1][++cnt[nw + 1]] = ex[op][t], ++t;
    ++nw;
    dfs(op + 1, zp + c[op]);
    --nw;
}
bool cmp(edge a, edge b){return a.w < b.w;}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1;i <= m;++i)scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
    sort(e + 1, e + m + 1, cmp), kks(n);
    for(int i = 1;i <= k;++i){
        scanf("%d", &c[i]);
        for(int j = 1;j <= n;++j)ex[i][j] = {n + i, j, 0}, scanf("%d", &ex[i][j].w);
        sort(ex[i] + 1, ex[i] + n + 1, cmp);
    }
    dfs(1, 0ll);
    printf("%lld", res);
    return 0;
}