#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const int mod = 998244353;

int n;
int a[N];
bool vis[N];
int ans = 0;


void dfs (int dep, int cnt, int tot, int mx, int sum) {
    ans = max(ans, cnt);
    if (dep > n) {
        ans = max(ans, cnt);
        return ;
    }

    dfs (dep + 1, cnt + 1, tot, mx, sum);
    for (int i = 1; i <= n; i ++ ) {
        if (!vis[i]) {
            vis[i] = 1;
            // dfs (dep + 1, cnt, tot + 1, max(mx, a[i]), sum + a[i]);
            if (tot >= 2 && 2 * max(mx, a[i]) < sum + a[i]) dfs (dep + 1, cnt + 1, tot + 1, max(mx, a[i]), sum + a[i]);
            else dfs (dep + 1, cnt, tot + 1, max(mx, a[i]), sum + a[i]);
            vis[i] = 0;
        }
    }
}


void dfs1 (int dep, int cnt, int sum, int mx) {
    if (dep > n) {
        if (cnt >= 3 && sum > 2 * mx) {
            ans ++ ;
            ans %= mod;
        }
        return ;
    }
    dfs1 (dep + 1, cnt + 1, sum, mx);
    for (int i = 1; i <= n; i ++ ) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs1 (dep + 1, cnt + 1, sum + a[i], max(mx, a[i]));
            vis[i] = 0;
        }
    }
}

int main () {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &a[i]);
    }
    sort (a + 1, a + 1 + n);

    if (n <= 3) {
        int mx = -1, sum = 0;
        for (int i = 1; i <= n; i ++ ) {
            mx = max(mx, a[i]);
            sum += a[i];
        }
        if (sum > 2 * mx) {
            printf("1\n");
        } else printf("0\n");
        return 0;
    }

    dfs(1, 0, 0, 0, 0);
    //dfs1(1, 0, 0, 0);
    cout << (ans %= mod);
    return 0;
}
