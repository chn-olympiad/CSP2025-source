#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5 + 5, L = 5e6 + 5, B = 998244353;
const long long P = ((long long)1e18) + 3;
const pair<int, int> O = {0, 0};

string get() {
    string S;
    char c;
    while ((c = getchar()) < 'a' || c > 'z');
    S += c;
    while ((c = getchar()) >= 'a' && c <= 'z') S += c;
    return S;
}

string S[N][2];
int pos[N][2], res[N];
gp_hash_table<long long, int> M1, M2;
int tot, ch[L][26];

pair<int, int> getPos(string s1, string s2, int ty) {
    int pos1 = 0, pos2 = s1.size() - 1;
    while (s1[pos1] == s2[pos1]) ++pos1;
    while (s1[pos2] == s2[pos2]) --pos2;
    long long key = 117;
    for (int j = pos1; j <= pos2; ++j) {
        key = ((__int128)key * B + s1[j]) % P;
        key = ((__int128)key * B + s2[j]) % P;
    }
    if (ty) {
        if (M1.find(key) == M1.end() || M2.find(key) == M2.end()) return O;
    }
    if (!M1[key]) M1[key] = ++tot;
    int cur1 = M1[key];
    for (int j = pos1 - 1; ~j; --j) {
        int c = s1[j] - 'a';
        if (!ch[cur1][c]) {
            if (ty) return O;
            ch[cur1][c] = ++tot;
        }
        cur1 = ch[cur1][c];
    }
    if (!M2[key]) M2[key] = ++tot;
    int cur2 = M2[key];
    for (int j = pos2 + 1; j < (int)s1.size(); ++j) {
        int c = s1[j] - 'a';
        if (!ch[cur2][c]) {
            if (ty) return O;
            ch[cur2][c] = ++tot;
        }
        cur2 = ch[cur2][c];
    }
    if (ty) assert(cur1 && cur2);
    return {cur1, cur2};
}

int dfn[L], siz[L], dfn_c;

void dfs(int x) {
    dfn[x] = ++dfn_c, siz[x] = 1;
    for (int i = 0; i < 26; ++i) {
        if (ch[x][i]) dfs(ch[x][i]), siz[x] += siz[ch[x][i]];
    }
}

int sum[L];

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        S[i][0] = get(), S[i][1] = get();
    }
    for (int i = 1; i <= q; ++i) {
        string t1 = get(), t2 = get();
        if (t1.size() != t2.size()) continue;
        pair<int, int> w = getPos(t1, t2, 0);
        pos[i][0] = w.first, pos[i][1] = w.second;
    }
    for (int i = 1; i <= tot; ++i) {
        if (!dfn[i]) dfs(i);
    }
    assert(dfn_c == tot);
    vector< array<int, 3> > qry;
    for (int i = 1; i <= q; ++i) {
        qry.push_back({dfn[pos[i][0]], dfn[pos[i][1]], i});
    }
    vector< array<int, 3> > mdf;
    for (int i = 1; i <= n; ++i) {
        if (S[i][0] == S[i][1]) continue;
        pair<int, int> w = getPos(S[i][0], S[i][1], 1);
        if (w == O) continue;
        mdf.push_back({dfn[w.first], dfn[w.second], 1});
        mdf.push_back({dfn[w.first], dfn[w.second] + siz[w.second], -1});
        mdf.push_back({dfn[w.first] + siz[w.first], dfn[w.second], -1});
        mdf.push_back({dfn[w.first] + siz[w.first], dfn[w.second] + siz[w.second], 1});
    }
    sort(mdf.begin(), mdf.end()), sort(qry.begin(), qry.end());
    int cur = 0;
    for (auto [a, b, c] : qry) {
        while (cur < mdf.size() && mdf[cur][0] <= a) {
            for (int i = mdf[cur][1]; i <= tot; i += i & -i) sum[i] += mdf[cur][2];
            ++cur;
        }
        for (int i = b; i; i -= i & -i) res[c] += sum[i];
    }
    for (int i = 1; i <= q; ++i) {
        printf("%d\n", res[i]);
    }
    return 0;
}