#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// char _m_s;
const int MAXN = 2e5 + 5;
const int MAXL = 5e6 + 5;

struct SHash {
    static const int BA = 29, MA = 1e9 + 7, IA = 758620695;
    static const int BB = 31, MB = 1145141923, IB = 1108201861;
    vector<int> ha, hb;
    static int pwA[MAXL], pwB[MAXL], invA[MAXL], invB[MAXL];
    static void init(int maxn) {
        pwA[0] = pwB[0] = invA[0] = invB[0] = 1;
        for (int i = 1; i < maxn; ++i) {
            pwA[i] = (1ll * pwA[i - 1] * BA) % MA;
            pwB[i] = (1ll * pwB[i - 1] * BB) % MB;
            invA[i] = (1ll * invA[i - 1] * IA) % MA;
            invB[i] = (1ll * invB[i - 1] * IB) % MB;
        }
    }
    SHash() : ha(), hb() {}
    SHash(const string& s) {
        int n = s.size();
        ha.resize(n); hb.resize(n);
        ha[0] = hb[0] = s[0] - 'a';
        for (int i = 1; i < n; ++i) {
            ha[i] = (ha[i - 1] + (s[i] - 'a') * 1ll * pwA[i] % MA) % MA;
            hb[i] = (hb[i - 1] + (s[i] - 'a') * 1ll * pwB[i] % MA) % MB;
        }
    }
    int length() const { return ha.size(); }
    ull get() const { return (ull(ha.back()) << 32) | ull(hb.back()); }
    ull get(int l, int r) const {
        assert(l <= r && l >= 0 && r < ha.size());
        int p1 = ((1ll * ha[r] - (l > 0 ? 1ll * ha[l - 1] : 0)) * 1ll * invA[l] % MA + MA) % MA;
        int p2 = ((1ll * hb[r] - (l > 0 ? 1ll * hb[l - 1] : 0)) * 1ll * invB[l] % MB + MB) % MB;
        return (ull(p1) << 32) | ull(p2);
    }
};
int SHash::pwA[MAXL], SHash::pwB[MAXL], SHash::invA[MAXL], SHash::invB[MAXL];

int n, q;
string s[MAXN][2], t[MAXN][2];
// SHash sh[MAXN][2], th[MAXN][2];
// pair<int, int> sdif[MAXN], tdif[MAXN];

pair<int, int> calcdiff(string s[2]) {
    if (s[0].size() != s[1].size()) return { -1, -1 };
    pair<int, int> ret = { -1, -1 };
    for (int i = 0; i < s[0].size(); ++i) {
        if (s[0][i] != s[1][i]) {
            ret.first = i;
            break;
        }
    }
    for (int i = s[0].size() - 1; i >= 0; --i) {
        if (s[0][i] != s[1][i]) {
            ret.second = i;
            break;
        }
    }
    return ret;
}

bool check(int si, int ti) {
    // printf("check %d %d\n", si, ti);
    if (s[si][0].size() != s[si][1].size() || 
        t[ti][0].size() != t[ti][1].size() || 
        t[ti][0].size() < s[si][0].size())
        return false;
    int ind = 0, ia = 0, ib = 0;
    bool ans = true;
    while ((ind = max(ia = t[ti][0].find(s[si][0], ind), ib = t[ti][1].find(s[si][1], ind))) != string::npos) {
        if (ia == string::npos || ib == string::npos) break;
        int end = ind + s[si][0].size() - 1;
        // if (end < tdif[ti].first) continue;
        // if (ind > tdif[ti].second) break;
        if (ia != ib) {
            ind = min(ia, ib) + 1;
            continue;
        }
        // printf("ia=%d ib=%d\n", ia, ib);
        if (!ans) return false;
        if (ans) ans = false;
        ++ind;
    }
    return !ans;
}

// char _m_e;

int main() {
    // fprintf(stderr, "memory:%.2lfMB\n", (&_m_e - &_m_s) / 1048576.0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    // SHash::init(MAXL);
// #if 0
//     {
//         SHash test("abcbaba");
//         printf("%llu==%llu\n", test.get(), test.get(0, test.length() - 1));
//         printf("%llu==%llu\n", test.get(0, 1), test.get(4, 5));
//         printf("%llu==%llu\n", test.get(3, 4), test.get(5, 6));
//         printf("%llu!=%llu\n", test.get(1, 2), test.get(2, 3));
//         printf("%llu==%llu\n", test.get(1, 2), SHash("bc").get());
//         printf("%llu==%llu\n", test.get(2, 3), SHash("cb").get());
//     }
// #endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i][0] >> s[i][1];
        // sh[i][0] = SHash(s[i][0]);
        // sh[i][1] = SHash(s[i][1]);
        // sdif[i] = calcdiff(s[i]);
    }
    for (int i = 1; i <= q; ++i) {
        cin >> t[i][0] >> t[i][1];
        // th[i][0] = SHash(t[i][0]);
        // th[i][1] = SHash(t[i][1]);
        // tdif[i] = calcdiff(t[i]);
    }
    for (int i = 1; i <= q; ++i) {
        int ans = 0;
        for (int j = 1; j <= n; ++j) if (check(j, i)) ++ans;
        cout << ans << '\n';
    }
    return 0;
}