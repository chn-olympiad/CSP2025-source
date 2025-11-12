#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long LL;
int T, n;
LL a[N][5], typ[N], sec[N], c[N];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        LL ans = 0;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
            LL nmax = max(a[i][1], max(a[i][2], a[i][3]));
            if (nmax == a[i][1]) cnt1++, typ[i] = 1, sec[i] = max(a[i][2], a[i][3]);
            else if (nmax == a[i][2]) cnt2++, typ[i] = 2, sec[i] = max(a[i][1], a[i][3]);
            else cnt3++, typ[i] = 3, sec[i] = max(a[i][1], a[i][2]);
            ans += nmax;
        }
        int flag = 0, cntt = 0;
        if (cnt1 > n/2) flag = 1, cntt = cnt1;
        else if (cnt2 > n/2) flag = 2, cntt = cnt2;
        else if (cnt3 > n/2) flag = 3, cntt = cnt3;
        if (!flag) {
            printf("%lld\n", ans);
            continue;
        }
        int tot = 0;
        for(int i = 1; i <= n; i++) {
            if (typ[i] == flag) {
                LL nmax = max(a[i][1], max(a[i][2], a[i][3]));
                c[++tot] = nmax-sec[i];
            }
        }
        sort(c+1, c+1+tot);
        int idx = 0;
        for(int i = cntt; i > n/2; i--) {
            ans -= c[++idx];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
