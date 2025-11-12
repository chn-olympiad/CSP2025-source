#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
int T, n, cnt[3], ans;
priority_queue<int> q[3];
void clear() {
    for (int i = 0; i < 3; i++)
        while (!q[i].empty())
           q[i].pop();
    memset(cnt, 0, sizeof cnt);
    ans = 0;
}
void solve() {
    clear();
    cin >> n;
    for (int i = 1, x, y, z; i <= n; i++) {
        cin >> x >> y >> z;
        if (x >= y and x >= z) {
            cnt[0]++;
            q[0].push(max(y - x, z - x));
            ans += x;
        } else if (y >= x and y >= z) {
            cnt[1]++;
            q[1].push(max(x - y, z - y));
            ans += y;
        } else {
            cnt[2]++;
            q[2].push(max(x - z, y - z));
            ans += z;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] > n / 2) {
            cnt[i] -= n / 2;
            while (cnt[i]--) {
                ans += q[i].top();
                q[i].pop();
            }
            break;
        }
    }
    cout << ans << "\n";
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    IOS;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
