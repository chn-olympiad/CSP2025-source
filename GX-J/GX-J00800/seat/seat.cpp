#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n, m, v = 1;
    cin >> n >> m;
    int a[n * m];
    cin >> a[0];
    for (int i = 1;i < n * m;i++) {
        cin >> a[i];
        if (a[i] > a[0]) v++;
    }
    int x = (v % n) ? v / n + 1 : v / n,
    y = (x % 2) ? x % n + 1 : n - x % n;
    cout << x << ' ' << y;
    return 0;
}
