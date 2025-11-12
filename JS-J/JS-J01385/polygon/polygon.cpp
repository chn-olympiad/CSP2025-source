#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;

const long long mod = 998244353;
int a[5010];
int vis[5010];

bool check(int cnt) {
    if (cnt < 3) return 0;
    long long sum = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            sum += a[i];
            mx = max(mx, a[i]);
        }
    }
    if (sum > 2 * mx) {
        return 1;
    }
    return 0;
}

void dfs(int now, int cnt) {
    if (now > n) {
        if (check(cnt)) {
            ans++;
            ans %= mod;
        }
        return;
    }
    vis[now] = 1;
    dfs(now + 1, cnt + 1);
    vis[now] = 0;
    dfs(now + 1, cnt);
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << ans % mod;

    return 0;
}
