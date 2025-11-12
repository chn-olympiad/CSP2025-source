#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, L = 5e6 + 5;
int n, q;
string s[N][2], t[2];
unordered_map<int, int> mp;
bool flag = true;

int ok(string x) {
    int cnt = 0, pos = -1;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 'a') continue;
        else if (x[i] == 'b') {
            if (cnt == 1) return -1;
            pos = i;
            cnt++;
        } else return -1;
    }
    if (cnt == 1) return pos;
    return -1;
}
void init() {
    for (int i = 1; i <= n; i++) {
        int d = ok(s[i][1]) - ok(s[i][0]);
        mp[d]++;
    }
}
void stkb(string t0, string t1) {
    int d = ok(t1) - ok(t0);
    cout << mp[d] << '\n';
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        if (ok(s[i][0]) == -1 || ok(s[i][1]) == -1) flag = false;
    }
    flag = false;
    if (flag) init();
    while (q--) {
        cin >> t[0] >> t[1];
        if (t[0].size() != t[1].size()) {cout << "0\n"; continue;}
        if (flag && ok(t[0]) != -1 && ok(t[1]) != -1) {
            stkb(t[0], t[1]);
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (t[0].find(s[i][0]) != string::npos) {
                int d = t[0].find(s[i][0]);
                string tmp = t[0];
                tmp = tmp.replace(d, s[i][1].size(), s[i][1]);
                if (tmp == t[1]) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}