#include <bits/stdc++.h>
#define FILEIO "replace"
using namespace std;

unordered_map<string, vector<string> > mp;

int n, q;

void dp();

signed main() {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        string s1, s2; cin >> s1 >> s2;
        mp[s1].emplace_back(s2);
    } 
    while (q--) {
        dp();
    }
}

void dp() {
    string s1, s2; cin >> s1 >> s2;
    if (s1.size() != s2.size()) {
        cout << "0\n";
        return;
    }
    int leng = s1.size();
    s1 = " " + s1, s2 = " " + s2;
    vector<vector<int> > dp(leng + 5, vector<int>(leng + 5));
    for (int i = 1; i <= n; ++i) {
        string tmp = "" + s1[i];
        if (mp[tmp].size() == 0) continue;
        for (auto &v : mp[tmp]) {
            if (v == "" + s2[i]) {
                dp[i][i] = 1;
                break;
            }
        }
    }
    for (int len = 2; len <= leng; ++len) {
        for (int i = 1, j = i + len - 1; j <= leng; ++i, ++j) {
            for (int k = i; k < j; ++k) {
                string t1 = s1.substr(i, k - i + 1), t2 = s2.substr(i, k - i + 1);
                string t11 = s1.substr(k + 1, i - k), t21 = s2.substr(k + 1, i - k);
                int tmp = 0;
                if (t1 == t2) {
                    tmp += dp[k + 1][j];
                }
                if (t11 == t21) {
                    tmp += dp[i][k];
                }
                for (auto &v : mp[t1]) {
                    if (v == t2) {
                        tmp++;
                        break;
                    }
                }
                for (auto &v : mp[t11]) {
                    if (v == t21) {
                        tmp++;
                        break;
                    }
                }
                dp[i][j] = max(dp[i][j], tmp);
            }
            string tmp1 = s1.substr(i, len), tmp2 = s2.substr(i, len);
            cerr << tmp1 << " " << tmp2 << "\n";
            for (auto &v : mp[tmp1]) {
                if (v == tmp2) {
                    cerr << "sf\n";
                    dp[i][j]++;
                    break;
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}