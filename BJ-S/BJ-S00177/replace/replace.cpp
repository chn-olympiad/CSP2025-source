#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr int base = 536527;
int n, q;
string s, t;
map<pair<ull, ull>, map<ull, multiset<ull>>> mp;
inline ull calc(const string &s, int l, int r) {
    ull res = 0;
    for (int i = l; i <= r; i++)
        res = res * base + s[i];
    return res;
}
inline int F(const multiset<ull> &s, const multiset<ull> &t) {
    if (s.size() < t.size()) {
        int f = 0;
        for (ull i : s) f += t.count(i);
        return f;
    }
    else {
        int f = 0;
        for (ull i : t) f += s.count(i);
        return f;
    }
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s >> t;
        if (s == t) continue;
        int l = 0;
        for (int j = 0; j < s.size(); j++)
            if (s[j] != t[j]) {
                l = j;
                break;
            }
        int r = 0;
        for (int j = s.size() - 1; j >= 0; j--)
            if (s[j] != t[j]) {
                r = j;
                break;
            }
        mp[{calc(s, l, r), calc(t, l, r)}][calc(s, 0, l-1)].insert(calc(s, r+1, s.size()-1));
    }
    while (q--) {
        cin >> s >> t;
        if (s.size() != t.size()) {
            cout << 0 << endl;
            continue;
        }
        int l = 0;
        for (int j = 0; j < s.size(); j++)
            if (s[j] != t[j]) {
                l = j;
                break;
            }
        int r = 0;
        for (int j = s.size() - 1; j >= 0; j--)
            if (s[j] != t[j]) {
                r = j;
                break;
            }
        long long res = 0;
        multiset<ull> st;
        ull tmp = 0;
        st.insert(0);
        for (int j = r+1; j < s.size(); j++) {
            tmp = tmp * base + s[j];
            st.insert(tmp);
        }
        tmp = 0;
        ull Pow = 1;
        ull c_s_l_r = calc(s, l, r), c_t_l_r = calc(t, l, r);
        if (mp.find({c_s_l_r, c_t_l_r}) == mp.end()) {
            cout << 0 << endl;
            continue;
        }
        for (int j = l; j >= 0; j--) {
            if (j != l) tmp += Pow * s[j], Pow *= base;
            if (mp[{c_s_l_r, c_t_l_r}].find(tmp) == mp[{c_s_l_r, c_t_l_r}].end()) continue;
            res += F(st, mp[{c_s_l_r, c_t_l_r}][tmp]);
        }
        cout << res << endl;
    }
    return 0;
}
