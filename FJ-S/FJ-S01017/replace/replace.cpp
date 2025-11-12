#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const int N = 2e5 + 10;

int n, q;
string s1[N], s2[N];
mt19937_64 rnd(time(0));
ull hsh1[N], hsh2[N];
ull bs1[26], bs = 19260817, bs2 = 998244353;
ull pbs[5000001];
unordered_map<ull, int> mp;

vector<ull> msh[N];

void solve() {
    for (int i = 1; i <= n; i++) {
        int tt = 0;
        for (auto j : s1[i]) hsh1[i] = hsh1[i] + bs1[j - 'a'] * pbs[++tt];
        tt = 0;
        for (auto j : s2[i]) hsh2[i] = hsh2[i] + bs1[j - 'a'] * pbs[++tt];
        // cout << hsh1[i] << ' ' << hsh2[i] << '\n';
        // msh[s1[i].length()].push_back((hsh1[i] - hsh2[i]));
    }

    for (int ii = 1; ii <= q; ii++) {
        // cerr << i << ' ' << '\n';
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()) {
            cout << 0 << '\n';
            continue;
        }
        int m = t1.length();
        t1 = " " + t1; t2 = " " + t2;
        int st = 0, ed = 0;
        for (int i = 1; i <= m; i++) if (t1[i] != t2[i]) {st = i; break;}
        for (int i = m; i; i--) if (t1[i] != t2[i]) {ed = i; break;}
        vector<ull> h1(m+2), h2(m+2);
        h1[m+1] = h2[m+1] = 0;

        long long ans = 0;
        for (int i = m; i; i--) {
            h1[i] = (bs1[t1[i] - 'a'] + h1[i+1]) * bs;
            h2[i] = (bs1[t2[i] - 'a'] + h2[i+1]) * bs; 
            if (i <= st) for (int j = 1; j <= n; j++) {
                int ll = s1[j].length();
                // if (ii == 1 && i == 1 && j == 1) {
                    // cout << "sppp" << ll << ' ' << hsh1[j] << ' ' << hsh2[j] << ' ' << m-i+1 << '\n';
                    // cout << h1[i] << ' ' << h2[i] << '\n';
                // }
                if (ll <= m-i+1 && ll >= ed-i+1 && hsh1[j] == h1[i] - h1[i+ll] * pbs[ll]
                    && hsh2[j] == h2[i] - h2[i+ll] * pbs[ll]) {
                    // cout << i << " " << j << '\n';
                    ++ans;
                } 
            }
            // if (i <= st) ans += mp[h1 - h2];
        }
        // cerr << "bad" << h1[1] << ' ' << hsh1[1] << '\n';
        cout << ans << '\n';
    }
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    for (int i = 0; i < 26; i++) bs1[i] = rnd();
    pbs[0] = 1;
    for (int i = 1; i <= 5000000; i++) pbs[i] = pbs[i - 1] * bs;

    if (n <= 1000 && q <= 1000) {
        solve();
        return 0;
    }
    // solve();
    for (int i = 1; i <= n; i++) {
        int tt = 0;
        for (auto j : s1[i]) hsh1[i] = hsh1[i] + bs1[j - 'a'] * pbs[++tt];
        tt = 0;
        for (auto j : s2[i]) hsh2[i] = hsh2[i] + bs1[j - 'a'] * pbs[++tt];
        // cout << hsh1[i] - hsh2[i] << '\n';
        msh[s1[i].length()].push_back((hsh1[i] - hsh2[i]));
    }

    for (int i = 1; i <= q; i++) {
        // cerr << i << ' ' << '\n';
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()) {
            cout << 0 << '\n';
            continue;
        }
        int m = t1.length();
        t1 = " " + t1; t2 = " " + t2;
        int st = 0, ed = 0;
        for (int i = 1; i <= m; i++) if (t1[i] != t2[i]) {st = i; break;}
        for (int i = 1; i <= m; i++) if (t1[i] != t2[i]) {ed = i; break;}
        ull h1 = 0, h2 = 0;
        long long ans = 0;
        mp.clear();
        for (int i = m; i; i--) {
            h1 = (bs1[t1[i] - 'a'] + h1) * bs;
            h2 = (bs1[t2[i] - 'a'] + h2) * bs; 

            for (auto j : msh[m - i + 1]) {
                mp[j]++;
            } 
            // cerr << h1-h2 << '\n';
            if (i <= st) ans += mp[h1 - h2];
        }
        cout << ans << '\n';
    }
    return 0;
}