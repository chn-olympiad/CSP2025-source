#include <bits/stdc++.h>
using namespace std;

unsigned long long get_hash (string s) {
    unsigned long long res = 0;
    for (char ch : s) {
        res = res * 27 + ch - 'a' + 1;
    }
    return res;
}

int main () {

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    map<unsigned long long, vector<unsigned long long>> mp;
    string s, t;
    for (int i = 1; i <= n; i++) {
        cin >> s >> t;
        mp[get_hash(s)].emplace_back(get_hash(t));
        // cout << "  " << get_hash(ss) << ' ' << get_hash(tt) << ' ' << ss << ' ' << tt << '\n';
    }
    for (auto &i : mp) {
        sort(i.second.begin(), i.second.end());
    }
    while (q--) {
        cin >> s >> t;
        // cout << "  " << get_hash(ss) << ' ' << get_hash(tt) << ' ' << ss << ' ' << tt << '\n';
        int len = s.size(), mn = 0, mx = len - 1;
        for (; mn < len && s[mn] == t[mn]; mn++);
        for (; ~mx && s[mx] == t[mx]; mx--);
        unsigned long long th = get_hash(t);
        int ans = 0;
        for (int i = 0; i <= mn; i++) {
            unsigned long long tmps = 0, tmpt = 0;
            for (int j = i; j < len; j++) {
                tmps = tmps * 27 + s[j] - 'a' + 1;
                tmpt = tmpt * 27 + t[j] - 'a' + 1;
                vector<unsigned long long> &qwq = mp[tmps];
                if (j >= mx) ans += upper_bound(qwq.begin(), qwq.end(), tmpt) - qwq.begin() - (lower_bound(qwq.begin(), qwq.end(), tmpt) - qwq.begin());
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

// qwq. fei le, zhi hui bao li.
