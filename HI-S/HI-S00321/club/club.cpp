#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 1e5 + 5;

int n, cnt[3], a[N][3], b[N], p;
bool vis[N];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
            mx = max(mx, a[i][j]);
        }
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == mx) {
                b[i] = j;
                ans += a[i][j];
                cnt[j]++;
                break;
            }
        }
    }
    p = -1;
    for (int i = 0; i < 3; i++) {
        if (cnt[i] > n / 2) {
            p = i;
            break;
        }
    }
    if (p != -1) {
        vector<PII> rec;
        for (int i = 1; i <= n; i++) {
            if (b[i] == p) {
                for (int j = 0; j < 3; j++) {
                    if (j != p) {
                        rec.push_back({a[i][j] - a[i][p], i});
                    }
                }
            }
        }
        sort(rec.begin(), rec.end(), [&](auto i, auto j) {
            return i.first > j.first;
        });
        int res = cnt[p] - n / 2;
        for (auto [x, y] : rec) {
            if (vis[y]) continue;
            if (!res) break;
            ans += x;
            vis[y] = 1;
            res--;
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}