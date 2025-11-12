#include<bits/stdc++.h>
using namespace std;
int n = 10000, m = 1000000, k = 10;
mt19937 rnd(time(0));
signed main() {
    freopen("road.in", "w", stdout);
    cout << n << ' ' << m << ' ' << k << endl;
    for (int i = 1; i <= m; i++) {
        int x = rnd() % n + 1, y = rnd() % n + 1, w = rnd() % (int)1e9;
        cout << x << ' ' << y << ' ' << w << endl;
    }
    for (int i = 1; i <= k; i++) {
        cout << rnd() % (int)1e9 << ' ';
        for (int j = 1; j <= n; j++) cout << rnd() % (int)1e9 << ' ';
        cout << '\n';
    }
    return 0;
}