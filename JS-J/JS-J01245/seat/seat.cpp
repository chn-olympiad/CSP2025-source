#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 8;
int n, m, a[N], cnt = 1, x, y;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
        if (a[i] > a[1]) cnt++;
    }
    x = cnt / n + (cnt % n != 0);
    if (x & 1) {
        if (cnt % n == 0) y = n;
        else y = cnt % n;
    } else {
        if (cnt % n == 0) y = 1;
        else y = n - cnt % n + 1;
    }
    cout << x << " " << y << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
