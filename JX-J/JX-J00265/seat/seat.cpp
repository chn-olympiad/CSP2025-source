#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int a1, a[105] = { 0 }, better_num = 0;
    int n, m, c;
    cin >> n >> m;

    cin >> a1; a[a1]++;
    for (int i = 1 ; i < n * m ; i++) {
        cin >> c;
        a[c]++;
    }

    for (int i = 100 ; i >= a1 ; i--) {
        better_num += a[i];
    }
    //cout << better_num << ":";
    int x = (better_num - 1) / n + 1;
    int mod = (better_num % n) ? (better_num % n) : n;
    int y = (x % 2) ? mod : (n + 1 - mod);
    cout << x << " " << y;
    //
    return 0;
}
