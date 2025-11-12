#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m, k;
struct Node{
    int u, v, w;
}b[10000005];
int f[1015], xz[15];
int c[15], a[15][1005], fc[1005][15], ans = 1e18, cur;
bool cmp(Node x, Node y) {
    return x.w < y.w;
}
int find(int x) {
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}
void add(int x, int y) {
    f[find(x)] = find(y);
}
void dfs(int step) {
    if(step > k) {
        int sum = 0;
        for (int i = 1; i <= k; ++i) {
            if(xz[i + n]) sum += c[i];
        }
        for (int i = 1; i <= n + k; ++i) f[i] = i;
        for (int i = 1; i <= cur; ++i) {
            if(!xz[b[i].u] || !xz[b[i].v]) continue;
            if(find(b[i].u) != find(b[i].v)) {
                sum += b[i].w;
                add(b[i].u, b[i].v);
            }
        }
        ans = min(ans, sum);
        return;
    }
    xz[step + n] = 1;
    dfs(step + 1);
    xz[step + n] = 0;
    dfs(step + 1);
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n + k; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i) xz[i] = 1;
    for (int i = 1; i <= m; ++i) {cin >> b[i].u >> b[i].v >> b[i].w;};
    int flag = 1;
    if(k == 0) {
        sort(b + 1, b + m + 1, cmp);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            if(find(b[i].u) != find(b[i].v)) {
                add(b[i].u, b[i].v);
                ans += b[i].w;
            }
        }
        cout << ans;
        return 0;
    }
    cur = m;
    for (int j = 1; j <= k; ++j) {
        cin >> c[j];
        for (int k1 = 1; k1 <= n; ++k1) {
            cin >> a[j][k1];
            b[++cur].u = n + j;
            b[cur].v = k1;
            b[cur].w = a[j][k1];
        }
    }
    sort(b + 1, b + cur + 1, cmp);
    dfs(1);
    cout << ans;
    return 0;
}