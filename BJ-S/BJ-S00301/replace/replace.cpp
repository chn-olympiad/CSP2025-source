#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
string s1[N], s2[N];

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (t1.find(s1[i]) != string::npos) {
                int l = t1.find(s1[i]), r = l + s1[i].size() - 1;
                string st = t1.substr(0, l) + s2[i] + t1.substr(r + 1);
                if (st == t2) ans++;
            }
        cout << ans << '\n';
    }
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
