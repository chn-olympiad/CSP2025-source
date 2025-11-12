#include <bits/stdc++.h>
using namespace std;
int a[15][15], b[105], n, m, target;
bool cmp (int ma, int mb) {
    return ma > mb;
}
int main () {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> b[i];
    target = b[1];
    sort(b + 1, b + n * m + 1, cmp);
    int k = 1;
    for (int j = 1; j <= m; j++) {
        if (j % 2) {
            for (int i = 1; i <= n; i++) {
                if (b[k] == target) {
                    cout << j << " " << i;
                    return 0;
                }
                a[i][j] = b[k];
                k++;
            }
        } else {
            for (int i = n; i >= 1; i--) {
                if (b[k] == target) {
                    cout << j << " " << i;
                    return 0;
                }
                a[i][j] = b[k];
                k++;
            }
        }
    }
    return 0;
}
