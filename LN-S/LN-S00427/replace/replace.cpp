#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

#define vi vector<int>
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define bit(k) (1 << (k))
#define bin(s, k) (((s) >> (k)) & 1)
#define mem(a, x) memset(a, x, sizeof(a))
#define req(i, l, r) for (int i = l, i##End = r; i < i##End; i = -~i)
#define rep(i, l, r) for (int i = l, i##End = r; i <= i##End; i = -~i)

bool Mbe;

template<typename T, typename U> void chkmx(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void chkmn(T &a, U b) { if (a > b) a = b; }

#define N 200005
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

constexpr u64 P1 = 1000000007;
constexpr u64 B1 = 131, B2 = 114547;

struct H {
    u64 a, b;
    void operator()(string::iterator l, string::iterator r) {
        a = b = 0;
        while (l != r) {
            a = (a * B1 + (*l - 'a' + 1)) % P1;
            b = b * B2 + *l;
            l++;
        }
    }
};

bool operator==(const H &u, const H &v) { return u.a == v.a && u.b == v.b; }
bool operator!=(const H &u, const H &v) { return !(u == v); }
bool operator<(const H &u, const H &v) {
    if (u.a != v.a) return u.a < v.a;
    return u.b < v.b;
}

struct X {
    string s, t; int i, l, r; H u, v;

    void operator()() {
        l = 0, r = s.size(), r--;
        while (l < s.size() && s[l] == t[l]) l++;
        while (r >= 0 && s[r] == t[r]) r--;
        auto S = s.begin(), T = t.begin();
        u(S + l, S + r + 1), v(T + l, T + r + 1);
        // l(s.substr(0, l)), r(s.substr(j + 1));
        // u(s.substr(l, j - l + 1));
        // v(t.substr(l, j - l + 1));
    }
};

bool operator==(const X &u, const X &v) { return u.u == v.u && u.v == v.v; }
bool operator<(const X &u, const X &v) {
    if (u.u != v.u) return u.u < v.u;
    return u.v < v.v;
}

int n, m, k;
X a[N], b[N];
int ans[N];

struct Trie {
    int tt;
    int ch[5000005][27];
    int fl[5000005], ct[5000005];
    int qu[5000005], L, R;

    void clr() { tt = 0, mem(ch[0], 0), fl[0] = ct[0] = 0; }

    int nwd() {
        int u = ++tt;
        mem(ch[u], 0), ct[u] = 0;
        return u;
    }

    void ins(const X &x) {
        int u = 0;
        req(i, 0, x.l) {
            int &v = ch[u][x.s[i] - 'a'];
            if (!v) v = nwd(); u = v;
        } {
            int &v = ch[u][26];
            if (!v) v = nwd(); u = v;
        } req(i, x.r + 1, x.s.size()) {
            int &v = ch[u][x.s[i] - 'a'];
            if (!v) v = nwd(); u = v;
        } ct[u]++;
    }

    void bld() {
        L = 1, R = 0;
        rep(i, 0, 26) {
            int v = ch[0][i];
            if (v) qu[++R] = v, fl[v] = 0;
        }
        while (L <= R) {
            int u = qu[L++];
            rep(i, 0, 26) {
                int &v = ch[u][i];
                if (!v) v = ch[fl[u]][i];
                else fl[v] = ch[fl[u]][i], qu[++R] = v;
            }
        }
        rep(i, 1, R) { int u = qu[i]; ct[u] += ct[fl[u]]; }
        // fputs("bld()\n", stderr);
        // rep(i, 0, tt) {
        //     fprintf(stderr, "%d: %d %d [%d %d ... %d ... %d]\n", i, fl[i], ct[i], ch[i][0], ch[i][1], ch[i][23], ch[i][26]);
        // }
    }

    void slv(const X &x) {
        int u = 0; int &res = ans[x.i];
        req(i, 0, x.l) {
            int v = ch[u][x.s[i] - 'a'];
            res += ct[u = v];
        } {
            int v = ch[u][26];
            res += ct[u = v];
        } req(i, x.r + 1, x.s.size()) {
            int v = ch[u][x.s[i] - 'a'];
            res += ct[u = v];
        }
    }
} T;

void mslv() {
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> a[i].s >> a[i].t;
        if (a[i].s == a[i].t) continue;
        (a[++k] = a[i])();
    } n = k, k = 0;
    rep(i, 1, m) {
        cin >> b[i].s >> b[i].t; b[i].i = i;
        if (b[i].s.size() != b[i].t.size()) continue;
        (b[++k] = b[i])();
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    // rep(i, 1, n) {
    //     fprintf(stderr, "i = %d: ", i);
    //     cerr << a[i].s << ' ' << a[i].t << " {" << a[i].l.a << ", " << a[i].l.b << "} {" << a[i].u.a << ", " << a[i].u.b << "} {" << a[i].v.a << ", " << a[i].v.b << "} {" << a[i].r.a << ", " << a[i].r.b << "}\n";
    // }
    // rep(i, 1, k) {
    //     fprintf(stderr, "i = %d: ", i);
    //     cerr << b[i].s << ' ' << b[i].t << " {" << b[i].l.a << ", " << b[i].l.b << "} {" << b[i].u.a << ", " << b[i].u.b << "} {" << b[i].v.a << ", " << b[i].v.b << "} {" << b[i].r.a << ", " << b[i].r.b << "}\n";
    // }
    int L = 1;
    rep(l, 1, k) {
        int r = l;
        while (r < k && b[r + 1] == b[l]) r++;
        while (L <= n && a[L] < b[l]) L++;
        if (L > n || b[l] < a[L]) { l = r; continue; }
        int R = L;
        while (R < n && a[R + 1] == a[L]) R++;
        // fprintf(stderr, "b: [%d, %d]; a: [%d, %d]\n", l, r, L, R);
        T.clr(); rep(i, L, R) T.ins(a[i]); T.bld();
        rep(i, l, r) T.slv(b[i]);
        // sort(b + l, b + r + 1, [](X u, X v) { return u.l < v.l; });
        // sort(a + L, a + R + 1, [](X u, X v) { return u.l < v.l; });
        // fprintf(stderr, "[%d %d] [%d %d]\n", l, r, L, R);
        // int t = L;
        // rep(i, l, r) {
        //     int j = i;
        //     while (j < r && b[j + 1].l == b[i].l) j++;
        //     while (t <= R && a[t].l < b[i].l) t++;
        //     if (t > R || b[i].l < a[t].l) { i = j; continue; }
        //     S.clear(); while (t <= R && a[t].l == b[i].l) S[a[t++].r]++;
        //     rep(_, i, j) ans[b[_].i] = S[b[_].r];
        // }
        l = r, L = R + 1;
    }
    rep(i, 1, m) printf("%d\n", ans[i]);
}

void mprw() {}

bool Med;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    mprw(), mslv();
    #ifdef JYR
    fprintf(stderr, "%.2lfMB ", abs(&Mbe - &Med) / 1048576.);
    fprintf(stderr, "%.0lfms\n", clock() * 1000. / CLOCKS_PER_SEC);
    #endif
    return 0;
}