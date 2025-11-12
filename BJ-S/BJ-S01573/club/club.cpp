#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int T, n, sum[5];

struct Student {
    int s[5], mx;
    bool operator< (const Student y) {
        return mx < y.mx;
    }
} a[MAXN];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        memset(sum, 0, sizeof(sum));
        memset(a, 0, sizeof(a));
        cin >> n;
        int s1 = 0, s2 = 0, s3 = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].s[1] >> a[i].s[2] >> a[i].s[3];
            s1 += a[i].s[1], s2 += a[i].s2, s3 += a[i].s3;
            a[i].mx = max(a[i].s[1], max(a[i].s[2], a[i].s[3]));
            for(int j = 1; j <= 3; ++j)
                if(a[i].mx == a[i].s[j]) ++sum[j];
        }
        sort(a + 1, a + n + 1);
        if(s2 == 0 && s3 == 0) {
            int ans = 0;
            for(int i = n; i > n / 2; ++i) {
                ans += a[i].mx;
            }
            cout << ans << '\n';
        }
        if(n == 2) {
            int ans = -INF;
            for(int i = 1; i <= 3; ++i) {
                for(int j = 1; j <= 3; ++j) {
                    if(i == j) continue;
                    ans = max(ans, a[1].s[i] + a[2].s[j]);
                }
            }
            cout << ans << '\n';
            continue;
        }
        int cnt[5], ans = 0, p[5], q;
        memset(cnt, 0, sizeof(cnt));
        for(int i = n; i; --i) {
            p[1] = a[i].s[1], p[2] = a[i].s[2], p[3] = a[i].s[3], q = 0;
            for(int j = 1; j <= 3; ++j)
                if(cnt[j] >= n / 2) p[j] = -INF;
            int pm = max(p[1], max(p[2], p[3])), k;
            for(int j = 1; j <= 3; ++j)
                if(p[j] == pm) ++q, k = j;
            if(q > 1) {
                k = 0;
                for(int j = 1; j <= 3; ++j)
                    if(p[j] == pm && (!k || sum[j] < sum[k])) k = j;
            }
            ++cnt[k], ans += p[k];
            for(int j = 1; j <= 3; ++j)
                if(a[i].mx == a[i].s[j]) --sum[j];
        }
        cout << ans << '\n';
    }
    return 0;
}
