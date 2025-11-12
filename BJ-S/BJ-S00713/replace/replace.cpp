#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
#define int long long
int n, q;
struct str{
    string l, r;
} s[N];
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s[i].l >> s[i].r;
    while(q--) {
        string a, b;
        cin >> a >> b;
        string c = a;
        string d = b;
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(c.find(s[i].l) >= 0 && c.find(s[i].l) < c.size() && d.find(s[i].r) >= 0 && d.find(s[i].r) < d.size()) {
                int l = c.find(s[i].l), r = d.find(s[i].r);
                string L = c.substr(0, l);
                string R = d.substr(0, l);
                if(L != R) continue;
                L = c.substr(l + s[i].l.size(), c.size() -(l + s[i].l.size()));
                R = d.substr(l + s[i].r.size(), d.size() - (l + s[i].r.size()));
                if(L == R) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
