#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5;
int n, m, a[N + 10];
int num;
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> a[1];
    for (int i = 2; i <= n * m; i ++) {
        cin >> a[i];
        if (a[i] > a[1]) num ++;
    }
    num ++;
    int x = num % n;//hang
    int y = num / n;//lie
    if (x != 0) y ++;
    if (y % 2 == 1) {
        if (x != 0)
            cout << y << ' ' << x;
        else cout << y << ' ' << n;
    }
    else {
        if (x != 0) cout << y << ' ' << n - x + 1 ;
        else cout << y << ' ' << 1;
    }
    cout << endl;
    return 0;
}
