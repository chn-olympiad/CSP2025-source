#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 200010;
int n, q;
ll ans[N];
string s1[N], s2[N], t1[N], t2[N];
namespace sub2 {
    vector<int> sd[N], td[N];
    int e[N], cnt;
    int ee[N * 2], cntt;
    int sp1[N], sp2[N], tp1[N], tp2[N];
    int sv[N], tv[N];
    int T[N];
    void upd(int x, int v) {
        while (x <= cntt) {
            T[x] += v;
            x += x & (-x);
        }
    }
    int qry(int x) {
        int v = 0;
        while (x) {
            v += T[x];
            x -= x & (-x);
        }
        return v;
    }
    void solve() {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < s1[i].size(); j++) if (s1[i][j] == 'b') sp1[i] = j;
            for (int j = 0; j < s2[i].size(); j++) if (s2[i][j] == 'b') sp2[i] = j;
            sv[i] = (int)(s1[i].size()) - sp1[i];
        }
        for (int i = 1; i <= q; i++) {
            for (int j = 0; j < t1[i].size(); j++) if (t1[i][j] == 'b') tp1[i] = j;
            for (int j = 0; j < t2[i].size(); j++) if (t2[i][j] == 'b') tp2[i] = j;
            e[i] = tp2[i] - tp1[i];
            tv[i] = (int)(t1[i].size()) - tp1[i];
        }
        sort(e + 1, e + 1 + q);
        cnt = unique(e + 1, e + 1 + q) - e - 1;
        for (int i = 1; i <= n; i++) {
            int x = lower_bound(e + 1, e + 1 + cnt, sp2[i] - sp1[i]) - e;
            if (e[x] == sp2[i] - sp1[i]) sd[x].push_back(i);
        }
        for (int i = 1; i <= q; i++) {
            int x = lower_bound(e + 1, e + 1 + cnt, tp2[i] - tp1[i]) - e;
            if (e[x] == tp2[i] - tp1[i]) td[x].push_back(i);
        }
        for (int x = 1; x <= cnt; x++) {
            // 能替换当且仅当
            // sp1[j] <= tp1[i], s1[j].size() - sp1[j] + tp1[i] <= t1[i].size()
            // sp1[j] <= tp1[i], s1[j].size() - sp1[j] <= t1[i].size() - tp1[i]
            sort(td[x].begin(), td[x].end(), [&](const auto &i, const auto &j) {
                return tv[i] < tv[j];
            });
            sort(sd[x].begin(), sd[x].end(), [&](const auto &i, const auto &j) {
                return sv[i] < sv[j];
            });
            cntt = 0;
            for (int i : td[x]) {
                ee[++cntt] = tp1[i];
            }
            for (int i : sd[x]) {
                ee[++cntt] = sp1[i];
            }
            sort(ee + 1, ee + 1 + cntt);
            cntt = unique(ee + 1, ee + 1 + cntt) - ee - 1;
            for (int i = 1; i <= cntt; i++) T[i] = 0;
            int pos = 0;
            for (int i : td[x]) {
                while (pos < sd[x].size() && sv[sd[x][pos]] <= tv[i]) {
                    int l = lower_bound(ee + 1, ee + 1 + cntt, sp1[sd[x][pos]]) - ee;
                    upd(l, 1);
                    pos++;
                }
                int l = lower_bound(ee + 1, ee + 1 + cntt, tp1[i]) - ee;
                ans[i] += qry(l);
            }
            // for (int i : td[x]) {
            //     for (int j : sd[x]) {
            //         if (sp1[j] <= tp1[i] && sv[j] <= tv[i]) ans[i]++;
            //     }
            // }
        }
    }
}
namespace sub1 {
    constexpr int P1 = 998244353, P2 = 1000000007;
    map<pair<ll, ll>, int> mp;
    void solve() {
        for (int i = 1; i <= n; i++) {
            ll R1 = 0, R2 = 0;
            ll v1 = 0, v2 = 0;
            for (int j = 0; j < s1[i].size(); j++) {
                v1 = (v1 * 137 + s1[i][j]) % P1;
                v2 = (v2 * 137 + s1[i][j]) % P2;
            }
            R1 = (v1 << 31) | v2;
            v1 = 0, v2 = 0;
            for (int j = 0; j < s2[i].size(); j++) {
                v1 = (v1 * 137 + s2[i][j]) % P1;
                v2 = (v2 * 137 + s2[i][j]) % P2;
            }
            R2 = (v1 << 31) | v2;
            mp[{R1, R2}]++;
        }
        for (int i = 1; i <= q; i++) if (t1[i].size() == t2[i].size()) {
            int L = 0, R = (int)t1[i].size() - 1;
            for (int j = 0; j < t1[i].size(); j++) {
                if (t1[i][j] == t2[i][j]) L++;
                else break;
            }
            L = min(L, (int)t1[i].size() - 1);
            for (int j = (int)t1[i].size() - 1; j >= 0; j--) {
                if (t1[i][j] == t2[i][j]) R--;
                else break;
            }
            R = max(R, 0);
            for (int j = 0; j <= L; j++) {
                ll v1 = 0, v2 = 0, v3 = 0, v4 = 0;
                for (int k = j; k < t1[i].size(); k++) {
                    v1 = (v1 * 137 + t1[i][k]) % P1;
                    v2 = (v2 * 137 + t1[i][k]) % P2;
                    v3 = (v3 * 137 + t2[i][k]) % P1;
                    v4 = (v4 * 137 + t2[i][k]) % P2;
                    if (k >= R) {
                        ans[i] += mp[{v1 << 31 | v2, v3 << 31 | v4}];
                    }
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    bool onlyab = 1;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
        int bnum, extra;
        bnum = 0, extra = 0;
        for (int j = 0; j < s1[i].size(); j++) {
            if (s1[i][j] == 'a');
            else if (s1[i][j] == 'b') bnum++;
            else extra = 1;
        }
        if (bnum != 1 && extra) onlyab = 0;
        bnum = 0, extra = 0;
        for (int j = 0; j < s2[i].size(); j++) {
            if (s2[i][j] == 'a');
            else if (s2[i][j] == 'b') bnum++;
            else extra = 1;
        }
        if (bnum != 1 && extra) onlyab = 0;
    }
    for (int i = 1; i <= q; i++) {
        cin >> t1[i] >> t2[i];
        int bnum, extra;
        bnum = 0, extra = 0;
        for (int j = 0; j < t1[i].size(); j++) {
            if (t1[i][j] == 'a');
            else if (t1[i][j] == 'b') bnum++;
            else extra = 1;
        }
        if (bnum != 1 && extra) onlyab = 0;
        bnum = 0, extra = 0;
        for (int j = 0; j < t2[i].size(); j++) {
            if (t2[i][j] == 'a');
            else if (t2[i][j] == 'b') bnum++;
            else extra = 1;
        }
        if (bnum != 1 && extra) onlyab = 0;
    }
    if (onlyab) {
        sub2::solve();
    } else {
        sub1::solve();
    }
    for (int i = 1; i <= q; i++) {
        if (t1[i].size() != t2[i].size()) ans[i] = 0;
        cout << ans[i] << '\n';
    }
}