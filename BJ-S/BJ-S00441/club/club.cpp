#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 10;
int t, n, a[maxn][3];
namespace pts_1_4 {
    bool check() { return n <= 10; }
    void work() {
        int ans = -1;
        for (int p = 0; p < pow(3, n); p++) {
            int ppp = p, cnt = 0; short flg[n + 1];
            for (int i = 1; i <= n; i++) flg[i] = 0;
            while (ppp) {
                flg[++cnt] = ppp % 3;
                ppp /= 3;
            }
            int sum = 0, cnt0 = 0, cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++) {
                if (flg[i] == 0) cnt0++;
                if (flg[i] == 1) cnt1++;
                if (flg[i] == 2) cnt2++;
                sum += a[i][flg[i]];
            }
            if (cnt0 <= n / 2 && cnt1 <= n / 2 && cnt2 <= n / 2) ans = max(ans, sum);
        }
        cout << ans << "\n";
        return;
    }
}
namespace pts_12 {
    bool check() {
        for (int i = 1; i <= n; i++) 
            if (a[i][1] != 0 || a[i][2] != 0) return false;
        return true;
    }
    void work() {
        int b[maxn];
        for (int i = 1; i <= n; i++) b[i] = a[i][0];
        sort(b + 1, b + n + 1, greater<int>());
        int res = 0;
        for (int i = 1; i <= n / 2; i++) res += b[i];
        cout << res << "\n";
        return;
    }
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        if (pts_1_4::check()) pts_1_4::work();
        else if (pts_12::check()) pts_12::work();
    }
    return 0;
}

// 25 pts