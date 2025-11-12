#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, a[10005];
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    int R = a[1];
    sort(a + 1, a + (n * m) + 1, greater<int>());
    int b = lower_bound(a + 1, a + (n * m) + 1, R, greater<int>()) - a;
    int c = ceil(b * 1.0 / n);
    int r;
    if (c % 2 == 1) r = (b % n ? b % n : n);
    else r = m - (b % n ? b % n : n) + 1;
    cout << c << ' ' << r << endl;
    return 0;
}
