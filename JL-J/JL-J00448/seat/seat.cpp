#include <iostream>
#include <cstdio>
#include <algorithm>
int n, m, a[105], mp[15][15];
bool cmp(int a, int b) { return a > b; }
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    std::cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        std::cin >> a[i];
    }
    int rsc = a[1];
    std::sort(a + 1, a + n * m + 1, cmp);
    int x = 1, y = 1, fang = 1;
    for (int i = 1; i <= n * m; i++) {
        mp[x][y] = a[i];
        x += fang;
        if (x == n+1 && fang == 1) {
            fang = -1;
            x = n;
            y++;
        }
        if (x == 0 && fang == -1) {
            fang = 1;
            x = 1;
            y++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == rsc) {
                std::cout << j << " " << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}