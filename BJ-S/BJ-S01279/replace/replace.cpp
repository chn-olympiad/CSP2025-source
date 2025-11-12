#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#define int long long
#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 5000005

using namespace std;

const int base = 31, mod = 998244353;

int n, q, pb[maxn];

inline int qpow(int x, int y) {
    int xum = 1;
    while(y) {
        if(y & 1) (xum *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return xum;
}

pii hs(string s) {
    int sum = 0;
    for(char ch : s) {
        sum *= base;
        sum += (ch - 'a');
        sum %= mod;
    }
    return make_pair(s.size(), sum);
}

struct Dat {
    pii hs;
    string s;
} ;

Dat trans(string s, string t) {
    string l, r;
    int L, R;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == t[i]) l += s[i];
        else {
            L = i;
            break;
        }
    }
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == t[i]) r += s[i];
        else {
            R = i;
            break;
        }
    }
    reverse(r.begin(), r.end());
    return (Dat){ make_pair(hs(s.substr(L, R - L + 1)).se, hs(t.substr(L, R - L + 1)).se), l + "{" + r };
}

// struct Hash {
//     int hs[maxn];
//     void load(string s) {
//         s = " " + s;
//         for(int i = 1; i < s.size(); i++) {
//             hs[i] = (hs[i - 1] * base + (s[i] - 'a')) % mod;
//         }
//     }
//     int query(int l, int r) {
//         return ((hs[r] - hs[l - 1] * pb[r - l + 1]) % mod + mod) % mod;
//     }
// } f;

signed rn, rt[maxn];

struct ACAM {
    signed f[maxn][27], fa[maxn], fail[maxn], cnt[maxn], nn;
    ACAM() {
        nn = 0;
        memset(f[0], 0, sizeof(f[0]));
    }
    int new_node() {
        return ++nn;
    }
    void insert(int p, string s) {
        // cout << "insert " << s << " to " << p << endl;
        for(char ch : s) {
            if(!f[p][ch - 97]) f[p][ch - 97] = new_node(), fa[f[p][ch - 97]] = p;
            p = f[p][ch - 97];
            // cout << ". " << p << endl;
        }
        cnt[p]++;
        // cout << "cnt " << p << "++" << endl;
    }
    void build(int s) {
        queue<int> q;
        queue<int> q2;
        q.push(s);
        while(!q.empty()) {
            int p = q.front(); q.pop();
            q2.push(p);
            // cout << "build " << p << endl;
            for(int i = 0; i < 27; i++) if(f[p][i]) q.push(f[p][i]);
            int id = -1;
            for(int i = 0; i < 27; i++) if(f[fa[p]][i] == p) id = i; 
            if(fa[p] == 0 || fa[fa[p]] == 0) fail[p] = s;
            else fail[p] = f[fail[fa[p]]][id];
            if(p != s) {
                for(int i = 0; i < 27; i++) if(!f[p][i]) f[p][i] = f[fail[p]][i];
            }
            else {
                for(int i = 0; i < 27; i++) if(!f[p][i]) f[p][i] = p;
            }
        }
        while(!q2.empty()) {
            int r = q2.front(); q2.pop();
            if(fail[r] != r) cnt[r] += cnt[fail[r]];
            // cout << "fail+" << r << endl;
        }
    }
    int sum(int p, string s) {
        // cout << "query " << s << " on " << p << endl;
        int res = 0;
        // cout << "+ " << p << endl;
        for(char ch : s) {
            p = f[p][ch - 'a'];
            res += cnt[p];
            // cout << "+ " << p << ' ' << cnt[p] << endl;
        }
        return res;
    }
    void test(int p, string s) {
        cout << "test " << s << " to " << p << endl;
        for(char ch : s) {
            if(!f[p][ch - 97]) f[p][ch - 97] = new_node(), fa[f[p][ch - 97]] = p;
            p = f[p][ch - 97];
            cout << ". " << p << endl;
        }
    }
} f;

map<pii, signed> rid;

void work() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        string s, t; cin >> s >> t;
        if(s == t) continue;
        Dat d = trans(s, t);
        if(!rid[d.hs]) rid[d.hs] = ++rn, rt[rn] = f.new_node();
        f.insert(rt[rid[d.hs]], d.s);
        // if(d.hs.fi == 777834625 && d.hs.se == 631991618 && (d.s.substr(0, 5) == "gebd{" || d.s.substr(0, 4) == "ebd{" || d.s.substr(0, 3) == "bd{" || d.s.substr(0, 2) == "d{" || d.s.substr(0, 1) == "{")) cout << d.s << endl;
    }
    for(int i = 1; i <= rn; i++) f.build(rt[i]);
    for(int Q = 1; Q <= q; Q++) {
        string s, t; cin >> s >> t;
        // if(Q != 101) continue;

        // cout << s << endl << t << endl;

        if(s.size() != t.size()) {
            cout << "0\n";
            continue;
        }
        Dat d = trans(s, t);
        if(!rid[d.hs]) {
            cout << "0\n";
            continue;
        }
        // cout << rt[rid[d.hs]] << endl;
        cout << f.sum(rt[rid[d.hs]], d.s) << '\n';
        // f.test(204, "gebd{");
        // cout << d.hs.fi << ' ' << d.hs.se << ' ' << d.s << endl;
    }
}

signed main() {
    int st = clock();
    fopen("replace");
    ios::sync_with_stdio(false); cin.tie(0);

    pb[0] = 1;
    for(int i = 1; i < maxn; i++) pb[i] = (pb[i - 1] * base) % mod;

    int _ = 1;
    // cin >> _;
    while(_--) work();
    // cerr << (1.0 * (clock() - st) / CLOCKS_PER_SEC) << endl;
}