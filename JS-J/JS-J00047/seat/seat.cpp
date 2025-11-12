#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15; // ???
int a[MAXN];
bool cmp(int a, int b) {
    return a > b;

}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m; cin >> n >> m;
    int xm;
    for (int i = 1; i <= n * m; ++i) {
        cin >> a[i];
        if (i == 1) {
            xm = a[i];
        }
    }
    sort(a + 1, a + n * m + 1, cmp);
    int x = 1, y = 1; bool flag = 0; // 0 = --, 1 = ++
    for (int i = 1; i <= n * m; ++i) {
        // cout << y << ' ' << x << '\n';
        if (a[i] == xm) {
            cout << y << ' ' << x << '\n';
        }
        if (!flag) {
            if (x == n) {
                y++;
                flag = 1;
                x = n;
                continue;
            } else {
                x++;
            }
        } else {
            if (x == 1) {
                y++;
                flag = 0;
                x = 1;
                continue;
            } else {
                x--;
            }
        }
        // x = y, y = x ==> swap
    }
    return 0;
}