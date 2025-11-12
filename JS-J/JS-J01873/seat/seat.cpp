#include <iostream>
#include <cstdio>
using namespace std;
const int N = 15;
int n, m, a[N * N], rnk, c, r;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    for (int i = 2; i <= n * m; i++) if (a[i] > a[1]) rnk++;
    c = rnk / n + 1;
    if (c & 1) r = rnk % n + 1;
    else r = n - rnk % n;
    cout << c << ' ' << r << '\n';
    return 0;
}
// expect 100pts