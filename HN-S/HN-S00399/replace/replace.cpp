#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int kmax = 2e5 + 3;
const int kmaxM = 5e6 + 3;
const int kB = 31;
const int Mod = 998244353;

bool mb;

struct V {
    string s, t;
    int op;
    long long hshs, hsht;
    long long ms, mt;
    int len, id;
    int ml, mr;
    bool o;
} v[kmax << 1];

int n, m;
int res[kmax];
long long pw[kmaxM];

void Init() {
    pw[0] = 1;
    for(int i = 1; i < kmaxM; i++) pw[i] = pw[i - 1] * kB % Mod;
}

bool Check(string a, string b, int len) {
    int ca = 0, cb = 0;
    for(int i = 1; i <= len; i++) {
        if(a[i] == 'a') {

        } else if(a[i] == 'b') {
            ca++;
        } else {
            return 0;
        }
        if(b[i] == 'a') {
            
        } else if(b[i] == 'b') {
            cb++;
        } else {
            return 0;
        }
    }
    return ca == 1 && cb == 1;
}

namespace Fenwick {

    int c[kmaxM];

    int Lowbit(int x) {
        return x & -x;
    }

    void Modify(int x, int v) {
        x++;
        for(; x < kmaxM; x += Lowbit(x)) {
            c[x] += v;
        }
    }    

    int Getres(int x) {
        x++;
        int tot = 0;
        for(; x; x -= Lowbit(x)) {
            tot += c[x];
        }
        return tot;
    }
}

namespace Sub1 {

    long long hsh[kmaxM];

    long long Hash(int l, int r) {
        // cout << "r - l + 1 = " << r - l + 1 << '\n';
        return (hsh[r] - hsh[l - 1] * pw[r - l + 1] % Mod + Mod) % Mod;
    }

    void Solve() {
        for(int j = n + 1; j <= n + m; j++) {
            for(int i = 1; i <= v[j].len; i++) {
                hsh[i] = (hsh[i - 1] * kB + v[j].s[i] - 'a') % Mod;
            }
            int ress = 0;
            for(int i = 1; i <= n; i++) {
                if(v[i].o) continue;
                if(v[i].ms == v[j].ms && v[i].mt == v[j].mt) {
                    // cout << "i = " << i << '\n';
                    int il = v[i].ml - 1, ir = v[i].len - v[i].mr;
                    int jl = v[j].ml - 1, jr = v[j].len - v[j].mr;
                    if(il > jl || ir > jr) continue;
                    // cout << "###\n";
                    if(v[i].hshs == Hash(v[j].ml - il, v[j].mr + ir)) ress++;
                }
            }
            cout << ress << '\n';
        }
    }
}

namespace Sub2 {

    bool chk = 1;

    struct G {
        int ls, rs, id;
    } g[kmax];

    int gc;

    void Solve(int l, int r) {
        gc = 0;
        for(int i = l; i <= r; i++) {
            if(v[i].o) continue;
            g[++gc] = {v[i].ml - 1, v[i].len - v[i].mr, v[i].id};
        }
        sort(g + 1, g + gc + 1, [](G p, G q) { return p.ls < q.ls || p.ls == q.ls && p.id < q.id; });
        for(int i = 1; i <= gc; i++) {
            if(g[i].id <= n) {
                Fenwick::Modify(g[i].rs, 1);
            } else {
                res[g[i].id - n] += Fenwick::Getres(g[i].rs);
            }
        }
        for(int i = 1; i <= gc; i++) {
            if(g[i].id <= n) {
                Fenwick::Modify(g[i].rs, -1);
            }
        }
    }
}

namespace ACAM {

    int chc, p[kmaxM];
    int ch[kmaxM][26];
    int ct[kmaxM];

    void Clear() {
        chc = 0;
        for(int i = 0; i < 26; i++) ch[0][i] = 0;
        ct[0] = p[0] = 0;
    }

    int New() {
        int x = ++chc;
        for(int i = 0; i < 26; i++) ch[x][i] = 0;
        ct[x] = p[x] = 0;
        return x;
    }

    void Insert(int id) {
        int x = 0;
        for(int i = 1; i <= v[id].len; i++) {
            int c = v[id].s[i] - 'a';
            if(!ch[x][c]) {
                ch[x][c] = New();
            }
            x = ch[x][c];
        }
        ct[x]++;
    } 

    void Fail() {
        queue<int> q;
        for(int i = 0; i < 26; i++) if(ch[0][i]) q.push(ch[0][i]);
        for(int x; !q.empty(); q.pop()) {
            x = q.front();
            ct[x] += ct[p[x]];
            // cout << "x = " << x << ' ' << ct[x] << '\n';
            for(int i = 0; i < 26; i++) {
                if(ch[x][i]) {
                    p[ch[x][i]] = ch[p[x]][i];
                    // cout << "x = " << x << ' ' << i << "In : " << ch[x][i] << '\n';
                    q.push(ch[x][i]);
                } else {
                    ch[x][i] = ch[p[x]][i];
                }
            }
        }
    }

