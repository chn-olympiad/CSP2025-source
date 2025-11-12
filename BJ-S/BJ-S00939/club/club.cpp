#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, t, a[100005], b[100005], c[100005], pl[100005], co[100005], tt[100005], cnt[5], ttlen, ans, tar;

bool cmp(int x, int y) {
    if (co[x] < co[y])
        return true;
    return false;
}

int main() {

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1;i <= n;i++)
            scanf("%d%d%d", a + i, b + i, c + i);
        cnt[1] = 0;
        cnt[2] = 0;
        cnt[3] = 0;
        ans = 0;
        tar = 0;
        ttlen = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i] >= b[i] && a[i] >= c[i]) {
                pl[i] = 1;
                ans += a[i];
                cnt[1]++;
                co[i] = min(a[i] - b[i], a[i] - c[i]);
            }
            else if (b[i] >= a[i] && b[i] >= c[i]) {
                pl[i] = 2;
                ans += b[i];
                cnt[2]++;
                co[i] = min(b[i] - a[i], b[i] - c[i]);
            }
            else{
                pl[i] = 3;
                ans += c[i];
                cnt[3]++;
                co[i] = min(c[i] - a[i], c[i] - b[i]);
            }
        }
        if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
            printf("%d\n", ans);
            continue;
        }
        if (cnt[1] > n / 2)
            tar = 1;
        else if (cnt[2] > n / 2)
            tar = 2;
        else
            tar = 3;
        for (int i = 1;i <= n;i++)
            if (pl[i] == tar)
                tt[++ttlen] = i;
        sort(tt + 1, tt + ttlen + 1, cmp);
        for (int i = 1;i <= cnt[tar] - n / 2;i++)
            ans -= co[tt[i]];
        printf("%d\n", ans);
    }
    return 0;
}
