#include <bits/stdc++.h>
using namespace std;

string s[200005][2];
vector <int> cnt[500005];

int main() {
    freopen("replace2.in", "r", stdin);
    //freopen("replace.out", "w", stdout);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> s[i][0] >> s[i][1];
        cnt[s[i][0].length()].push_back(i);
    }
    while (q--) {
        int ans = 0;
        string s1, s2; cin >> s1 >> s2;
        if (s1.length() != s2.length()) {
            cout << 0 << endl;
            continue;
        }
        int len = s1.length();
        ans += cnt[len].size();
        for (int i : cnt[len]) {
            bool flag = 1;
            for (int j = 0; j < len; j++) {
                if (s[i][0][j] != s1[j] || s[i][1][j] != s2[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans++;
        }
        cout << ans << endl;
    }


    return 0;
}
