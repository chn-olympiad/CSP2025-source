#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int k = n * m;
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    int t = a[1];
    sort(a + 1, a + k + 1, cmp);
    int rk;
    for (int i = 1; i <= k; i++)
        if (a[i] == t)
            rk = i;
    int c, r;
    c = (rk - 1) / n + 1;
    if (c & 1) r = (rk - 1) % n + 1;
    else r = n - ((rk - 1) % n + 1) + 1;
    printf("%d %d\n", c, r);
    return 0;
}
