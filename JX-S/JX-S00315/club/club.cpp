#include <cstdio>
#include <algorithm>
using namespace std;
int T, n, a[100010][3], t[100010];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        long long ans = 0;
        int cnt[3] = {};
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            int maxa = max({a[i][0], a[i][1], a[i][2]});
            if (a[i][0] == maxa) {
                ++cnt[0];
            } else if (a[i][1] == maxa) {
                ++cnt[1];
            } else if (a[i][2] == maxa) {
                ++cnt[2];
            }
            ans += maxa;
        }
        if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
            printf("%lld\n", ans);
        } else {
            int tot = 0;
            for (int i = 1; i <= n; i++) {
                int maxa = max({a[i][0], a[i][1], a[i][2]});
                if (a[i][0] == maxa) {
                    if (cnt[0] > n / 2) {
                        t[++tot] = maxa - max(a[i][1], a[i][2]);
                    }
                } else if (a[i][1] == maxa) {
                    if (cnt[1] > n / 2) {
                        t[++tot] = maxa - max(a[i][0], a[i][2]);
                    }
                } else if (a[i][2] == maxa) {
                    if (cnt[2] > n / 2) {
                        t[++tot] = maxa - max(a[i][0], a[i][1]);
                    }
                }
            }
            sort(t + 1, t + tot + 1);
            int maxc = max({cnt[0], cnt[1], cnt[2]});
            for (int i = 1; i <= maxc - n / 2; i++) {
                ans -= t[i];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
