#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define FRE(p) freopen(#p".in", "r", stdin), freopen(#p".out", "w", stdout)
#define DBG(p) freopen(#p".in", "r", stdin), freopen("my.out", "w", stdout)
// #define int long long
#define LL long long
const int N = 5e6+5, M = 5e6+5, mod = 998244353;
using namespace std;
bool fst;
int n, q;
string s, t;
struct AC_automac {
    int tr[26][N>>1], fail[N>>1], dep[N>>1];
    vector<int> ids[N>>1];
    int tot = 0;
    void insert(string &s, int id) {
        int p = 0;
        for (auto c : s) {
            int ch = c-'a';
            if (!tr[ch][p]) tr[ch][p] = ++tot;
            p = tr[ch][p];
        }
        ids[p].emplace_back(id);
    }
    void build() {
        int p = 0;
        queue<int> q;
        rep(i, 0, 25) if (tr[i][p]) q.push(tr[i][p]);
        while (q.size()) {
            p = q.front(); q.pop();
            rep(ch, 0, 25) {
                if (!tr[ch][p]) tr[ch][p] = tr[ch][fail[p]];
                else fail[tr[ch][p]] = tr[ch][fail[p]], dep[tr[ch][p]] = dep[p]+1, q.push(tr[ch][p]);
            }
        }
    }
} t1, t2;
bool fed;
int cur[N], re[N];
signed main() {
    FASTIO;
    FRE(replace);
    // DBG(replace3);
    // cerr << ((&fed)-(&fst))/1024.0/1024 << '\n';
    cin >> n >> q;
    rep(i, 1, n) {
        cin >> s >> t;
        t1.insert(s, i), t2.insert(t, i);
    }
    t1.build(), t2.build();
    rep(term, 1, q) {
        cin >> s >> t;
        if (s.size() != t.size() || s == t) {
            cout << "0\n";
            continue;
        }
        int m = s.size();
        int maxpre = 0, maxsuf = 0, res = 0;
        while (maxpre < m && s[maxpre] == t[maxpre]) ++maxpre;
        while (maxsuf < m && s[m-maxsuf-1] == t[m-maxsuf-1]) ++maxsuf;
        vector<pair<int,int>> tmp;
        tmp.reserve(m);
        int curs = 0, curt = 0;
        for (int j = 0; j < m; ++j) {
            int cs = s[j]-'a', ct = t[j]-'a';
            curs = t1.tr[cs][curs], curt = t2.tr[ct][curt];
            tmp.emplace_back(curs, curt);
        }
        static int st[N], tp;
        for (int j = m-1; ~j; --j) {
            curs = tmp[j].first, curt = tmp[j].second;
            for (int x = curs; x; x = t1.fail[x]) {
                if (t1.dep[x]+maxpre >= j) {
                    for (auto it : t1.ids[x]) cur[it] = 1, st[++tp] = it;
                } else break;
            }
            if (m-j-1 <= maxsuf) {
                for (int x = curt; x; x = t2.fail[x])
                    for (auto it : t2.ids[x]) res += cur[it];
            }
        }
        while (tp>0) cur[st[tp--]]=0;
        cout << res << '\n';
    }
    return 0;
}