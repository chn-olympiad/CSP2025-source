# include <bits/stdc++.h>
# define maxn 200100
# define inf 0x3f3f3f3f
# define ull unsigned long long
# define mod 1000000007
# define mem(a, val) memset(a, val, sizeof(a))
# define rep(i, j, k) for(int i = j; i <= k; ++i)
# define per(i, j, k) for(int i = j; i >= k; --i)
using namespace std;

struct Fenwick {int op, x, y, val;};
const int V = 2500000;
int n, q, num, m;
int L[maxn], R[maxn], L1[maxn], R1[maxn], X[maxn], Y[maxn];
int ans[maxn];
string s1[maxn], s2[maxn], t1[maxn], t2[maxn];
ull Pow[V + 5];
vector<int> vec1[maxn], vec2[maxn];
map<pair<ull, ull>, int> mp;
Fenwick b[maxn * 5];

namespace fenwick {
    # define lowbit(x) (x & -x)
    int tree[V + 5];
    inline void update(int pos, int val) {while(pos <= m) tree[pos] += val, pos += lowbit(pos);}
    inline int query(int pos) {int sum = 0; while(pos) sum += tree[pos], pos -= lowbit(pos); return sum;}
}

namespace Trie {
    int nxt1[V + 5][26], nxt2[V + 5][26], dfn1[V + 5], siz1[V + 5], dfn2[V + 5], siz2[V + 5], tim1, tim2, tot1, tot2;
    inline void init() {tot1 = tot2 = 1; mem(nxt1[1], 0); mem(nxt2[1], 0); tim1 = tim2 = 0;}
    inline int add(bool flag) {
        if(flag == 0) {mem(nxt1[tot1 + 1], 0); return (++tot1);}
        else {mem(nxt2[tot2 + 1], 0); return (++tot2);}
    }

    inline int insert1(int id, int lim) {
        int pos = 1;
        per(i, lim, 0) {
            int val = s1[id][i] - 'a';
            (nxt1[pos][val] ? 0 : nxt1[pos][val] = add(0)), pos = nxt1[pos][val];
        }
        return pos;
    }

    inline int insert2(int id, int lim) {
        int pos = 1, lim1 = (int)s1[id].size() - 1;
        rep(i, lim, lim1) {
            int val = s1[id][i] - 'a';
            (nxt2[pos][val] ? 0 : nxt2[pos][val] = add(1)), pos = nxt2[pos][val];
        }
        return pos;
    }

    inline int solve1(int id, int lim) {
        int pos = 1;
        per(i, lim, 0) {
            int val = t1[id][i] - 'a';
            if(nxt1[pos][val] == 0) return pos;
            else pos = nxt1[pos][val];
        }
        return pos;
    }

    inline int solve2(int id, int lim) {
        int pos = 1, lim1 = (int)t1[id].size() - 1;
        rep(i, lim, lim1) {
            int val = t1[id][i] - 'a';
            if(nxt2[pos][val] == 0) return pos;
            else pos = nxt2[pos][val];
        }
        return pos;
    }
} using namespace Trie;

namespace Solve {
    inline bool cmp(Fenwick x, Fenwick y) {return x.x == y.x ? x.op < y.op : x.x < y.x;}
    inline void dfs1(int pos) {dfn1[pos] = ++tim1; siz1[pos] = 1; rep(i, 0, 25) if(nxt1[pos][i]) dfs1(nxt1[pos][i]), siz1[pos] += siz1[nxt1[pos][i]];}
    inline void dfs2(int pos) {dfn2[pos] = ++tim2; siz2[pos] = 1; rep(i, 0, 25) if(nxt2[pos][i]) dfs2(nxt2[pos][i]), siz2[pos] += siz2[nxt2[pos][i]];}

    void solve(int id) {
        init(); int cnt1 = vec1[id].size(), cnt2 = vec2[id].size(), tmp1 = 0;
        for(int i : vec1[id]) X[i] = insert1(i, L[i] - 1), Y[i] = insert2(i, R[i] + 1);
        dfs1(1); dfs2(1); m = tim2;
        for(int i : vec1[id]) {
            int u1 = X[i], u2 = Y[i];
            b[++tmp1] = {0, dfn1[u1], dfn2[u2], 1}, b[++tmp1] = {0, dfn1[u1], dfn2[u2] + siz2[u2], -1};
            b[++tmp1] = {0, dfn1[u1] + siz1[u1], dfn2[u2], -1}, b[++tmp1] = {0, dfn1[u1] + siz1[u1], dfn2[u2] + siz2[u2], 1};
        }
        for(int i : vec2[id]) {
            int u1 = solve1(i, L1[i] - 1), u2 = solve2(i, R1[i] + 1);
            b[++tmp1] = {1, dfn1[u1], dfn2[u2], i};
        }
        sort(b + 1, b + tmp1 + 1, cmp);
        memset(fenwick::tree, 0, 4 * (m + 1));
        rep(i, 1, tmp1) {
            if(b[i].op == 0) fenwick::update(b[i].y, b[i].val);
            else ans[b[i].val] = fenwick::query(b[i].y);
        }
    }
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    Pow[0] = 1; rep(i, 1, V) Pow[i] = 52ull * Pow[i - 1] % mod;
    rep(i, 1, n) {
        cin >> s1[i] >> s2[i]; int len = s1[i].size(); ull res1 = 0, res2 = 0; L[i] = -1;
        rep(j, 0, len - 1) if(s1[i][j] != s2[i][j]) {
            L[i] = (L[i] == -1 ? j : L[i]), R[i] = j;
            res1 += (s1[i][j] - s2[i][j] + 26) * Pow[j - L[i]]; res1 %= mod;
            res2 += (s1[i][j] + s2[i][j]) * Pow[j - L[i]]; res2 %= mod;
        }
        if(mp[{res1, res2}] == 0) mp[{res1, res2}] = ++num;
        vec1[mp[{res1, res2}]].push_back(i);
    }
    rep(i, 1, q) {
        cin >> t1[i] >> t2[i]; int len = t1[i].size(); ull res1 = 0, res2 = 0; L1[i] = -1;
        if(t1[i].size() != t2[i].size()) continue;
        rep(j, 0, len - 1) if(t1[i][j] != t2[i][j]) {
            L1[i] = (L1[i] == -1 ? j : L1[i]), R1[i] = j;
            res1 += (t1[i][j] - t2[i][j] + 26) * Pow[j - L1[i]]; res1 %= mod;
            res2 += (t1[i][j] + t2[i][j]) * Pow[j - L1[i]]; res2 %= mod;
        }
        if(mp.find({res1, res2}) == mp.end()) continue;
        vec2[mp[{res1, res2}]].push_back(i);
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        int id = it -> second;
        if(vec1[id].empty() || vec2[id].empty()) continue;
        Solve::solve(id);
    }
    rep(i, 1, q) cout << ans[i] << '\n';
    return 0;
}
