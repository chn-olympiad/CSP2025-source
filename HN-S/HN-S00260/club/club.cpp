#include <cstdio>
#include <algorithm>

constexpr int MAX_N = 100000 + 2;
constexpr int INF = 1000000000;

int a[MAX_N][3], d[MAX_N], delta[MAX_N];

void solve() {
    int n, cnt[3] = {0, 0, 0}, ans = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);

        d[i] = 0;

        for (int j = 0; j < 3; j++) {
            if (a[i][j] > a[i][d[i]]) {
                d[i] = j;
            }
        }

        ans += a[i][d[i]];
        cnt[d[i]]++;
    }

    int c = 0;

    for (int i = 0; i < 3; i++) {
        if (cnt[i] > cnt[c]) {
            c = i;
        }
    }

    if (cnt[c] <= n >> 1) {
        printf("%d\n", ans);

        return;
    }

    int tot = 0;

    for (int i = 1; i <= n; i++) {
        if (d[i] != c) {
            continue;
        }

        int minVal = INF;

        for (int j = 0; j < 3; j++) {
            if (j != c) {
                minVal = std::min(minVal, a[i][c] - a[i][j]);
            }
        }

        delta[tot++] = minVal;
    }

    std::sort(delta, delta + tot);

    for (int i = 0; i < tot - (n >> 1); i++) {
        ans -= delta[i];
    }

    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}
