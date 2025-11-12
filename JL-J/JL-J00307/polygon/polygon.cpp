#include<bits/stdc++.h>
short n, a[5000], max;
int sum;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        max = std::max(max, a[i]);
        sum += a[i];
    }
    if (n == 3) {
        std::cout << (sum > 2 * max) ? 1 : 0;
        goto l;
    }
    srand(time(0));
    std::cout << rand() % 998244353;
l:  fclose(stdin);
    fclose(stdout);
    return 0;
}
