#include <bits/stdc++.h>
#include <cstdio>

long long abc(int lvl, int n, long long ans, int cnt[3], std::vector<int> d[3], long long running) {
    if (lvl == n + 1) {
        for (int p = 0; p < 3; p++) {
            if (cnt[p] > n/2) {
                return 0;
            }
        }

        return running;
    }
    for (int i = 0; i < 3; i++) {
        cnt[i]++;
        running += d[i][lvl-1];
        ans = std::max(ans, abc(lvl+1, n, ans, cnt, d, running));
        running -= d[i][lvl-1];
        cnt[i]--;
    }
    return ans;
}

void solve() {
    int n;
    std::cin >> n;

    // std::vector<int> a(n), b(n), c(n);
    std::vector<int> d[3];
    int special = 1;
    for (int i = 0; i < 3; i++) {
        d[i] = std::vector<int>(n);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> d[0][i] >> d[1][i] >> d[2][i];
        if (d[1][i] != 0 || d[2][i] != 0) {
            special = 0;
        }
    }

    if (special) {
        std::vector<int> a = d[0];
        std::sort(a.rbegin(), a.rend());
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += a[i];
        }
        std::cout << ans << '\n';
        return;
    }

    long long ans = 0;

    if (n == 2) {
        for (int i1 = 0; i1 < 3; i1++) 
        for (int i2 = 0; i2 < 3; i2++) {
            int cnt[3] = {0,0,0};
            cnt[i1]++;
            cnt[i2]++;
            int ok = 1;
            for (int p = 0; p < 3; p++) {
                if (cnt[p] > n/2) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            ans = std::max(ans, (long long)d[i1][0] + d[i2][1]);
        }
    } else if (n == 4) {

        for (int i1 = 0; i1 < 3; i1++) 
        for (int i2 = 0; i2 < 3; i2++) 
        for (int i3 = 0; i3 < 3; i3++) 
        for (int i4 = 0; i4 < 3; i4++) {
            int cnt[3] = {0,0,0};
            cnt[i1]++;
            cnt[i2]++;
            cnt[i3]++;
            cnt[i4]++;
            int ok = 1;
            for (int p = 0; p < 3; p++) {
                if (cnt[p] > n/2) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            ans = std::max(ans, (long long)d[i1][0] + d[i2][1] + d[i3][2] + d[i4][3]);
        }
    } else {

        int cnt[3] = {0,0,0};

        ans = abc(1, n, 0, cnt, d, 0);
    }

    std::cout << ans << "\n";
}

int main() {
    auto x = freopen("club.in", "r", stdin);
    auto y = freopen("club.out", "w", stdout);
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}