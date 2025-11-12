#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    set<int> S;
    map<string, string> M;
    for (int i = 1; i <= n; i++) {
        string a, b;
        cin >> a >> b;
        M[a] = b;
        S.insert(a.size());
    }

    while (m--) {
        string s1, s2;
        cin >> s1 >> s2;
        int ans = 0;
        for (auto v : S) {
            for (int i = 0; i + v <= s1.size(); i++) {
                string sstr = s1.substr(i, v);
                if (M.find(sstr) == M.end())
                    continue;
                string s = s1.substr(0, i) + M[sstr] + s1.substr(i + v, s1.size() - (i + v));
//                cout << sstr << ' ';
//                cout << s << endl;
                if (s == s2)
                    ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
