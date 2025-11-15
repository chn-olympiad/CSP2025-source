/*
160545 since ik how do 2 i do 3 first
175322 ok i still dk how do dis
*/

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int replace(string a, string b, string c, string d) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        string e = a;
        if (a[i] == b[0]) {
            for (int j = 0; j < b.size(); j++) {
                if (a[i + j] != b[j]) {
                    break;
                }
            }
            for (int j = 0; j < b.size(); j++) {
                e[i+j] = d[j];
            }
            cnt += (e == c);
            continue;
        }
    }
    return cnt;
}

int main() {
    
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    int n, q; cin >> n >> q;
    vector<pair<string, string>> dict(n);
    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;
        dict[i] = {s, t};
    }
    if (n <= 100 && q <= 100) {
        while (q--) {
            int ans = 0;
            string s, t; cin >> s >> t;
            for (int i = 0; i < n; i++) {
                ans += replace(s, dict[i].ff, t, dict[i].ss);
            }
            cout << ans << endl;
        }
    }
}