#include <bits/stdc++.h>
#define ull unsigned long long

void Freopen() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
}

using namespace std;
const int N = 2e5 + 10, M = 5e6 + 10, inf = 1e9, mod = 998244353;
const ull pw = 1333337;

int n, q, tot;

// char s1[M], s2[M];

string s1[N], s2[N];
string t1[N], t2[N];

map< pair< string, string>, int> mp;
string tmp1, tmp2;

struct node {
    int x, y, id;

    bool operator < ( const node & rhs) const {
        if (x == rhs.x) {
            if (y == rhs.y) return id < rhs.id;
            return y < rhs.y;
        }

        return x < rhs.x;
    }
} ;

vector< node> vec[N];

struct node2 {
    int x, y;
    ull hsh1, hsh2;
} ;

vector< node2> vec2[N];

int ans[N];
ull hsh1[M], hsh2[M];

struct bit {
    int tr[M];

    void add( int u, int v) {
        u ++;
        for (; u < M; u += (u & -u)) tr[u] += v;
    }

    int ask( int u, int res = 0) {
        u ++;
        for (; u; u -= (u & -u)) res += tr[u];
        return res;
    }
} b;

void solve1000() {
    for ( int i = 1; i <= n; i ++) {
        int len = (int)s1[i].size() - 1;

        int l = 1, r = len;
        while (s1[i][l] == s2[i][l] && l <= len) l ++;
        while (s1[i][r] == s2[i][r] && r >= 1) r --;

        // cout << l << ' ' << r << '\n';

        if (l > len) continue ;

        tmp1.clear(), tmp2.clear();
        for ( int j = l; j <= r; j ++) {
            tmp1.push_back(s1[i][j]);
            tmp2.push_back(s2[i][j]);
        }

        ull hsh1 = 0, hsh2 = 0;
        for ( int j = l - 1; j >= 1; j --) hsh1 = hsh1 * pw + s1[i][j];
        for ( int j = r + 1; j <= len; j ++) hsh2 = hsh2 * pw + s1[i][j];

        if (! mp.count({tmp1, tmp2})) mp[{tmp1, tmp2}] = ++ tot;
        // cout << l - 1 << ' ' << r << '\n';
        vec2[mp[{tmp1, tmp2}]].push_back({l - 1, len - r, hsh1, hsh2});

        // cout << '\n';
    }

    for ( int i = 1; i <= q; i ++) {
        int len1 = (int)t1[i].size() - 1, len2 = (int)t2[i].size() - 1;

        if (len1 != len2) {
            cout << "0\n";
            continue ;
        }

        int l = 1, r = len1;
        while (t1[i][l] == t2[i][l] && l <= len1) l ++;
        while (t1[i][r] == t2[i][r] && r >= 1) r --;

        if (l > len1) {
            cout << "0\n";
            continue ;
        }

        tmp1.clear(), tmp2.clear();

        for ( int j = l - 1, k = 1; j >= 1; j --, k ++) hsh1[k] = hsh1[k - 1] * pw + t1[i][j];
        for ( int j = r + 1, k = 1; j <= len1; j ++, k ++) hsh2[k] = hsh2[k - 1] * pw + t1[i][j];
        for ( int j = l; j <= r; j ++) {
            tmp1.push_back(t1[i][j]);
            tmp2.push_back(t2[i][j]);
        }

        int ans = 0;

        if (! mp.count({tmp1, tmp2})) {
            cout << "0\n";
            continue ;
        }

        for ( auto v : vec2[mp[{tmp1, tmp2}]]) {
            if (v.x > l - 1 || v.y > len1 - r) continue ;
            if (v.hsh1 == hsh1[v.x] && v.hsh2 == hsh2[v.y]) ans ++;
        }

        cout << ans << '\n';
    }
}

