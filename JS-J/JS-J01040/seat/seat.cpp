#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
int n, m, a[105], g[15][15];
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    int val = a[0];
    sort(a, a + n * m, greater<int>());
    for (int i = 0, j = 0, idx = 0; i < n && j < m; idx++) {
        if (a[idx] == val) {
            cout << j + 1 << " " << i + 1;
            return 0;
        }
        g[i][j] = a[idx];
        //cout << a[idx] << " " << g[i][j] << '\n';
        if ((i == n - 1 && j % 2 == 0) || (i == 0 && j % 2 == 1)) {
            j++;
        } else if (j % 2 == 0){
            i++;
        } else if (j % 2) {
            i--;
        }
        //cout << i << " " << j << '\n' << '\n';
    }
    return 0;
}
