#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

int n, q;
unordered_map<string, string> mp;
string s1, s2, t1, t2, s, pre, suf, t;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    for (int i = 1; i <= q; i++) {
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << 0 << '\n';
            continue;
        }
        int m = t1.size();
        t1 = ' ' + t1;
        int ans = 0;
        for (int j = 1; j <= m; j++) {
            pre = t1.substr(1, j - 1);
            for (int k = j; k <= m; k++) {
                s = t1.substr(j, k - j + 1);
                suf = t1.substr(k + 1);
                if (mp.count(s)) {
                    t = pre + mp[s] + suf;
                    if (t == t2) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}