#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL P = 998244353LL;
int a[5001], n;
LL ans, mx, sum, old_mx, cnt;

void dfs(int u) {
    if (u > n)
        return;
    old_mx = mx;
    mx = max((LL)a[u], mx);
    sum += a[u];
    cnt++;
    if (sum > 2 * mx && cnt >= 3)   ans++, ans %= P;
    for (int i = u + 1; i <= n; i++)
        dfs(i);
    sum -= a[u];
    mx = old_mx;
    cnt--;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        dfs(i);
    printf("%lld", ans);
}
