#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int n, a[5][N];
bool f2, f3;

namespace sit1{
    int ans;

    void dfs(int x, int sum, int c1, int c2, int c3) {
        if (x > n) {
            ans = max(ans, sum);
            return;
        }
        if (c1 < n / 2)
            dfs(x + 1, sum + a[1][x], c1 + 1, c2, c3);
        if (c2 < n / 2)
            dfs(x + 1, sum + a[2][x], c1, c2 + 1, c3);
        if (c3 < n / 2)
            dfs(x + 1, sum + a[3][x], c1, c2, c3 + 1);
    }

    void solve() {
        ans = 0;
        dfs(1, 0, 0, 0, 0);
        cout << ans << '\n';
    }
}

namespace sit2{
    int ans;

    void solve() {
        sort(a[1] + 1, a[1] + n + 1, greater<int>());
        ans = 0;
        for (int i = 1; i <= n / 2; ++i)
            ans += a[1][i];
        cout << ans << '\n';
    }
}

namespace sit3{
    int ans;

    void solve() {
        sort(a[1] + 1, a[1] + n + 1, greater<int>());
        sort(a[2] + 1, a[2] + n + 1, greater<int>());
        ans = 0;
        for (int i = 1; i <= n / 2; ++i) {
            ans += a[1][i];
            ans += a[2][i];
        }
        cout << ans << '\n';
    }
}

void solve() {
    f2 = f3 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[1][i] >> a[2][i] >> a[3][i];
        if (a[2][i]) f2 = 1;
        if (a[3][i]) f3 = 1;  
    }
    if (n <= 10)
        sit1::solve();
    else if (!f2 && !f3)
        sit2::solve();
    else if (!f3)
        sit3::solve();
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}