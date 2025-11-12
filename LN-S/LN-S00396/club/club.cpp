#include <bits/stdc++.h>
using namespace std;
#define FILEIO "club"
const int N = 1e5 + 10;

int a[N][5];
int f[N];

void solve() {
    memset(a, 0, sizeof a);
    memset(f, 0, sizeof f);
    int n; cin >> n;
    vector<int> a1, b1, c1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        int maxn = max({a[i][1], a[i][2], a[i][3]});
        int cmax;
        if (a[i][1] == maxn) {
            a1.emplace_back(i);
            cmax = max(a[i][2], a[i][3]);
        }
        else if (a[i][2] == maxn) {
            b1.emplace_back(i);
            cmax = max(a[i][1], a[i][3]);
        }
        else if (a[i][3] == maxn) {
            c1.emplace_back(i);
            cmax = max(a[i][1], a[i][2]);
        }
        f[i] = maxn - cmax;
        ans += maxn;
    }
    if ((int) a1.size() > n / 2) {
        sort(a1.begin(), a1.end(), [&](int a, int b)
             { return f[a] < f[b]; });
        for (int i = 0, len = a1.size() - n / 2; i < len; ++i) {
            ans -= f[a1[i]];
        }
    }
    else if ((int) b1.size() > n / 2) {
        sort(b1.begin(), b1.end(), [&](int a, int b)
             { return f[a] < f[b]; });
        for (int i = 0, len = b1.size() - n / 2; i < len; ++i) {
            ans -= f[b1[i]];
        }
    }
    else if ((int) c1.size() > n / 2) {
        sort(c1.begin(), c1.end(), [&](int a, int b)
             { return f[a] < f[b]; });
        for (int i = 0, len = c1.size() - n / 2; i < len; ++i) {
            ans -= f[c1[i]];
        }
    }
    cout << ans << "\n";
}

signed main() {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}