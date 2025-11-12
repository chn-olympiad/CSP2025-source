#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10;
int a[N + 5][N + 5];
int p[N * N + 5];
int f[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, 1}};
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m, x;
    cin >> n >> m >> x;
    p[1] = x;
    for (int i = 2; i <= n * m; i++) {
        int s;
        cin >> s;
        p[i] = s;
    }
    sort(p + 1, p + 1 + n * m);
    reverse(p + 1, p + 1 + n * m);
    int i = 1, j = 1, cnt = 0;
    while (cnt < n * m) {
        while (i <= n && cnt < n * m && !a[i][j]) {
            a[i ++][j] = p[++ cnt];
        }
        i --;
        j ++;
        while (i >= 1 && cnt < n * m && !a[i][j]) {
            a[i --][j] = p[++ cnt];
        }
        i ++;
        j ++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (a[i][j] == x) {
				cout << j << ' ' << i;
				return 0;
			}
	}
    return 0;
}

