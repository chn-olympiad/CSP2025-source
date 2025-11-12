#include <bits/stdc++.h>//48Pts
using namespace std;
#define int long long
#define rint register int
#define inline static inline
void pre() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    return ;
}
int result = 1e18;
int n, m, k;
int c[25];
int ans[25];
int fa[20005];
int cu[25][20005];
struct node {
    int from, to, val;
}g[2000005], e[2000005];
bool cmp(node x, node y) {
    return x.val < y.val;
}
namespace KRU {
    int find(int x) {
        return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
    }
    void Union(int x, int y) {
        x = find(fa[x]), y = find(fa[y]);
        fa[x] = y;
        return ;
    }
    inline int kruscal(int cur) {
        int res = 0;
        for(int i = 1; i <= m + n * cur; i ++) {
            int x = g[i].from, y = g[i].to;
            if(find(x) == find(y))  continue;
            Union(x, y);
            res += g[i].val;
        }
        return res;
    }
    inline int kruscall(int cur) {
        int res = 0;
        for(int i = 1; i <= m + n * cur; i ++) {
            int x = e[i].from, y = e[i].to;
            if(find(x) == find(y))  continue;
            Union(x, y);
            res += e[i].val;
        }
        return res;
    }
}
using namespace KRU;
inline int calc(int cur) {
    for(int i = 1; i <= m; i ++)
        e[i].from = g[i].from, e[i].to = g[i].to, e[i].val = g[i].val;
    for(int i = 1; i <= cur; i ++) {
        for(int j = 1; j <= n; j ++)
            e[m + i * n + j].from = j, e[m + i * n + j].to = ans[i], e[m + i * n + j].val = cu[ans[i]][j];
    }
    for(int i = 1; i <= m + cur * n; i ++)
        if(e[i].val == 0)   e[i].val = 1e18;
    sort(e + 1, e + 1 + m + cur * n, cmp);
    return kruscall(cur);
}
inline void dfs(int pre, int last, int cur) {
    ans[cur] = pre;
    if(pre == k) {
        for(int i=  1; i <= n + k; i ++)
            fa[i] = i;
        int sum = calc(cur);
        cout << sum << " ";
        for(int i = 1; i <= cur; i ++)
            sum += c[ans[i]];
        cout << sum << "\n";
        result = min(result, sum);
        return ;
    }
    for(int i = pre + 1; i <= n; i ++)
        dfs(i, pre, cur + 1);
    return ;
}
signed main() {
    pre();
    cin >> n >> m >> k;
    for(rint i = 1; i <= n + k; i ++)
        fa[i] = i;
    for(rint i = 1; i <= m; i ++)
        cin >> g[i].from >> g[i].to >> g[i].val;
    bool flag = false;
    for(int i = 1; i <= k; i ++) {
        cin >> c[i];
        if(c[i])    flag = true;
        bool zero = false;
        for(int j = 1; j <= n; j ++) {
            cin >> g[m + i * n + j].val;
            cu[i][j] = g[m + i * n + j].val;
            g[m + i * n + j].from = n + i;
            g[m + i * n + j].to = j;
            if(g[m + i * n + j].val == 0)   zero = true;
        }
        if(!zero) flag = true;
    }
    if(!flag || k == 0) {
        sort(g + 1, g + 1 + m + k * n, cmp);
        cout << kruscal(k);
        return 0;
    }
    dfs(0, 0, 0);
    cout << result;
    return 0;
}