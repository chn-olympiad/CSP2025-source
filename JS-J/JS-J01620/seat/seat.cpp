#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[150];

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int s = a[1];
    sort(a + 1, a + 1 + n * m);
    int rk = n * m + 1 - (lower_bound(a + 1, a + 1 + n * m, s) - a);
    //cout << rk << '\n';
    int col = rk / n + (rk % n != 0);
    int row;
    if(col % 2) {
        row = (rk - 1) % n + 1;
    } else {
        row = col * n + 1 - rk;
    }
    cout << col << " " << row;
    return 0;
}
