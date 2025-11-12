#include <bits/stdc++.h>

void IO(const std::string & s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 2E5 + 5;
constexpr int M = 5E6 + 5;

namespace Hash {
    constexpr int N = 5E6 + 5;
    constexpr int B1 = 131;
    constexpr int B2 = 20100611;

    u64 pw1[N], pw2[N];
    void init() {
        pw1[0] = pw2[0] = 1;
        for (int i = 1; i <= 5000000; i++) {
            pw1[i] = pw1[i - 1] * B1;
            pw2[i] = pw2[i - 1] * B2;
        }
    }

    struct Integer {
        u64 h1, h2;
        int n;
        Integer(char c) : 
            h1(c - 'a'), h2(c - 'a'), n(1) {}
        Integer(u64 _h1 = 0, u64 _h2 = 0, int n = 0) : 
            h1(_h1), h2(_h2), n(n) {}
        friend Integer operator + (const Integer & lhs, const Integer & rhs) {
            return Integer(lhs.h1 * pw1[rhs.n] + rhs.h1, lhs.h2 * pw2[rhs.n] + rhs.h2, lhs.n + rhs.n);
        }
        Integer & operator += (const Integer & rhs) {
            return *this = *this + rhs;
        }
        constexpr friend bool operator == (const Integer & lhs, const Integer & rhs) {
            return lhs.h1 == rhs.h1 && lhs.h2 == rhs.h2 && lhs.n == rhs.n;
        }
    };
}

using Hash::Integer;

int n, q;

int trans[26][M], tot;
int fail[M], dis[M];
std::vector<Integer> end[M];

void insert(const std::string & s, const Integer & hs) {
    int u = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int c = s[i] - 'a';
        if (!trans[c][u]) trans[c][u] = ++tot;
        u = trans[c][u];
    }
    end[u].push_back(hs);
}

void build() {
    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (trans[i][0]) {
            dis[trans[i][0]] = 1;
            q.push(trans[i][0]);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (trans[i][u]) {
                fail[trans[i][u]] = trans[i][fail[u]];
                dis[trans[i][u]] = dis[u] + 1;
                q.push(trans[i][u]);
            } else {
                trans[i][u] = trans[i][fail[u]];
            }
        }
    }
}

Integer pre[N], suf[N];
i64 query(const std::string & s, const std::string & t) {
    if (s.size() != t.size()) return 0;
    int n = (int)s.size() - 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + s[i];
    }
    suf[n] = s[n];
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = s[i] + suf[i + 1];
    }
    Integer want(0, 0, 0);
    for (int i = 1; i <= n; i++) {
        want = want + t[i];
    }
    int u = 0;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        u = trans[s[i] - 'a'][u];
        for (int v = u; v; v = fail[v]) {
            for (auto h : end[v]) {
                if (pre[i - dis[v]] + h + suf[i + 1] == want) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    IO("replace");

    Hash::init();

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        Integer hs(0, 0, 0);
        for (int j = 0; j < (int)s2.size(); j++) {
            hs += s2[j];
        }
        insert(s1, hs);
    }

    if (1LL * n * q > 1000000000LL) {
        for (int i = 1; i <= q; i++) {
            std::cout << 0 << "\n";
        }
        return 0;
    }

    build();

    for (int i = 1; i <= q; i++) {
        std::string t1, t2;
        std::cin >> t1 >> t2;
        t1 = " " + t1, t2 = " " + t2;
        std::cout << query(t1, t2) << "\n";
    }
    return 0;
}

/*
3 1
ab cd
bc de
aa bb
xabcx xadex
*/