signed main() {
    Freopen();

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    int F = 1;

    for ( int i = 1; i <= n; i ++) {
        cin >> s1[i] >> s2[i];
        s1[i] = " " + s1[i], s2[i] = " " + s2[i];

        int len = (int)s1[i].size() - 1, cnt1 = 0, cnt2 = 0;
        for ( int j = 1; j <= len; j ++) {
            if ((s1[i][j] != 'a' && s1[i][j] != 'b') || (s2[i][j] != 'a' && s2[i][j] != 'b')) F = 0;
            if (s1[i][j] == 'b') cnt1 ++;
            if (s2[i][j] == 'b') cnt2 ++;
        }

        if (cnt1 != 1 || cnt2 != 1) F = 0;
    }

    for ( int i = 1; i <= q; i ++) {
        cin >> t1[i] >> t2[i];
        t1[i] = " " + t1[i], t2[i] = " " + t2[i];

        int len = (int)t1[i].size() - 1, cnt1 = 0, cnt2 = 0;
        int len2 = (int)t2[i].size() - 1;
        for ( int j = 1; j <= len; j ++) {
            if (t1[i][j] != 'a' && t1[i][j] != 'b') F = 0;
            if (t1[i][j] == 'b') cnt1 ++;
        }

        for ( int j = 1; j <= len2; j ++) {
            if (t2[i][j] != 'a' && t2[i][j] != 'b') F = 0;
            if (t2[i][j] == 'b') cnt2 ++;
        }

        if (cnt1 != 1 || cnt2 != 1) F = 0;        
    }

    if (F) {
        for ( int i = 1; i <= n; i ++) {
            int len = (int)s1[i].size() - 1;

            int l = 1, r = len;
            while (s1[i][l] == s2[i][l] && l <= len) l ++;
            while (s1[i][r] == s2[i][r] && r >= 1) r --;

            if (l > len) continue ;

            tmp1.clear(), tmp2.clear();
            for ( int j = l; j <= r; j ++) {
                tmp1.push_back(s1[i][j]);
                tmp2.push_back(s2[i][j]);
            }

            if (! mp.count({tmp1, tmp2})) mp[{tmp1, tmp2}] = ++ tot;
            vec[mp[{tmp1, tmp2}]].push_back({l - 1, len - r, 0});
        }

        for ( int i = 1; i <= q; i ++) {
            int len1 = (int)t1[i].size() - 1, len2 = (int)t2[i].size() - 1;

            if (len1 != len2) continue ;

            int l = 1, r = len1;
            while (t1[i][l] == t2[i][l] && l <= len1) l ++;
            while (t1[i][r] == t2[i][r] && r >= 1) r --;

            if (l > len1) continue ;

            tmp1.clear(), tmp2.clear();
            for ( int j = l; j <= r; j ++) {
                tmp1.push_back(t1[i][j]);
                tmp2.push_back(t2[i][j]);
            }

            if (! mp.count({tmp1, tmp2})) mp[{tmp1, tmp2}] = ++ tot;
            vec[mp[{tmp1, tmp2}]].push_back({l - 1, len1 - r, i});
        }

        for ( int i = 1; i <= tot; i ++) {
            sort(vec[i].begin(), vec[i].end());

            for ( auto v : vec[i]) {
                if (v.id == 0) b.add(v.y, 1);
                else ans[v.id] = b.ask(v.y);
            }

            for ( auto v : vec[i])
                if (v.id == 0) b.add(v.y, -1);
        }

        for ( int i = 1; i <= q; i ++)
            cout << ans[i] << '\n';

        return 0;   
    }

    solve1000();

    return 0;
}

/*
想性质，就有 70 分。
我真的成为了暴力王。
考虑 $B$ 性质。

我去？
好像会正解了？

首先一个 $i$ 肯定最多一个贡献。

只需要找到 $s1$ 与 $s2$ 本质不同的位置，看做一个二元组，把所有相同的二元组放进一个等价类。

对于等价类中的一个元素，有一个二元组 $(a,b)$，对于询问也有一个二元组 $(a,b)$。

就是个二维偏序啊，爽爽爽爽！！！

完了，假了，但是可以过 $B$ 性质，哎。

但是感觉暴力可以过啊。
*/