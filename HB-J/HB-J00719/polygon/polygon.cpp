// polygon.cpp
#include <iostream>
using namespace std;

#define MOD 998244353
const int N = 5000 + 5 * 512;
int n, a[N], k, ans;

void dfs(int x, int y, int sum, int maxn) {
    if (y == k) {
        if (sum > maxn * 2) ans = (ans + 1) % MOD;
        return;
    }
    if (n - x + 1 < k - y) return;
    dfs(x + 1, y + 1, sum + a[x], a[x] > maxn ? a[x] : maxn);
    dfs(x + 1, y, sum, maxn);
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (k = 3; k <= n; k++)
        dfs(1, 0, 0, 0);
    cout << ans << '\n';
    return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/