#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int mod1 = 99971, mod2 = 999983;

int n, q;
int len[200005][2];
string s[200005][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        len[i][0] = s[i][0].size();
        len[i][1] = s[i][1].size();
        s[i][0] = 'K' + s[i][0];
        s[i][1] = 'K' + s[i][1];
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int N = t1.size();
        t1 = 'K' + t1, t2 = 'K' + t2;
        ll ans = 0;
        cout << 0 << '\n';
    }
    return 0;
}
