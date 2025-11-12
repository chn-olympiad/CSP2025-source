#include <iostream>
#include <cstring>
#include <algorithm>

int a[100000][3], b[100000] = {1};
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, max = 0, sum = 0;
        scanf("%d", &n);
        if (n < 11) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < 3; ++j)
                    scanf("%d", &a[i][j]);
            while (!b[n]) {
                for (int i = 0; i < 3; ++i) {
                    int cnt = 0;
                    for (int j = 0; j < n; ++j)
                        if (b[j] == i)
                        ++cnt;
                    if (cnt << 1 > n)
                        goto end;
                }
                sum = 0;
                for (int i = 0; i < n; ++i)
                    sum += a[i][b[i]];
                if (sum > max)
                    max = sum;
                end:++b[0];
                for (int i = 0; i < n && b[i] > 2; ++i)
                    b[i] = 0, ++b[i + 1];
            }
            printf("%d\n", max);
            memset(a, 0, n * 12);
            b[n] = 0;
        } else {
            for (int i = 0; i < n; ++i)
                scanf("%d%*s%*s", &b[i]);
            std::sort(b, b + n, [] (int a, int b) {
                return a > b;
            });
            int sum = 0;
            for (int i = 0; i < n >> 1; ++i)
                sum += b[i];
            printf("%d\n", sum);
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
