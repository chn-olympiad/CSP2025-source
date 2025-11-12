#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 5e2 + 5;

int n, m, a[N], b[N];

namespace Code1 {
    int p[N];

    bool work() {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0 || cnt >= b[p[i]]) {
                cnt++;
            }
        }
        return (n - cnt >= m);
    }

    void solve() {
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
        int ans = 0;
        do {
            ans += work();
        } while (next_permutation(p + 1, p + 1 + n));
        cout << ans << '\n';
    }
}

void solve() {
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    Code1::solve();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    solve();
    return 0;
}