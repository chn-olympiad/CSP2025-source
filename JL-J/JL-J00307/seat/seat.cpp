#include<bits/stdc++.h>
short n, m;
short a[100], cnt;
bool cmp(short x, short y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    std::cin >> n >> m;
    for (short i = 0; i < n * m; i++)
        std::cin >> a[i];
    short r = a[0];
    std::sort(a, a + n * m, cmp);
    for (short i = 0; a[i] > r; i++, cnt++);
    printf("%d %d", cnt / n + 1, (cnt / n & 1 == 0) ? (cnt % n % m + 1) : (m - cnt % n % m));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
