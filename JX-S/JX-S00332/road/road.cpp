#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10, M = 2e6 + 10;
int n, m, k, cnt, f[N], c[N], flag[N], g[20][N];
long long res, ans = 1e18;
struct sb {int u, v, w;} a[M], b[M];
bool cmp(sb x, sb y) {return x.w < y.w;}
int find(int x) {
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
void fun(int num) {
    cnt = 0;
    for(int i = 1; i <= n + k + 2; i++) f[i] = i;
    for(int i = 1; i <= k; i++) if(flag[i]) for(int j = 1; j <= n; j++) b[++cnt] = {n + i, j, g[i][j]};
    sort(b + 1, b + cnt + 1, cmp);
    int tmp = 0, pos = 1;
    long long sum = 0;
    for(int i = 1; i <= m; i++) {
        while(a[i].w > b[pos].w && pos <= cnt) {
            int u = b[pos].u, v = b[pos].v, w = b[pos].w;
            if(find(u) == find(v)) {
                pos++;
                continue;
            }
            tmp++;
            sum += w;
            if(sum + res >= ans) return ;
            f[find(u)] = find(v);
            if(tmp == n + num - 1) break;
            pos++;
        }
        if(tmp == n + num - 1) break;
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if(find(u) == find(v)) continue;
        tmp++;
        sum += w;
        if(sum + res >= ans) return ;
        f[find(u)] = find(v);
        if(tmp == n + num - 1) break;
    }
    tmp = 0;
    for(int i = 1; i <= n + k; i++) if(f[i] == i) tmp++;
    if(tmp - k + num < 2) ans = min(ans, res + sum);
    return ;
}
void dfs(int pos, int num) {
    if(pos == k + 1 && res < ans) {
        fun(num);
        return ;
    }
    flag[pos] = 1;
    res += c[pos];
    dfs(pos + 1, num + 1);
    flag[pos] = 0;
    res -= c[pos];
    dfs(pos + 1, num);
    return ;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    sort(a + 1, a + 1 + m, cmp);
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> g[i][j];
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}
