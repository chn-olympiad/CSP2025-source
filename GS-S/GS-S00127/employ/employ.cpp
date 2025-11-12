#include <iostream>

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    if (m == n) {
        char c;
        for (int i = 0; i < n; ++i) {
            std::cin >> c;
            if (c == '0') {
                std::cout << '0';
                return 0;
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i)
            ans = ans * i % 998244353;
        printf("%d", ans);
    } else if (n < 10) {

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
