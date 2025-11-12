#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int T, n, a[4][100001], maxx = -1, p[100001];
bool flag = true;
void dfs(int l, int d, int p1, int p2, int p3) {
    if (p1 > n / 2 || p2 > n / 2 || p3 > n / 2) {
        return;
    }
    if (l == n + 1) {
        maxx = max(maxx, d);
        return;
    }
    for (int i = 1; i <= 3; i++) {
        dfs(l + 1, d + a[l][i], p1 + (i == 1), p2 + (i == 2), p3 + (i == 3));
    }
}
bool cmp(int __x, int __y) {
    return __x > __y;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[1][i] >> a[2][i] >> a[3][i];
            if (a[2][i] != 0 || a[3][i] != 0) {
                flag = false;
            }
        }
        if (flag) {
            int sum = 0;
            sort(a[1] + 1, a[1] + n + 1, cmp);
            for (int i = 1; i <= n / 2; i++) {
                sum += a[1][i];
            }
            cout << sum << endl;
            continue;
        }
        dfs(1, 0, 0, 0, 0);
        cout << maxx << endl;
        maxx = 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
