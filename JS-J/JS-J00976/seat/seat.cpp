#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[105];
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int x = a[1], pos = -1;
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == x) {
            pos = i;
        }
    }
//    cout << pos << "\n";
    int lie = (pos + n - 1) / n, hang;
    int lft = pos - (lie - 1) * n;
    if (!(lie & 1)) {
        hang = n - lft + 1;
    } else {
        hang = lft;
    }
    cout << lie << " " << hang << "\n";
    return 0;
}
