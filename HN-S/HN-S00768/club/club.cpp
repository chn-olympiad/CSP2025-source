#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 5;

int T, n, a[kMaxN][3], p[kMaxN], b[kMaxN], tot, cnt[3], ans;

void Clear() {
    fill(cnt, cnt + 3, 0);
    ans = tot = 0;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    // freopen("club5.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    for (cin >> T; T; T--, Clear()) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j : {0, 1, 2}) cin >> a[i][j];
            if (a[i][0] >= max(a[i][1], a[i][2])) {
                p[i] = 0, cnt[0]++;
            } else if (a[i][1] >= max(a[i][0], a[i][2])) {
                p[i] = 1, cnt[1]++;
            } else {
                p[i] = 2, cnt[2]++;
            }
            ans += *max_element(a[i], a[i] + 3);
        }
        int x = max_element(cnt, cnt + 3) - cnt;
        if (cnt[x] <= n / 2) {
            cout << ans << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (p[i] == x) {
                sort(a[i], a[i] + 3);
                b[++tot] = a[i][1] - a[i][2];
            }
        }
        sort(b + 1, b + 1 + tot, greater<int>());
        for (int i = 1; i <= cnt[x] - n / 2; i++) {
            ans += b[i];
        }
        cout << ans << '\n';
    }
    return 0;
}