#include <bits/stdc++.h>

using namespace std;
using ULL = unsigned long long;

const int kMaxN = 2e5 + 5, kMaxL = 5e6 + 5;

int n, q, l[kMaxN], r[kMaxN], ans[kMaxN];
ULL kB = 131;
string s[kMaxN][2], t[kMaxN][2];
vector<pair<ULL, ULL>> vec;
vector<int> B[kMaxL * 2];

ULL GetHash(string s, ULL ret = 0) {
    for (char c : s) ret = kB * ret + c;
    return ret;
}

bool CheckString(string s) {
    int cnt = 0;
    for (char c : s) {
        if (c == 'b') {
            cnt++;
            if (cnt > 1) return 0;
        } else if (c != 'a') {
            return 0;
        }
    }
    return cnt == 1;
}

bool CheckB() {
    for (int i = 1; i <= n; i++) {
        if (!CheckString(s[i][0]) || !CheckString(s[i][1])) {
            return 0;
        }
    }
    for (int i = 1; i <= q; i++) {
        if (!CheckString(t[i][0]) || !CheckString(t[i][1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    // freopen("replace4.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
    }
    for (int i = 1; i <= q; i++) {
        cin >> t[i][0] >> t[i][1];
    }
    if (CheckB()) {
        for (int i = 1; i <= n; i++) {
            int p[2] = {};
            for (int o : {0, 1}) {
                for (int j = 0; j < s[i][o].size(); j++) {
                    if (s[i][o][j] == 'b') p[o] = j;
                }
            }
            l[i] = p[0], r[i] = (int)s[i][0].size() - p[0];
            B[p[0] - p[1] + kMaxL].push_back(i);
        }
        for (int i = 0; i <= 2 * kMaxL; i++) {
            sort(B[i].begin(), B[i].end());
        }
        for (int i = 1, ans = 0; i <= q; i++, ans = 0) {
            int p[2] = {};
            for (int o : {0, 1}) {
                for (int j = 0; j < t[i][o].size(); j++) {
                    if (t[i][o][j] == 'b') p[o] = j;
                }
            }
            int L = p[0], R = (int)t[i][0].size() - p[0];
            for (int j : B[p[0] - p[1] + kMaxL]) {
                if (l[j] <= L && r[j] <= R) {
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    } else {
        for (int i = 1; i <= n; i++) {
            vec.push_back({GetHash(s[i][0]), GetHash(s[i][1])});
        }
        sort(vec.begin(), vec.end());
        for (long long _ = 1, ans = 0; _ <= q; _++, ans = 0) {
            if (t[_][0].size() != t[_][1].size()) {
                cout << "0\n";
                continue;
            }
            int l = 0;
            for (; l < t[_][0].size() && t[_][0][l] == t[_][1][l]; l++) {
            }
            int r = t[_][0].size() - 1;
            for (; ~r && t[_][0][r] == t[_][1][r]; r--) {
            }
            for (int i = 0; i <= l; i++) {
                ULL hs = 0, ht = 0;
                for (int j = i; j < r; j++) {
                    hs = kB * hs + t[_][0][j];
                    ht = kB * ht + t[_][1][j];
                }
                for (int j = r; j < t[_][0].size(); j++) {
                    hs = kB * hs + t[_][0][j];
                    ht = kB * ht + t[_][1][j];
                    ans += upper_bound(vec.begin(), vec.end(), make_pair(hs, ht))
                         - lower_bound(vec.begin(), vec.end(), make_pair(hs, ht));
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
/*
2 2
aaaba aabaa
ab ba
aaaba aabaa
aaaab aaaba
*/