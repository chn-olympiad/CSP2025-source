#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 5e3 + 10;
int n;
int a[N];
int fs;

int A(int x, int y) {
    int ans = 1;
    for (int i = y, j = 1; j <= x; j++, i--) ans *= i;
    return ans;
}

void dfs(int x, int sum, int mx) {
    if (x > n) {
        if (sum > mx * 2) (fs += 1) %= mod;
        return;
    }

    dfs(x + 1, sum, mx);
    dfs(x + 1, sum + a[x], max(mx, a[x]));
}

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if (mx == 1) {
        int ans = 0;
        for (int i = 3; i <= n; i++) (ans += A(i, n) / A(i, i)) %= mod;
        cout << ans % mod;

        return 0;
    }

    dfs(1, 0, 0);
    cout << fs;

    return 0;
}