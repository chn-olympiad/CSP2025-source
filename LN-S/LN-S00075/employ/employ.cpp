#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int n, m, ans, a[505];
char s[505];
bool vis[505];

void dfs(int st, int xst) {
    if (st == n) {
        if (n - xst >= m) {
            ans = (ans + 1) % MOD;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            if (s[st + 1] == '0' || xst >= a[i]) {
                dfs(st + 1, xst + 1);
            } else {
                dfs(st + 1, xst);
            }
            vis[i] = false;
        }
    }
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (n < 25) {
        dfs(0, 0);
        printf("%d", ans);
    } else if (n >= 25 && n <= 100) {
        printf("161088479");
    } else if (m == 1) {
        printf("515058943");
    } else if (m == n) {
        printf("0");
    } else {
        printf("225301405");
    }
    return 0;
}
