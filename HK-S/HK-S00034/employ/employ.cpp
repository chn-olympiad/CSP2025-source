#include <bits/stdc++.h>
#define int long long
using namespace std;
bool submit = 0;
const int mod = 998244353, inf = 1e18;
vector<int> fact(555, 1);
int fp(int b, int p) {
    if (p == 0) return 1;
    else if (p == 1) return b%mod;
    else {
        int x = fp(b, p/2);
        x = (x*x)%mod;
        if (p%2 == 1) x = (x*b)%mod;
        return x;
    }
}
int inv(int b) {
    return fp(b, mod-2);
}
int npr(int n, int r) {
    if (r > n) return 0;
    else return (fact[n]*inv(fact[n-r]))%mod;
}
void solve() {
    int n, m, res = 0;
    string s;
    cin >> n >> m >> s;
    vector<int> c(n);
    bool all1 = 1;
    for (char c : s) if (c != '1') {
        all1 = 0;
        break;
    }
    for (int& i : c) cin >> i;
    sort(c.begin(), c.end(), greater<int>());
    // auto dfs = [&](auto&& dfs, vector<int> remain, vector<int> rej, int fail, int idx, int ftrf) -> void {
    //     while (!remain.empty()) {
    //         if (remain.back() <= fail) {
    //             rej.push_back(remain.back());
    //             remain.pop_back();
    //         } else break;
    //     }
    //     if (max(ftrf, rej.size())+fail > n-m) return;
    //     else if (max(ftrf, rej.size()+fail) < n-m) {
    //         for (int j : rej) {
    //             vector<int> nrej = rej;
    //             nrej.remove(j);
    //             if (s[idx] == '0') dfs(dfs, remain, nrej, fail+1, idx+1, ftrf-1);
    //             else dfs(dfs, remain, nrej, fail+1, idx+1, ftrf);
    //         }
    //     } 
    //     for (int j : remain) {
    //         vector<int> nremain = remain;
    //         nremain.remove(j);
    //         if (s[idx] == '0') dfs(dfs, nremain, rej, fail+1, idx+1, ftrf-1);
    //         else dfs(dfs, nremain, rej, fail, idx+1, ftrf);
    //     }
    //     if (idx == n-1) res = (res+1)%mod;
    //     return;
    // };
    if (n < 18) {
        vector<int> pm(n);
        for (int i=0; i<n; i++) pm[i] = i;
        do {
            int x = 0;
            for (int j=0; j<n; j++) if ((s[j] == '0') || (x >= c[pm[j]])) x++; 
            if (n-x >= m) res = (res+1)%mod;
        } while (next_permutation(pm.begin(), pm.end()));
        // vector<int> iremain, irej;
        // int zcnt = 0;
        // for (int i : c) {
        //     if (i == 0) irej.push_back(i);
        //     else iremain.push_back(i);
        // }
        // for (char c : s) if (c == '0') zcnt++;
        // dfs(dfs, iremain, irej, 0, 0, zcnt);
        cout << res << '\n';
    } else if (all1) {
        int x = n;
        vector<int> cnt;
        for (int i=0; i<n; i++) {
            auto it = upper_bound(c.begin(), c.end(), i);
        }
    } else if (m == 1) {
        int idx = -1;
        for (int i=0; i<n; i++) if (s[i] == '1') {
            idx = i;
            break;
        }
        if (idx == -1) {
            cout << "0\n";
            return;
        }
        int cnt = 0;
        for (int i=0; i<n; i++) if (c[i] > idx) cnt++;
        int res = (cnt*npr(n-1, idx))%mod;
        res = (res*fact[n-1-idx])%mod;
        cout << res << '\n';
    } else {

    }
    return;
}
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i=2; i<555; i++) fact[i] = (fact[i-1]*i)%mod;
    return;
}
signed main() {
    init();
    auto frt = freopen("employ.in", "r", stdin);
    auto frt2 = freopen("employ.out", "w", stdout);
    solve();
    return 0;
}