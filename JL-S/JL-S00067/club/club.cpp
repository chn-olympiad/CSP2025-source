#include <bits/stdc++.h>
using namespace std;

int T, n, a[4][100010], b[100010], zmax[100010], cmax[100010], num[4], ans;

inline void solve() {
    ans = 0;
    num[1] = 0, num[2] = 0, num[3] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[1][i], &a[2][i], &a[3][i]);
        int x = a[1][i], y = a[2][i], z = a[3][i];
        if (x >= y && x >= z) {
            zmax[i] = 1, num[1]++;
            if (y >= z)
                cmax[i] = 2;
            else
                cmax[i] = 3;
        }
        else if (y >= z) {
            zmax[i] = 2, num[2]++;
            if (x >= z)
                cmax[i] = 1;
            else
                cmax[i] = 3;
        }
        else {
            zmax[i] = 3, num[3]++;
            if (x >= y)
                cmax[i] = 1;
            else
                cmax[i] = 2;
        }
    }
    for (int i = 1; i <= n; i++)
        ans += a[zmax[i]][i];
    int id;
    bool t = true;
    for (int i = 1; i <= 3; i++)
        if (num[i] > n / 2) {
            t = false;
            id = i;
            break;
        }
    if (t) {
        printf("%d\n", ans);
        return;
    }
    int shu = 0;
    for (int i = 1; i <= n; i++)
        if (zmax[i] == id) {
            b[++shu] = a[id][i] - a[cmax[i]][i];
        }
    sort(b + 1, b + shu + 1);
    for (int i = 1; i <= num[id] - (n / 2); i++)
        ans -= b[i];
    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}
