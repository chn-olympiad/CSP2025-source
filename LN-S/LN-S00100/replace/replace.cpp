#include <bits/stdc++.h>
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;

vector<u32> pi_func(string s) {
    u32 n = s.size();
    vector<u32> pi(n + 1);
    for (u32 i = 1, j = 0; i < n; i++, pi[i] = j) {
        for (j = pi[i]; j && s[i] != s[j]; ) j = pi[j];
        if (s[i] == s[j]) j++;
    }
    return pi;
}

vector<u32> kmp(string s, string t) {
    auto pi = pi_func(t);
    u32 n = s.size(), m = t.size();
    vector<u32> res;
    for (u32 i = 0, j = 0; i < n && j < m; i++) {
        for (; j && j < m && s[i] != t[j]; ) j = pi[j];
        if (s[i] == t[j]) j++;
        if (j == m) res.push_back(i - m + 1), j = pi[j];
    }
    return res;
}

constexpr u64 N = 200'000, P = 1'000'000'000'000'000'009, B = 131;

string A[N][2];
u64 H[N];

u64 qpow(u64 b, u64 p) {
    if (p == 0) return 1;
    if (p == 1) return b;
    return qpow(b * b % P, p / 2) * qpow(b, p % 2) % P;
}

i64 hassh(string s) {
    u64 ans = 0;
    for (u32 i = s.size(); i > 0; i--) ans = ans * B + s[i - 1], ans %= P;
    return ans;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    u32 n, q;
    cin >> n >> q;
    for (u32 i = 0; i < n; i++) cin >> A[i][0] >> A[i][1], H[i] = (hassh(A[i][1]) - hassh(A[i][0]) + P) % P;
    while (q--) {
        string S, T;
        cin >> S >> T;
        i64 hs = hassh(S), ht = hassh(T);
        u64 res = 0;
        for (u32 i = 0; i < n; i++) {
            auto p = kmp(S, A[i][0]), q = kmp(T, A[i][1]);
            for (u32 j : p)
                if ((ht - hs + P) % P == H[i] * qpow(B, j)) res++;
        }
        cout << res << "\n";
    }
}