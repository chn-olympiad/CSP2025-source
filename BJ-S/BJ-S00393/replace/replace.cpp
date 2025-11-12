#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef unsigned long long ULL;
const int P = 13331;
const int N = 2e5 + 3;
const int L = 5e6 + 3;
int n, q;
ULL p[L], hs[5][N], ht[5][L];
string s[5][N];

ULL Hash(int c, int l, int r) {
    return ht[c][r] - ht[c][l - 1] * p[r - l + 1];
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    p[0] = 1;
    for (int i = 1; i <= 2000; ++i)
        p[i] = p[i - 1] * P;
    for (int i = 1; i <= n; ++i) {
        cin >> s[1][i] >> s[2][i];
        for (int j = 1; j <= s[1][i].size(); ++j)
            hs[1][i] = hs[1][i] * P + 1ull * (s[1][i][j - 1] - 'a' + 1);
        for (int j = 1; j <= s[2][i].size(); ++j)
            hs[2][i] = hs[2][i] * P + 1ull * (s[2][i][j - 1] - 'a' + 1);
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= t1.size(); ++i)
            ht[1][i] = ht[1][i - 1] * P + 1ull * (t1[i - 1] - 'a' + 1);
        for (int i = 1; i <= t2.size(); ++i)
            ht[2][i] = ht[2][i - 1] * P + 1ull * (t2[i - 1] - 'a' + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int l = 1; l <= t1.size(); ++l) {
                int r = l + s[1][i].size() - 1;
                if (r > t1.size())
                    continue;
                if (Hash(1, l, r) == hs[1][i]) {
                    bool ok = true;
                    if (Hash(1, 1, l - 1) != Hash(2, 1, l - 1))
                        ok = false;
                    if (Hash(1, r + 1, t1.size()) != Hash(2, r + 1, t2.size()))
                        ok = false;
                    if (ok && hs[2][i] == Hash(2, l, r))
                        ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}