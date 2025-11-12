#include<bits/stdc++.h>
using namespace std;
int n, m, a[200], t, p;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    t = a[1];
    sort(a + 1, a + 1 + n * m, cmp);
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == t) {
            p = i;
            break;
        }
    }
    int x = 1, y = 1, c = 1;
    while (c < p) {
        if (y % 2) {
            if (x == n)y++;
            else x++;
        } else {
            if (x == 1)y++;
            else x--;
        }
        c++;
    }
    cout << y << ' ' << x;
    return 0;
}