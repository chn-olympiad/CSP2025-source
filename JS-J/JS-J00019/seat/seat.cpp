#include <bits/stdc++.h>
using namespace std;
int n, m, s, s1, l = 1, x, y;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &s1);
    for (int i = 2; i <= n * m; ++i) {
        scanf("%d", &s);
        if (s > s1) l++;
    }
    x = (l - 1) / n + 1;
    y = (l - 1) % n + 1;
    if (x % 2) printf("%d %d", x, y);
    else printf("%d %d", x, n - y + 1);
    return 0;
}
