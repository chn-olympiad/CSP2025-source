#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
inline string sub(string o, ll l, ll r) {
    string ans = "";
    for (int i = l; i <= r; i++) ans += o[i];
    return ans;
}
inline void re(string &o, string &k, ll l, ll r) {
    for (int i = l; i <= r; i++) o[i] = k[i - l];
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    vector<pair<string, string>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    
    while (q--) {
        string x, y; cin >> x >> y;
        ll len = x.length(), len1 = y.length(), ans = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= n; j++) {
                // cerr << j << endl;
                string tmp = x;
                ll r = i + a[j].first.length() - 1;
                if (r < len) {
                    string s = sub(tmp, i, r);
                    // cerr << s << endl;
                    if (s == a[j].first) {
                        // cerr << i << ' ' << r << endl;
                        re(tmp, a[j].second, i, r);
                        if (tmp == y) ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}