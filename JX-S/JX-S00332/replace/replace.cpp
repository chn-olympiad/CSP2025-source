#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s1[N], s2[N];
vector<int> f[N];
bool check(int l, int r, string &x, string &y) {
    for(int i = 0; i <= l; i++) if(x[i] != y[i]) return 0;
    for(int i = r; i < x.size(); i++) if(x[i] != y[i]) return 0;
    return 1;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
        int pos = 0;
        f[i].push_back(0);
        for(int j = 1; j < s1[i].size(); j++) {
            if(s1[i][j] == s1[i][pos]) pos++;
            else pos = 0;
            f[i].push_back(pos);
        }
    }
    while(q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        if(t1.size() != t2.size()) {
            cout << 0 << "\n";
            continue;
        }
        for(int i = 1; i <= n; i++) {
            int pos = 0, cnt = 0;
            if(s1[i].size() > t1.size()) continue;
            for(int j = 0; j < t1.size(); j++) {
                if(t1[j] == s1[i][pos]) {
                    pos++;
                    if(pos == s1[i].size()) {
                        string tmp = t2.substr(j - s2[i].size() + 1, s2[i].size());
                        if(tmp == s2[i]) {
                            if(check(j - s2[i].size(), j + 1, t1, t2)) {
                                ans++;
                                continue;
                            }
                        }
                        pos = f[i][pos - 1];
                    }
                } else {
                    while(t1[j] != s1[i][pos] && pos != 0) pos = f[i][pos - 1];
                    if(pos == 0 && t1[j] == s1[i][pos]) pos++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
