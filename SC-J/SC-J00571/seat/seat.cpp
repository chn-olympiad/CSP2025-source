#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;

int n, m, a[N], val, idx;

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%lld%lld", &n, &m);

    for (int i = 1; i <= n * m; i++) {
        scanf("%lld", &a[i]);
    }

    val = a[1];

    sort(a + 1, a + n * m + 1, [](const int &x, const int &y) { return x > y; });

    for (int i = 1; i <= n * m; i++) {
        if (a[i] == val) {
            idx = i;
            break;
        }
    }

    int ans1 = (idx + n - 1) / n;

    int ans2 = idx % n;
    if (!ans2) ans2 = n;
    ans2 = (ans1 & 1 ? ans2 : n - ans2 + 1);

    printf("%lld %lld\n", ans1, ans2);

    fclose(stdin);
    fclose(stdout);
    return 0;
}