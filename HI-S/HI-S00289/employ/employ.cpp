#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 MOD = 998'244'353;

int main() {
#ifndef LOCAL
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
#endif
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> b(n + 1);
    {
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            b[i + 1] = s[i] - '0';
        }
    }
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int st = 1 << n;
    vector<vector<i64>> f(st, vector<i64>(n + 1));
    f[0][0] = 1;
    for(int s = 0; s < st; s++) {
        int k = __builtin_popcount(s);
        for(int i = 0; i <= n; i++) { 
            for(int j = 1; j <= n; j++) {
                if((s >> (j - 1)) & 1) {
                    continue;
                }
                int t = s | (1 << (j - 1));
                if(b[k + 1] == 0 || k - i >= a[j]) {
                    (f[t][i] += f[s][i]) %= MOD;
                } else {
                    (f[t][i + 1] += f[s][i]) %= MOD;
                }
            }
        }
    }

    i64 ans = 0;
    for(int i = m; i <= n; i++) {
        ans = (ans + f[st - 1][i]) % MOD;
    }

    cout << ans << '\n';

    return 0;
}