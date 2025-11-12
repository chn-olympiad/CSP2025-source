#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 5e6 + 20;
const int MOD = 200904101;
const int X = 31;
const int A = 5000001;

struct Query {
    int id, hs, x;
};

int n, q, tot, mp[30][30], ans[NR], pw[NR];
string s1, s2;
unordered_map < int, int > tr, cnt;
vector < int > vec[NR], e[NR], tmp;
vector < Query > qry[NR];

inline int code(int x, char y, char z) {
    return A * mp[y - 'a'][z - 'a'] + x;
}

inline void ins(int x, int y, int z) {
    int p = 1;
    for (int i = x; i < y; ++i) {
        int t = tr[code(p, s1[i], s2[i])];
        if (!t) tr[code(p, s1[i], s2[i])] = t = ++ tot, e[p].push_back(t);
        p = t;
    }
    vec[p].push_back(z);
}

inline void add(int x, int y, int w, int o) {
    int p = 1, pp = 0;
    for (int i = x; i < y; ++i) {
        int t = tr[code(p, s1[i], s2[i])];
        if (i <= w) pp = p;
        if (!t) break;
        p = t;
    }
    for (auto i : tmp) qry[p].push_back((Query){o, i, 1}), qry[pp].push_back((Query){o, i, -1});
}

inline void dfs(int x) {
    for (auto i : vec[x]) cnt[i] ++;
    for (auto i : qry[x]) ans[i.id] += cnt[i.hs] * i.x;
    for (auto i : e[x]) dfs(i);
    for (auto i : vec[x]) cnt[i] --;
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> n >> q, pw[0] = 1;
    for (int i = 1; i < NR; ++i) pw[i] = pw[i - 1] * X % MOD;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j) mp[i][j] = tot, tot ++;
    tot = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> s1 >> s2;
        int hs = 0, len = 0, m = s1.size();
        for (int j = 0; j < m; ++j) {
            if (s1[j] != s2[j]) break;
            len ++, hs = (hs * X + s1[j]) % MOD;
        }
        ins(len, m, hs);
    }
    for (int i = 1; i <= q; ++i) {
        cin >> s1 >> s2;
        int hs = 0, len1 = 0, len2 = 0, m = s1.size();
        tmp.clear();
        for (int j = 0; j < m; ++j) {
            if (s1[j] != s2[j]) break;
            len1 ++;
        }
        tmp.push_back(0);
        for (int j = len1 - 1; j >= 0; --j) {
            hs = (hs + s1[j] * pw[len1 - 1 - j]) % MOD;
            tmp.push_back(hs);
        }
        for (int j = m - 1; j >= 0; --j) {
            if (s1[j] != s2[j]) break;
            len2 ++;
        }
        add(len1, m, m - len2 - 1, i);
    }
    dfs(1);
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    return 0;
}