#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int n, m, a[N], t, R, Rt;
bool cmp(int a, int b) {
    return a > b;
}
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m; t = n * m;
    for (int i = 1; i <= t; i++) cin >> a[i];
    R = a[1]; sort(a + 1, a + t + 1, cmp);
    for (int i = 1; i <= t; i++) {
        if (a[i] == R) {
            Rt = i;
            break;
        }
    }
    //cout << "Rt: " << Rt << "\n";
    for (int i = 1; i <= m; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= n; j++) {
                if (Rt == (i - 1) * n + j) cout << i << " " << j;
            }
        } else {
            for (int j = 1; j <= n; j++) {
                if (Rt == (i - 1) * n  + j) cout << i << " " << n - j + 1;
            }
        }
    }
    return 0;
}
