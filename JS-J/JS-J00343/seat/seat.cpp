#include <bits/stdc++.h>
using namespace std;
int n, m, r, a[110], seat[15][15];
bool cmp(int x, int y) {
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int d = 1, i = 0, j = 1;
    for (int k = 1; k <= n * m; k++) {
        i += d;
        if (i > n) {
            i = n;
            j += 1;
            d = -d;
        }
        if (i < 1) {
            i = 1;
            j += 1;
            d = -d;
        }
        seat[i][j] = a[k];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (seat[i][j] == r) {
                cout << j << " " << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
