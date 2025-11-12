#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> v(n * m + 1);
    for (int i = 1; i <= n * m; i++) {
        cin >> v[i];
    }
    int x = v[1];
    //cout << x << endl;
    sort(v.begin() + 1, v.end(), greater<int>());
    int xi = 1;
    for (;xi <= n * m; xi++)
        if (v[xi] == x) break;
    //cout << xi << endl;
    int c = (xi - 1) / n + 1;
    int r = c % 2 ? (xi - 1) % n + 1 : m - (xi - 1) % n;
    cout << c << ' ' << r;
    return 0;
}
