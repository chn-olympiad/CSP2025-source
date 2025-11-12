#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int f[2][105][105][105];
int num[100005];
int s[100005][5];
bool solve () {
    for (int i = 1; i <= n; i++) {
        if (s[i][2] != 0 || s[i][3] != 0) return false;
    }
    return true;
}
bool cmp (int x, int y) {
    return x > y;
}
signed main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> s[i][j];
                if (j == 1) num[i] = s[i][j];
            }
        }
        if (n >= 400 && solve()) {
            sort(num + 1, num + n + 1, cmp);
            int sum = 0;
            for (int i = 1; i <= (n / 2); i++) {
                sum += num[i];
            }
            cout << sum << endl;
            continue;
        }
        memset(f, 0, sizeof(f));
        f[0][0][0][0] = 0;
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            for (int a = 0; a <= i; a++) {
                for (int b = 0; b <= i; b++) {
                    int c = i - a - b;
                    if (c < 0) continue;
                    if (a > (n / 2) || b > (n / 2) || c > (n / 2)) continue;
                    if (a > 0) f[i & 1][a][b][c] = max(f[(i - 1) & 1][a - 1][b][c] + s[i][1], f[i & 1][a][b][c]);
                    if (b > 0) f[i & 1][a][b][c] = max(f[(i - 1) & 1][a][b - 1][c] + s[i][2], f[i & 1][a][b][c]);
                    if (c > 0) f[i & 1][a][b][c] = max(f[(i - 1) & 1][a][b][c - 1] + s[i][3], f[i & 1][a][b][c]);
                    if (a <= (n / 2) && b <= (n / 2) && c <= (n / 2)) maxn = max(maxn, f[i & 1][a][b][c]);
                }
            }
        }
        //for (int i = 1; i <= n; i++) {
        //    for (int a = 0; a <= (n / 2); a++) {
        //        for (int b = 0; b <= (n / 2); b++) {
        //            int c = i - a - b;
        //            if (c < 0 || c > (n / 2)) continue;
        //            cout << i << ' ' << a << ' ' << b << ' ' << c << " : " << f[i][a][b][c] << endl;
        //        }
        //    }
        //}
        cout << maxn << endl;
    }
    return 0;
}
