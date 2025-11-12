#include <bits/stdc++.h>
using namespace std;

int a[110];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int R = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    int x = 1, y = 0;
    int updown = 0;
    for (int i = 1; i <= n * m; i++) {
        if (updown == 0) {
            y++;
            if (y > n) {
                x++;
                y = n;
                updown = 1;
            }
        } else {
            y--;
            if (y < 1) {
                x++;
                y = 1;
                updown = 0;
            }
        }
        if (a[i] == R) {
            break;
        }
    }
    cout << x << " " << y;

    return 0;
}
