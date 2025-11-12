#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 MOD = 998'244'353;
constexpr int w = 5000;

int main() {
#ifndef LOCAL
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
#endif

    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(w + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<vector<i64>> bin(n + 1, vector<i64>(n + 1));
    for(int i = 0; i <= n; i++) {
        bin[i][0] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            bin[i][j] = (bin[i - 1][j - 1] + bin[i - 1][j]) % MOD;
        }
    }

    vector<i64> f(2 * w + 2);
    f[0] = 1;

    auto update = [&](int x) {
        for(int i = 2 * w + 1; i >= 0; i--) {
            (f[min(2 * w + 1, i + x)] += f[i]) %= MOD;   
        }
    };

    i64 ans = 0;
    for(int m = 1; m <= w; m++) {
        for(int k = 1; k <= cnt[m]; k++) {
            i64 x = bin[cnt[m]][k];
            i64 y = 0;
            for(int i = max(0, (2 - k) * m + 1); i <= 2 * w + 1; i++) {
                y = (y + f[i]) % MOD;
            }
            i64 add = x * y % MOD;
            ans = (ans + add) % MOD;
        }
        for(int k = 1; k <= cnt[m]; k++) {
            update(m);
        }
    }

    cout << ans << '\n';

    return 0;
}
// 9:42
// OK, now I passed all problems within 1 hour and 12 minutes. I hope I can AK this contest, though it's only CSP-J.
// T4 is easier than I have expected. I think of the answer only after I read the statement, and I passed the example tests without any debug.
// Maybe now I should write some generators to check my code.