#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5 + 3;
int n, q;
map<int, string> mp;
string s[MN];

void solve() {
    string S, t;
    int ans = 0;
    cin >> S >> t;
    int len = (int)S.size();
    for (int i = 0; i < len; i++) {
        for (int j = 1; j <= n; j++) {
            int tl = s[j].size();
            if (i + 1 - tl < 0) continue;
            string st = S.substr(i + 1 - tl, tl), sf = "", se = "";
            if (st != s[j]) continue;
            if (i + 1 - tl > 0) sf = S.substr(0, i + 1 - tl);
            if (i != len - 1) se = S.substr(i + 1, len);
            string tt = sf + mp[j] + se;
            if (tt == t) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("1.in", "r", stdin);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        s[i] = s1;
        mp[i] = s2;
    }
    while (q--) solve();
    return 0;
}
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a
