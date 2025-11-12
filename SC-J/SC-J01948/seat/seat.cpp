#include <bits/stdc++.h>
using namespace std;

int n, m, a, num, cnt = 0, x = 1, y = 1;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0);
    cin >> n >> m;
    cin >> a;
    for (int i = 1; i < n * m; i++) {
        cin >> num;
        if(num > a)cnt ++;
    }
    for (int i = 1; i <= cnt; i++) {
        if(y % 2)x ++;
        else x --;
        if(x > n) {
            x --, y ++;
        }
        if(x < 1) {
            x ++, y ++;
        }
    }
    cout << y << ' ' << x;
    return 0;
}