    int b[kmaxM], bc;

    int Query(int id) {
        int x = 0;
        int tot = 0;
        bc = 0;
        for(int i = 1; i <= v[id].len; i++) {
            int c = v[id].s[i] - 'a';
            x = ch[x][c];
            b[++bc] = x;
            // cout << "x = " << x << ' ' << ct[x] << '\n';
        }
        sort(b + 1, b + bc + 1);
        for(int i = 1; i <= bc; i++) {
            if(i == 1 || b[i] != b[i - 1]) tot += ct[b[i]];
        }
        return tot;
    }
}

// namespace Sub4 {

//     long long hsh[kmaxM];

//     long long Hash(int l, int r) {
//         // cout << "r - l + 1 = " << r - l + 1 << '\n';
//         return (hsh[r] - hsh[l - 1] * pw[r - l + 1] % Mod + Mod) % Mod;
//     }

//     void Solve(int l, int r) {
//         for(int j = l; j <= r; j++) {
//             if(v[j].id <= n) continue;
//             for(int i = 1; i <= v[j].len; i++) {
//                 hsh[i] = (hsh[i - 1] * kB + v[j].s[i] - 'a') % Mod;
//             }
//             int ress = 0;
//             for(int i = l; i <= r; i++) {
//                 if(v[i].o || v[i].id > n) continue;
//                 if(v[i].ms == v[j].ms && v[i].mt == v[j].mt) {
//                     // cout << "i = " << i << '\n';
//                     int il = v[i].ml - 1, ir = v[i].len - v[i].mr;
//                     int jl = v[j].ml - 1, jr = v[j].len - v[j].mr;
//                     if(il > jl || ir > jr) continue;
//                     // cout << "###\n";
//                     if(v[i].hshs == Hash(v[j].ml - il, v[j].mr + ir)) ress++;
//                 }
//             }
//             cout << ress << '\n';
//         }
//     }
// }

namespace Sub3 {

    void Solve(int l, int r) {
        // cout << "Solve() " << l << ' ' << r << '\n';
        ACAM::Clear();
        int i = l;
        for(; i <= r && v[i].id <= n; i++) {
            if(v[i].o) continue;
            // cout << v[i].s << '\n';
            ACAM::Insert(i);
        }
        ACAM::Fail();
        for(; i <= r; i++) {
            res[v[i].id - n] = ACAM::Query(i);
        }
    }
}

void Solve(int l, int r) {
    if(Sub2::chk) {
        Sub2::Solve(l, r);
    } else {
        Sub3::Solve(l, r);
    }
}

bool med;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    Init();
    int ct = 0;
    for(int i = 1; i <= n + m; i++) {
        cin >> v[i].s >> v[i].t;
        if(i > n) v[i].op = 1;
        v[i].id = i;
        v[i].len = v[i].s.size();
        v[i].s = ' ' + v[i].s, v[i].t = ' ' + v[i].t;
        for(int j = 1; j <= v[i].len; j++) {
            v[i].hshs = (v[i].hshs * kB + v[i].s[j] - 'a') % Mod;
            v[i].hsht = (v[i].hsht * kB + v[i].t[j] - 'a') % Mod;
        }
        int l = 1, r = v[i].len;
        for(; l <= v[i].len && v[i].s[l] == v[i].t[l]; l++) {
        }
        for(; r && v[i].s[r] == v[i].t[r]; r--) {
        }
        if(l > v[i].len) {
            v[i].o = 1;
            continue;
        }
        for(int j = l; j <= r; j++) {
            v[i].ms = (v[i].ms * kB + v[i].s[j] - 'a') % Mod;
            v[i].mt = (v[i].mt * kB + v[i].t[j] - 'a') % Mod;
        }
        v[i].ml = l, v[i].mr = r;
        Sub2::chk &= Check(v[i].s, v[i].t, v[i].len);
    }
    if(n * m <= 50000000) {
        Sub1::Solve();
        return 0;
    }
    sort(v + 1, v + n + m + 1, [](V p, V q) { return p.ms < q.ms || p.ms == q.ms && p.mt < q.mt || p.ms == q.ms && p.mt == q.mt && p.op < q.op; });
    for(int i = 1, j = 1; i <= n + m; i = j) {
        for(; j <= n + m && v[i].ms == v[j].ms && v[i].mt == v[j].mt; j++) {
        }
        Solve(i, j - 1);
    }
    for(int i = 1; i <= m; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}
/*
4 1
u d
u d
u d
u d
uu du
*/