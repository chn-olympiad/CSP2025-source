#include <bits/stdc++.h>
using namespace std;

#define L(i, j, k) for(int i = (j), _e = (k); i <= _e; ++i)
#define R(i, j, k) for(int i = (j), _e = (k); i >= _e; --i)
#define db(...) fprintf(stderr, __VA_ARGS__)
typedef long long ll;

constexpr int N = 2e5 + 5, Len = 5e6 + 5;
int n, q, L1;
vector<string> s1, s2;

bool eq(string& s1, string& s2, int l, int r) {
    L(i, l, r) if (s2[i] != s1[i - l]) return false;
    return true;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    L1 = 0;
    L(i, 1, n) {
        string s; cin >> s;
        s1.push_back(s); L1 += s.size();
        string str; cin >> str;
        s2.push_back(str); L1 += str.size();
    }
    L(Q, 1, q) {
        string t1, t2; cin >> t1 >> t2;
        if (t1.size() != t2.size()) { cout << "0\n"; continue; }
        int l = 0, r = t1.size() - 1;
        while (t1[l] == t2[l]) ++l;
        while (t1[r] == t2[r]) --r;

        int ans = 0;
        L(i, 0, n - 1) {
            if (t1.size() < s1[i].size()) continue;
            bool flag = false;
            L(j, 0, t1.size() - s1[i].size()) {
                int m = s1[i].size();
                if (j <= l && j + m - 1 >= r && (eq(s1[i], t1, j, j + m - 1) &&
                      eq(s2[i], t2, j, j + m - 1))) {
                    flag = true; break;
                }
            }
            if (flag) ++ans;
        }
        cout << ans << '\n';
    }
}
