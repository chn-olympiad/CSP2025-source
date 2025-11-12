#include <bits/stdc++.h>

using namespace std;

const int N = 250;

int n, m;
int a[N];

bool cmp (int x, int y) {
    return x > y;
}

int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    int score = -1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            int val;
            scanf("%d", &val);
            if (i == 1 && j == 1) score = val;
            if (i % 2) a[1 + m * (i - 1) + (j - 1)] = val;
            else a[1 + m * (i - 1) + (n - j)] = val;
            //cout << n * (i) + j << '\n';
        }
    }
    sort (a + 1, a + n * m + 1, cmp);
    // cout <<score << '\n';
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
                // cout << a[n * (i - 1) + j] << ' ' << n * (i - 1) + j << '\n';
            int val;
            if (i % 2) val = a[1 + m * (i - 1) + (j - 1)];
            else val = a[1 + m * (i - 1) + (n - j)];
            if (val == score) {
                printf ("%d %d\n", i, j);
            }
        }
    }
    return 0;
}
