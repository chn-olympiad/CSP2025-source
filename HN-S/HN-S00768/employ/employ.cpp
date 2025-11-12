#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 505, kM = 998244353;

int n, m, c[kMaxN], ans, fac[kMaxN];
string s;
bool vis[kMaxN];

void Dfs(int step, int cnt) {
    if (n - cnt < m) return;
    if (n - cnt - (n - step + 1) >= m) {
        ans = (ans + fac[n - step + 1]) % kM;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            Dfs(step + 1, cnt + (cnt >= c[i] || s[step] == '0'));
            vis[i] = 0;
        }
    }
}

bool CheckS(string s) {
    for (char c : s) {
        if (c == '0') return 0;
    }
    return 1;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    // freopen("employ3.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s, s = ' ' + s;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> c[i], fac[i] = 1LL * fac[i - 1] * i % kM;
    }
    sort(c + 1, c + 1 + n);
    if (CheckS(s)) {
        cout << fac[n];
        return 0;
    }
    Dfs(1, 0);
    cout << ans;
    return 0;
}