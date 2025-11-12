#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, m, k, a[20][10005], fa[100005];
inline int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
struct Edge{
    int u, v, w;
    int guishu;
}e[1200005], g[1200005]; int tot = 0;
inline bool cmp(Edge x, Edge y){
    return x.w < y.w;
}
namespace A{
    inline void Solve(){
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                e[++tot] = {n + i, j, a[i][j], 0};
            }
        }
        sort(e + 1, e + 1 + tot, cmp);
        for(int i = 1; i <= n + k; i++) fa[i] = i;
        int cnt = 0, sum = 0;
        for(int i = 1; i <= tot; i++){
            if(cnt >= n + k - 1) break;
            int u = find(e[i].u), v = find(e[i].v);
            if(u != v){
                cnt++;
                sum += e[i].w;
                fa[u] = v;
            }
        }
        cout << sum << '\n';
        return;
    }
}
namespace Baoli{
    bool choose[20];
    int ans;
    inline int Kruskal(int zong){
        for(int i = 1; i <= tot; i++) g[i] = e[i];
        sort(g + 1, g + 1 + tot, cmp);
        for(int i = 1; i <= zong; i++) fa[i] = i;
        int cnt = 0, sum = 0;
        for(int i = 1; i <= tot; i++){
            if(cnt >= zong - 1) break;
            int u = find(g[i].u), v = find(g[i].v);
            if(u != v){
                cnt++;
                sum += g[i].w;
                fa[u] = v;
            }
        }
        return sum;
    }
    inline void check(){
        tot = m;
        int res = 0, chosed = 0;
        for(int i = 1; i <= k; i++){
            if(choose[i]){
                chosed++;
                res += a[i][0];
                for(int j = 1; j <= n; j++){
                    e[++tot] = {n + i, j, a[i][j], 0};
                }
            }
        }
        res += Kruskal(n + chosed);
        ans = min(ans, res);
        return;
    }
    inline void dfs(int x){
        if(x > k){
            check();
            return;
        }
        choose[x] = true;
        dfs(x + 1);
        choose[x] = false;
        dfs(x + 1);
        return;
    }
    inline void Solve(){
        ans = 1e18;
        dfs(1);
        cout << ans << '\n';
        return;
    }
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1; i <= m; i++){
        int u = read(), v = read(), w = read();
        e[++tot] = {u, v, w, 0};
    }
    bool A = true;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            a[i][j] = read();
            if(j == 0 && a[i][j] != 0) A = false;
        }
    }
    if(A){
        A::Solve();
        // cout << 'A' << endl;
        return 0;
    }
    Baoli::Solve();
    return 0;
}