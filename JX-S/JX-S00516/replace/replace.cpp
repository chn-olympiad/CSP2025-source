#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'

constexpr int MAXN = 2e5 + 5;
constexpr int MAXC = 5e6 + 5;
constexpr long long MOD = 1e18 + 3;
constexpr int BASE = 131;
int n, m;
string s1[MAXN], s2[MAXN], t1[MAXN], t2[MAXN];
int ls[MAXN], rs[MAXN], lt[MAXN], rt[MAXN];

long long calc(string s) {
    __int128 res = 0;
    for (char c : s) {
        res = (res * BASE + (c - 'a') + 5) % MOD;
    }
    return res;
}

map<long long, vector<int>> cnt;
map<long long, vector<int>> toask;

struct Trie {

int sons[MAXC][26], tot;
int dfn[MAXC], sz[MAXC], num;

void init() {
    num = 0;
    rep (i, 0, tot) memset(sons[i], 0, sizeof (sons[i]));
    tot = 1;
}

int insert(string s) {
    int p = 1;
    for (char c : s) {
        int t = c - 'a';
        if (!sons[p][t]) sons[p][t] = ++tot;
        p = sons[p][t];
    }
    return p;
}

int query(string s) {
    int p = 1;
    for (char c : s) {
        int t = c - 'a';
        if (!sons[p][t]) break;
        p = sons[p][t];
    }
    return p;
}

void solve(int k) {
    dfn[k] = ++num;
    sz[k] = 1;
    rep (i, 0, 25) if (sons[k][i]) solve(sons[k][i]), sz[k] += sz[sons[k][i]];
}

} trie1, trie2;

namespace Fenwick {

int n;

int c[MAXC];
void init(int _n) {
    n = _n;
    rep (i, 1, n) c[i] = 0;
}

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += y;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) res += c[i];
    return res;
}

}

vector<pair<int, bool>> add[MAXC];
vector<pair<int, int>> ask[MAXC];
int ans[MAXN];

signed main() {
#ifndef INFTER
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    rep (i, 1, n) {
        cin >> s1[i] >> s2[i];
        if (s1[i] == s2[i]) continue;
        int m = s1[i].size();
        int l = 0, r = m - 1;
        while (l < m && s1[i][l] == s2[i][l]) l++;
        while (r >= 0 && s1[i][r] == s2[i][r]) r--;
        ls[i] = l, rs[i] = r;
        // cerr << l << " " << r << " " << calc(s1[i].substr(l, r - l + 1) + s2[i].substr(l, r - l + 1)) << endl;
        // if (498875927619626148ll == calc(s1[i].substr(l, r - l + 1) + s2[i].substr(l, r - l + 1))) cerr << s1[i] << " " << s2[i] << endl;
        cnt[calc(s1[i].substr(l, r - l + 1) + s2[i].substr(l, r - l + 1))].emplace_back(i);
    }
    rep (i, 1, m) {
        cin >> t1[i] >> t2[i];
        if (t1[i].size() != t2[i].size()) continue;
        int m = t1[i].size();
        int l = 0, r = m - 1;
        while (l < m && t1[i][l] == t2[i][l]) l++;
        while (r >= 0 && t1[i][r] == t2[i][r]) r--;
        lt[i] = l, rt[i] = r;
        // if (i == 106) { cerr << l << " " << r << " " << t1[i] << " " << t2[i] << endl;
        //     cerr << calc(t1[i].substr(l, r - l + 1) + t2[i].substr(l, r - l + 1)) << endl;
        //     cerr << cnt[calc(t1[i].substr(l, r - l + 1) + t2[i].substr(l, r - l + 1))].size() << endl;
        // }
        // cerr << l << " " << r << " " << calc(t1[i].substr(l, r - l + 1) + t2[i].substr(l, r - l + 1)) << endl;
        toask[calc(t1[i].substr(l, r - l + 1) + t2[i].substr(l, r - l + 1))].emplace_back(i);
    }

    // cerr << "OK" << endl;

    for (pair<long long, vector<int>> p : cnt) {
        // if (p.first == 498875927619626148) {
        // }
        // cerr << p.first << endl;
        vector<int> vec = p.second;
        trie1.init();
        trie2.init();
        vector<int> p1, p2;
        for (int x : vec) {
            string cur1 = s1[x].substr(0, ls[x]);
            string cur2 = s1[x].substr(rs[x] + 1);
            reverse(cur1.begin(), cur1.end());
            p1.emplace_back(trie1.insert(cur1));
            p2.emplace_back(trie2.insert(cur2));
        }
        // cerr << "OK" << endl;
        trie1.solve(1);
        trie2.solve(1);
        rep (i, 1, trie1.tot) {
            add[i].clear(), ask[i].clear();
        }
        // cerr << "OK" << endl;
        Fenwick::init(trie2.tot);
        vector<int> tim;
        for (int i = 0; i < vec.size(); i++) {
            int lx = trie1.dfn[p1[i]], rx = lx + trie1.sz[p1[i]];
            int ly = trie2.dfn[p2[i]], ry = ly + trie2.sz[p2[i]];
            // cerr << lx << " " << rx - 1 << " " << ly << " " << ry - 1 << endl;
            add[lx].emplace_back(make_pair(ly, 1));
            // if (p.first == 498875927619626148 && lx == 1) cerr << ly << " " << ry << endl;
            if (ry <= trie2.tot) add[lx].emplace_back(make_pair(ry, 0));
            if (rx <= trie1.tot) add[rx].emplace_back(make_pair(ly, 0));
            if (rx <= trie1.tot && ry <= trie2.tot) add[rx].emplace_back(make_pair(ry, 1));
            // add[lx].
        }
        // cerr << "OK" << endl;
        for (int x : toask[p.first]) {
            // if (p.first == 498875927619626148) cerr << x << endl;
            // cerr << "!" << x << endl;
            string cur1 = t1[x].substr(0, lt[x]);
            string cur2 = t1[x].substr(rt[x] + 1);
            reverse(cur1.begin(), cur1.end());
            int p1 = trie1.query(cur1);
            int p2 = trie2.query(cur2);
            // if (p.first == 498875927619626148 && x == 106) cerr << trie1.dfn[p1] << " --- " << trie2.dfn[p2] << endl;
            // if (p1 && p2) {
            // if (p.first == 498875927619626148 && x == 106) cerr << "!" << trie1.dfn[p1] << endl;
            ask[trie1.dfn[p1]].emplace_back(make_pair(trie2.dfn[p2], x));
            // }
        }
        // cerr << "OK" << endl;
        rep (i, 1, trie1.tot) {
            for (pair<int, bool> x : add[i]) {
                // if (p.first == 498875927619626148 && i == 1) cerr << "!!!!!!!!!!!!" << x.first << " " << x.second << endl;
                if (x.second) Fenwick::add(x.first, 1);
                else Fenwick::add(x.first, -1);
            }
            for (pair<int, int> x : ask[i]) {
                // if (p.first == 498875927619626148 && i == 1) cerr << "!!!!!!!!!!!!" << x.first << " " << x.second << endl;
                ans[x.second] = Fenwick::sum(x.first);
            }
        }
    }

    rep (i, 1, m) cout << ans[i] << endl;

    return 0;
}