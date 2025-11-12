#include <bits/stdc++.h>
using namespace std;

int t, n, c[4];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    for (int x = 0; x < t; x++) {
        cin >> n;
        int cnt[5], res = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cin >> c[1] >> c[2] >> c[3];
            int ma = 0, mid = 0, mi = 0;
            ma = c[1] >= c[2] ? 1 : 2, mi = c[1] <= c[2] ? 1 : 2;
            ma = c[ma] >= c[3] ? ma : 3, mi = c[mi] <= c[3] ? mi : 3;
            mid = 1;
            if (mid == ma || mid == mi) mid = 2;
            if (mid == ma || mid == mi) mid = 3;

            if (cnt[ma]/2 < n) {
                cnt[ma]++;
                res += c[ma];
            }
            else if (cnt[mid]/2 < n) {
                cnt[mid]++;
                res += c[mid];
            }
            else {
                cnt[mi]++;
                res += c[mi];
            }
        }
        cout << res << endl;
    }
    return 0;
}