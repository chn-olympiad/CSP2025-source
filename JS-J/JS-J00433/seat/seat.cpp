#include <bits/stdc++.h>
using namespace std;
int n, m;
bool tmp(int x,int y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int a[n*m+2], r, st[n][m];
    for (int i = 0; i < n*m; ++i) cin >> a[i];
    r = a[0];
    sort (a, a + (n*m), tmp);
    int p = 0;
    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                st[j][i] = a[p];
                ++p;
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                st[j][i] = a[p];
                ++p;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (st[i][j] == r) {
                cout << j + 1 << " " << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
