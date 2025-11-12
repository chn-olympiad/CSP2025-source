#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
int a[N];
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int x = a[1];
    sort(a + 1, a + n * m + 1);
    int cnt = 0;
    for (int i = n * m; i >= 1; i--) {
        cnt++;
        if (a[i] == x) break;
    }
    int l = ceil(1.0 * cnt / n);
    int h;
    if (l % 2) {
        h = cnt - (l - 1) * n;
    }
    else {
        h = n - (cnt - (l - 1) * n) + 1;
    }
    cout << l << ' ' << h << '\n';
    return 0;
}
