#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, string> mp;
map<string, string>:: iterator it;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    string s1, s2, t1, t2;
    for (int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    while (q--) {
        cin >> t1 >> t2;
        int l1 = t1.size(), l2 = t2.size();
        if (l1 != l2) {
            cout << "0\n";
            continue;
        }
        ll ans = 0;
        for (it = mp.begin(); it != mp.end(); it++) {
            string from = (it -> first), to = (it -> second);
            int len = from.size();
            for (int i = 0; i < l1; i++) {
                if (t1.substr(i, len) == from) {
                    string t = "";
                    int idx = 0;
                    for (int j = 0; j < l1; j++) {
                        if (j >= i and j <= i + len - 1) t += to[idx++];
                        else t += t1[j];
                    }
                    if (t == t2) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
