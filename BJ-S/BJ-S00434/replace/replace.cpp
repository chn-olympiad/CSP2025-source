#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
const int L = 5e6 + 10;
#define ull unsigned long long
string s[N][2];
ull hs[N][2], ht[L][2], pw[L];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> s[i][0] >> s[i][1];
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 233;
    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j < s[i][0].size(); ++j) hs[i][0] = hs[i][0] * 233 + s[i][0][j] - 'a', hs[i][1] = hs[i][1] * 233 + s[i][1][j] - 'a';
    while (q--) {
        string t[2];
        cin >> t[0] >> t[1];
        t[0] = " " + t[0]; t[1] = " " + t[1];
        if (t[0].size() != t[1].size()) { cout << "0\n"; continue ; }
        for (int i = 1; i < t[0].size(); ++i) ht[i][0] = ht[i - 1][0] * 233 + t[0][i] - 'a', ht[i][1] = ht[i - 1][1] * 233 + t[1][i] - 'a';
        int ans = 0;
        for (int d = 1; d <= n; ++d) 
            for (int i = 1; i + s[d][0].size() <= t[0].size(); ++i) 
                if (ht[i + s[d][0].size() - 1][0] - ht[i - 1][0] * pw[s[d][0].size()] == hs[d][0] && ht[t[0].size() - 1][0] - pw[t[0].size() - i - s[d][0].size()] * (hs[d][0] - hs[d][1]) == ht[t[0].size() - 1][1]) ++ans;
        cout << ans << "\n";
    }
    return 0;
}