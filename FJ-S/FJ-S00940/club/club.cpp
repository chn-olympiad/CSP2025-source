#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N][3], b[N], d[N];

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        long long res = 0;
        int cnt[3] = {0, 0, 0};
        for (int i = 1; i <= n; ++i) {
            for (int j : {0, 1, 2}) scanf("%d", &a[i][j]);
            int id = max_element(a[i], a[i] + 3) - a[i];
            res += a[i][id];
            ++cnt[id], b[i] = id;
        }
        if (max({cnt[0], cnt[1], cnt[2]}) <= n / 2) {
            printf("%lld\n", res);
        } else {
            int w = max_element(cnt, cnt + 3) - cnt, r = 0;
            for (int i = 1; i <= n; ++i) {
                if (b[i] != w) continue;
                int mx = 0;
                for (int j = 0; j < 3; ++j) {
                    if (j != w) mx = max(mx, a[i][j]);
                }
                d[++r] = a[i][w] - mx;
            }
            sort(d + 1, d + r + 1);
            for (int i = 1; i <= cnt[w] - n / 2; ++i) {
                res -= d[i];
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}