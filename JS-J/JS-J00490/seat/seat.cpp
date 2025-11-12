#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, x, y;
int a[107];
int pos = 1, t;
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
        if (i == 1) t = a[i];
        else if (a[i] > t) pos++;
    }
    // cout << pos << endl;
    x = pos / n + (pos % n != 0);
    int k = pos % m;
    if (x % 2 == 1) {
        if (k == 0) y = m;
        else y = k;
    }
    else {
        if (k == 0) y = 1;
        else y = m + 1 - k;
    }
    cout << x << " " << y << endl;
    return 0;
}
