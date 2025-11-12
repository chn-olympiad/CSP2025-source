#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 110;
int a[N];

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    int R = a[1];
    sort(a + 1, a + n * m + 1, greater<int> ());

    int x = 0, y = 1;
    bool turn = true; // true: down  false: up
    for (int i = 1; i <= n * m; i++) {
        if (turn) {
            x++;

            if (x > n) {
                x--;
                y++;
                turn = false;
            }
        } else {
            x--;

            if (x < 1) {
                x++;
                y++;
                turn = true;
            }
        }

        if (a[i] == R) {
            cout << y << ' ' << x;
            break;
        }
    }

    return 0;
}
