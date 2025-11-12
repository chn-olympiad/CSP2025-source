// ac自动机???
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5;
int n, q;
vector<int> nxt[2][N];
int len[N];
string s1[N], s2[N];
void match(int c, int op, const string &t, vector<int> &pos) {
    const string &s = (op == 0 ? s1[c] : s2[c]);
    // cout << "match " << s << " " << t << "...";
    for (int i = 1, j= 0 ; i < (int)t.size(); i++) {
        while (j && s[j + 1] != t[i]) j = nxt[op][c][j];
        if (s[j + 1] == t[i]) j++;
        if (j == len[c]) pos.push_back(i - len[c] + 1);
    }
    // cout << "pos: "; for (auto x : pos) cout << x << ' '; cout << '\n';
}
using llu = unsigned long long int;
const llu base = 237;
llu pw[M];
void init(const string &s, vector<llu> &hsh) {
    hsh.resize(s.size() + 1);
    for (int i = 1; i < s.size(); i++) hsh[i] = hsh[i - 1] * base + s[i] - 'a';
}
llu geth(int l, int r, vector<llu> &hsh) {
    if (r < l) return 0;
    l--;
    return hsh[r] - pw[r - l] * hsh[l];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < M; i++) pw[i] = pw[i- 1] * base;
    cin >> n >> q;
    for (int c = 1; c <= n; c++) {
        cin >> s1[c]>>s2[c];s1[c]='@'+s1[c], s2[c]='@'+s2[c];
        len[c] = s2[c].length() - 1;
        nxt[0][c].resize(len[c] + 2);
        nxt[0][c][1] = nxt[0][c][0] = 0;
        for (int i = 2, j=  0; i <= len[c]; i++) {
            while (j && s1[i] != s1[j + 1]) j = nxt[0][c][j];
            if (s1[j + 1] == s1[i]) j++;
            nxt[0][c][i] = j;
        }
        nxt[1][c].resize(len[c] + 2);
        nxt[1][c][1] = nxt[1][c][0] = 0;
        for (int i = 2, j=  0; i <= len[c]; i++) {
            while (j && s2[i] != s2[j + 1]) j = nxt[1][c][j];
            if (s2[j + 1] == s2[i]) j++;
            nxt[1][c][i] = j;
        }
    }
    // if (q != 1 && n >= 1e4) {
    //     for (int i = 1; i <= q; i++) cout << 0 << '\n';
    //     return 0;
    // }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2; t1 = '@' + t1, t2 = '@' + t2;
        int L = t1.size()  -1;
        int ans = 0;
        vector<llu> ha, hb;
        init(t1, ha), init(t2, hb);
        for (int i = 1; i <= n; i++) {
            // cout << "i=" << i << '\n';
            vector<int> pa, pb;
            unordered_set<int> s;
            match(i, 0, t1, pa), match(i, 1, t2, pb);
            // cout << "mat s1: "; for (int x : pa) cout << x << " "; cout << '\n';
            // cout << "mat s2: "; for (int x : pb) cout << x << " "; cout << '\n';
            for (int x : pa) s.insert(x);
            for (int x : pb) if (s.count(x)) {
                if (geth(1, x - 1, ha) ==geth(1, x - 1, hb)
                     && geth(x + len[i], L, ha) == geth(x + len[i], L, hb))
                        ans++;//, cout << "add " << x << "\n";
                // cout << geth(1, x - 1, ha) << ' ' << geth(x + len[i], L, ha) << '\n';
                // cout << geth(1, x - 1, hb) << ' ' << geth(x + len[i], L, hb) << '\n';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
// 50pts ?? 