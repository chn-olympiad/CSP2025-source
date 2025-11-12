#include <bits/stdc++.h>

namespace CYRENE {
#define rep(i, st, ed) for (int i = (st), _##i = (ed); i <= _##i; ++i)
#define qep(i, st, ed) for (int i = (st), _##i = (ed); i <  _##i; ++i)
#define per(i, st, ed) for (int i = (st), _##i = (ed); i >= _##i; --i)
#define fi first
#define se second
#define eb emplace_back
#define gc getchar
#define pc putchar
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

namespace IO {
    template<typename T>
    void read(T &x) {
        x = 0; char c = gc(); bool f = false;
        while (!isdigit(c)) f = (c == '-'), c = gc();
        while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
        if (f) x = -x;
    }

    template<typename T, typename ...Nxt>
    void read(T &x, Nxt &...nxt) { read(x); read(nxt...); }
} using namespace IO;

constexpr int N = 505, MOD = 998244353;

int n, m, a[N];
char s[N];

namespace BF {
    constexpr int N = 15;
    
    int ord[N], ans;

    void solve() {
        iota(ord + 1, ord + n + 1, 1);
        do {
            int in = 0, out = 0;
            rep(i, 1, n) {
                int who = ord[i];
                if (s[i] == '0' || out >= a[who]) ++out;
                else ++in;
            }
            if (in >= m) ++ans;
        } while (next_permutation(ord + 1, ord + n + 1));
        printf("%d\n", ans);
    }
}

namespace FEAT_A {
    bool satis() {
        rep(i, 1, n) if (s[i] == '0') return false;
        return true;
    }

    void solve() {
        int ans = 1;
        rep(i, 1, n) ans = (i64)ans * i % MOD;
        printf("%d\n", ans);
    }
}

int moe() {
    read(n, m);
    scanf("%s", s + 1);
    rep(i, 1, n) read(a[i]);
    if (n <= 10) BF::solve();
    else if (FEAT_A::satis()) FEAT_A::solve();
    else BF::solve();
    return 0;
}
} // namespace CYRENE

int main() {
    std::freopen("employ.in", "r", stdin);
    std::freopen("employ.out", "w", stdout);
    return CYRENE::moe();
}

/*
g++ -o employ employ.cpp -std=c++17 -O2 -Wall -Wno-unused-result -g -DDEBUG -fsanitize=address,undefined
*/
