#include <bits/stdc++.h>
using namespace std;
int n, m, a[520], r;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n * m; i++) {
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1, a + n * m + 1);
    for(int i=1; i<=n * m; i++) {
        if(a[i] == r) {
            r = n * m - i + 1;
            break;
        }
    }
    if(r % n != 0) {
        cout << r / n + 1 << " "
        ;
        if((r / n) % 2 == 1) {
            cout << n - (r % n) + 1;
        } else {
            cout << r % n;
        }
    } else {
        cout << r / n << " ";
        if(r / n % 2 == 1) {
            cout << n;
        } else {
            cout << 1;
        }
    }
    return 0;
}
