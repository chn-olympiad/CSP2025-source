#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], ans[15][15], x, i, j=1, k;
bool cmp (int a, int b) {
    return a > b;
}
int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n*m; i++)
        scanf ("%d", &a[i]);
    x = a[1];
    sort (a+1, a+n*m+1, cmp);
    while (k != n*m) {
        k++;
        if (j%2 && i == n)
            j++;
        else if (!(j%2) && i == 1)
            j++;
        else if (j%2)
            i++;
        else
            i--;
        ans[i][j] = a[k];
        if (ans[i][j] == x) {
            printf ("%d %d", j, i);
            return 0;
        }
    }
    return 0;
}
