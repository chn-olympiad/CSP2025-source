#include <bits/stdc++.h>
using namespace std;
int n, m;
int grid[15][15];
int a[105], k, cnt, p = 1;
bool cmp(int a, int b) {return a > b;}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    k = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int i = 1, j = 1;
    while (cnt <= n * m) {
        grid[i][j] = a[++cnt];
        if (p % 2 == 0) i--;
        else i++;
        if (i > n) i--, j++, p++;
        if (i < 1) i++, j++, p++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == k) {
                cout << j << " " << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
/*
2 2
99 100 97 98
*/
//#Shang4Shan3Ruo6Shui4
