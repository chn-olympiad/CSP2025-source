#include <bits/stdc++.h>
using namespace std;
int n, m, x, a[105];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n * m; i++) {
        scanf("%d", &a[i]);
    }
    x = a[1];
    sort(a + 1, a + 1 + n * m);
    int p = a + n * m - lower_bound(a + 1, a + 1 + n * m, x) + 1;
    int ans1 = (p + n - 1) / n, ans2;
    if (ans1 % 2 == 0) {
        if (p % n == 0) ans2 = 1;
        else ans2 = n - p % n + 1;
        printf("%d %d\n", ans1, ans2);
    } else {
        if (p % n == 0) ans2 = n;
        else ans2 = p % n;
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}