#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
const int N = 505;
bool vis[N];
int n, m, ans, s[N], c[N];
void dfs (int k, int cnt, int sum) {
    if (sum + n - k + 1 < m) return;
    if (k == n + 1) {
        ans += sum >= m;
        return;
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = true;
        if (!s[k]) dfs(k + 1, cnt + 1, sum);
        else if (c[i] <= cnt) dfs(k + 1, cnt + 1, sum);
        else dfs(k + 1, cnt, sum + 1);
        vis[i] = false;
    }
}
int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%1d", &s[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    dfs(1, 0, 0);
    printf("%d", ans);
    return 0;
}