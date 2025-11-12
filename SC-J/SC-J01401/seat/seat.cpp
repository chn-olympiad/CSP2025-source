#include <bits/stdc++.h>
#define db(x...) fprintf(stderr,x)
const int N = 110;
int a[N], R, id, n, m, T;
bool cmp (int x, int y) { return x > y; }
int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    T = n * m;
    for (int i = 1; i <= T; i++) scanf ("%d", &a[i]);
    R = a[1];
    std::sort (a + 1, a + T + 1, cmp);
    for (int i = 1; i <= T; i++)
        if (a[i] == R) id = i;
    int x = (id + n - 1) / n, y = (id - 1) % n + 1;
    if (!(x & 1)) y = n - y + 1;
    printf ("%d %d\n", x, y);
    fclose (stdin);
    fclose (stdout);
    return 0;
}