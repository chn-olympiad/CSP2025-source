#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[105];
int x;
int c, r;

bool cmp(int a, int b) {
    return a > b;
}

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a [i];
    }
    x = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == x) {
            x = i;
            break;
        }
    }
    int t_1 = x / (2 * n) + (x % (2 * n) > 0);
    int t_2 = x % (2 * n);
    // cout << tmp;
    if (t_2 == 0) {
        c = t_1 * 2;
        r = 1;
    } else {
        if (t_2 <= n) {
            c = t_1 * 2 - 1;
            r = t_2;
        } else {
            c = t_1 * 2;
            r = 2 * n - t_2 + 1;
        }
    }
    cout << c << " " << r;
    return 0;
}
