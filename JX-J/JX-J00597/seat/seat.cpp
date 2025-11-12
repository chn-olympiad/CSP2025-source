#include<bits/stdc++.h>
using namespace std;
int a[250];
int change (int x, int y) {
    return x > y;
}
int main() {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n * m; i ++) {
        scanf ("%d", &a[i]);
    }
    int sum = a[0];
    int tot = 0;
    sort (a, a + n * m, change);
    for (int j = 0; j < m; j ++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i ++) {
                if (a[tot ++] == sum) {
                    printf ("%d %d\n", j + 1, i + 1);
                    return 0;
                }
            }
        }
        else {
            for (int i = n - 1; i >= 0; i --) {
                if (a[tot ++] == sum) {
                    printf ("%d %d\n", j + 1, i + 1);
                    return 0;
                }
            }
        }
    }
    return 0;
}