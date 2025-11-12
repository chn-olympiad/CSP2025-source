#include <bits/stdc++.h>
#define rep(x, y, z) for (int x = (y); x <= (z); ++x)
#define per(x, y, z) for (int x = (y); x >= (z); --x)
#define pii pair<int, int>
#define fi first
#define se second
#define sz(x) (int)x.size()
using namespace std;
constexpr int maxn = 2e5 + 5, maxl = 2.5e6 + 5;
struct KMP {
    string s; vector<int> fail;
    void init() {
        s = " " + s;
        fail.resize(sz(s));
        fail[1] = fail[0] = 0;
        rep(i, 2, sz(s) - 1) {
            int &j = fail[i]; j = fail[i - 1];
            while (j && s[j + 1] != s[i]) j = fail[j];
            if (s[j + 1] == s[i]) ++j;
        }
    }
    vector<int> find(const string& t) {
        int j = 0; vector<int> res;
        rep(i, 1, sz(t) - 1) {
            if (s[j + 1] == t[i]) {
                ++j;
                if (j == sz(s) - 1) {
                    res.push_back(i);
                    j = fail[j];
                } 
            } else {
                while (j && s[j + 1] != t[i]) j = fail[j];
                if (s[j + 1] == t[i]) ++j;
            }
        }
        return res;
    }
} s1[maxn], s2[maxn];
int n, q;
bool mark[maxl];
vector<int> merge(const vector<int>& v1, const vector<int>& v2) {
    vector<int> res;
    for (auto x : v1) mark[x] = true;
    for (auto x : v2) if (mark[x]) res.push_back(x);
    for (auto x : v1) mark[x] = false;
    return res;
}
void solve(const string& t1, const string& t2) {
    if (n > 2000) {
        cout << 0 << endl;
        return ;
    }
    int lst = 0, fst = 0;
    rep(i, 1, sz(t1) - 1) {
        if (t1[i] != t2[i]) {
            lst = i;
            if (!fst) fst = i;
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        int len = sz(s1[i].s) - 1;
        vector<int> res1 = s1[i].find(t1);
        vector<int> res2 = s2[i].find(t2);
        vector<int> res = merge(res1, res2);
        for (auto x : res) if (x >= lst && lst - len + 1 <= fst) ++ans;
    }
    cout << ans << endl;
}
signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    rep(i, 1, n) {
        cin >> s1[i].s >> s2[i].s;
        s1[i].init(), s2[i].init();
    }
    while (q--) {
        string t1, t2; cin >> t1 >> t2;
        t1 = " " + t1, t2 = " " + t2;
        solve(t1, t2);
    }
    return 0;
}