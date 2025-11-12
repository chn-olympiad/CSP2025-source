#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
int n, q;
pair<string, string> s[maxn], t[maxn];
namespace pts_B {
    bool pd(string s) {
        int res = 0;
        for (auto ch : s) {
            if (ch != 'a' && ch != 'b') return false;
            if (ch == 'b') res++;
            if (res > 1) return false;
        }
        return true;
    }
    bool check() {
        for (int i = 1; i <= n; i++) if (!pd(s[i].first) || !pd(s[i].second)) return false;
        for (int i = 1; i <= q; i++) if (!pd(t[i].first) || !pd(t[i].second)) return false;
        return true;
    }
    int locate(string s) {
        for (int i = 0; i < s.size(); i++) 
            if (s[i] == 'b') return i;
        return 0;
    }
    void work() {
        pair<int, int> ss[maxn], tt[maxn];
        int sss[n + 1], ttt[q + 1];
        for (int i = 1; i <= n; i++) ss[i] = {locate(s[i].first), locate(s[i].second)};
        for (int i = 1; i <= q; i++) tt[i] = {locate(t[i].first), locate(t[i].second)};
        for (int i = 1; i <= n; i++) sss[i] = ss[i].second - ss[i].first;
        for (int i = 1; i <= q; i++) ttt[i] = tt[i].second - tt[i].first;
        vector<tuple<int, int, int>> v;
        for (int i = 1; i <= n; i++) v.push_back(make_tuple(sss[i], ss[i].first, s[i].second.size() - ss[i].second - 1));
        // dif = , l <= , r <=
        for (int p = 1; p <= q; p++) {
            int l = tt[p].first, r = t[p].second.size() - tt[p].second - 1, dif = ttt[p], cnt = 0;
            for (auto node : v) {
                int ddif = get<0>(node), ll = get<1>(node), rr = get<2>(node);
                if (ddif == dif && ll <= l && rr <= r) cnt++;
            }
            cout << cnt << "\n";
        }
        exit(0);
    }
}
namespace pts_1_8_plus_13_14 {
    bool check() { return n * q <= 1e8; }
    void work() {
        vector<tuple<int, int, string, string>> v;
        for (int i = 1; i <= n; i++) {
            int mn = s[i].first.size(), mx = -1;
            for (int j = 0; j < s[i].first.size(); j++)
                if (s[i].first[j] != s[i].second[j]) {
                    mn = min(mn, j);
                    mx = max(mx, j);
                }
            v.push_back(make_tuple(mn, s[i].second.size() - mx - 1, s[i].first.substr(mn, mx - mn + 1), s[i].second.substr(mn, mx - mn + 1)));
        }
        for (int i = 1; i <= q; i++) {
            int mn = t[i].first.size(), mx = -1, ans = 0;
            for (int j = 0; j < t[i].first.size(); j++)
                if (t[i].first[j] != t[i].second[j]) {
                    mn = min(mn, j);
                    mx = max(mx, j);
                }
            int l = mn, r = t[i].second.size() - mx - 1;
            string from = t[i].first.substr(mn, mx - mn + 1), to = t[i].second.substr(mn, mx - mn + 1);
            for (auto tp : v) {
                if (from == get<2>(tp) && to == get<3>(tp) && get<0>(tp) <= l && get<1>(tp) <= r) ans++;
            }
            cout << ans << "\n";
        }
        exit(0);
    }
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i].first >> s[i].second;
    for (int i = 1; i <= q; i++) cin >> t[i].first >> t[i].second;
    if (pts_1_8_plus_13_14::check()) pts_1_8_plus_13_14::work();
    else pts_B::work();
    return 0;
}

// 50 pts