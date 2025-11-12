#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int MAXN = 1e4 + 15, MAXM = 1e6 + 5, MAXK = 15;
int read(){
    int res = 0;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar());
    for (; c >= '0' && c <= '9'; c = getchar()){
        res = (res << 1) + (res << 3) + (c ^ 48);
    }
    return res;
}
int fa[MAXN];
int n, m, k;
void init(){
    for (int i = 1; i <= n + k; i++){
        fa[i] = i;
    }
}
int getFather(int x){
    if (fa[x] == x){
        return x;
    }
    return fa[x] = getFather(fa[x]);
}
void merge(int x, int y){
    x = getFather(x), y = getFather(y);
    fa[y] = x;
}
struct Edge{
    int u, v, w;
    bool operator < (const Edge E) const{
        return w < E.w;
    }
}e[MAXM], a[MAXK][MAXN], b[MAXK][MAXN];
int c[MAXK];
ll ans = 1e18;
void dfs(int lst, ll cost, int dep){
    if (lst == k){
        return;
    }
    for (int x = lst + 1; x <= k; x++){
        ll now = cost + c[x];
        init();
        int tot = 0;
        for (int i = 1, j = 1; i < n + dep; i++){
            while (j <= n && a[x][j].w < b[dep][i].w){
                if (getFather(a[x][j].u) != getFather(a[x][j].v)){
                    merge(a[x][j].u, a[x][j].v);
                    now += a[x][j].w;
                    b[dep + 1][++tot] = a[x][j];
                }
                j++;
            }
            if (getFather(b[dep][i].u) != getFather(b[dep][i].v)){
                merge(b[dep][i].u, b[dep][i].v);
                now += b[dep][i].w;
                b[dep + 1][++tot] = b[dep][i];
            }
        }
        ans = min(ans, now);
        dfs(x, cost + c[x], dep + 1);
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++){
        e[i].u = read(), e[i].v = read(), e[i].w = read();
    }
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        for (int j = 1; j <= n; j++){
            a[i][j].u = n + i;
            a[i][j].v = j;
            a[i][j].w = read();
        }
        sort(a[i] + 1, a[i] + n + 1);
    }
    sort(e + 1, e + m + 1);
    init();
    ll now = 0, tot = 0;
    for (int i = 1; i <= m; i++){
        if (getFather(e[i].u) != getFather(e[i].v)){
            merge(e[i].u, e[i].v);
            now += e[i].w;
            b[0][++tot] = e[i];
        }
    }
    ans = now;
    dfs(0, 0, 0);
    cout << ans << '\n';
    return 0;
}