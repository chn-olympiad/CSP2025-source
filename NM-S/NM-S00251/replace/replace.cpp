#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull BASE = 1315423911ull;
const size_t MAXLEN = 5000000 + 5;
const long long COMBO_LIMIT = 200000;

static ull pw[MAXLEN];

struct PairKey {
    ull h1, h2;
    int len;
    bool operator==(const PairKey& other) const noexcept {
        return h1 == other.h1 && h2 == other.h2 && len == other.len;
    }
};

struct KeyHash {
    size_t operator()(const PairKey& k) const noexcept {
        return (size_t)(k.h1 ^ (k.h2 * 1000003ull) ^ ((ull)k.len * 19260817ull));
    }
};

ull get_hash(const vector<ull>& pre, int l, int len) {
    return pre[l + len] - pre[l] * pw[len];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pw[0] = 1;
    for (size_t i = 1; i < MAXLEN; ++i) pw[i] = pw[i - 1] * BASE;

    ifstream fin("replace.in");
    ofstream fout("replace.out");
    int n, q;
    fin >> n >> q;

    unordered_map<PairKey, int, KeyHash> mp;
    mp.reserve(n * 2);

    struct UP { ull h1, h2; int len; int cnt; };
    vector<UP> uniq;
    uniq.reserve(n);

    auto hash_string = [&](const string& s) -> ull {
        ull h = 0;
        for (char c : s) h = h * BASE + (ull)(c - 'a' + 1);
        return h;
    };

    for (int i = 0; i < n; ++i) {
        string a, b;
        fin >> a >> b;
        int len = (int)a.size();
        ull h1 = hash_string(a);
        ull h2 = hash_string(b);
        PairKey key{h1, h2, len};
        auto it = mp.find(key);
        if (it == mp.end()) {
            int idx = (int)uniq.size();
            mp[key] = idx;
            uniq.push_back({h1, h2, len, 1});
        } else {
            ++uniq[it->second].cnt;
        }
    }

    for (int qi = 0; qi < q; ++qi) {
        string s, t;
        fin >> s >> t;
        int m = (int)s.size();
        if ((int)t.size() != m) {
            fout << 0 << '\n';
            continue;
        }

        int l0 = -1, r0 = -1;
        for (int i = 0; i < m; ++i) {
            if (s[i] != t[i]) { l0 = i; break; }
        }
        if (l0 == -1) {
            fout << 0 << '\n';
            continue;
        }
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != t[i]) { r0 = i; break; }
        }
        int diffLen = r0 - l0 + 1;

        long long combos = (long long)(l0 + 1) * (m - r0);

        vector<ull> ps(m + 1), pt(m + 1);
        ps[0] = pt[0] = 0;
        for (int i = 0; i < m; ++i) {
            ps[i + 1] = ps[i] * BASE + (ull)(s[i] - 'a' + 1);
            pt[i + 1] = pt[i] * BASE + (ull)(t[i] - 'a' + 1);
        }

        long long ans = 0;

        if (combos <= COMBO_LIMIT) {
            for (int pos = 0; pos <= l0; ++pos) {
                int minLen = r0 - pos + 1;
                for (int len = minLen; pos + len <= m; ++len) {
                    ull hs = get_hash(ps, pos, len);
                    ull ht = get_hash(pt, pos, len);
                    PairKey key{hs, ht, len};
                    auto it = mp.find(key);
                    if (it != mp.end()) ans += uniq[it->second].cnt;
                }
            }
        } else {
            for (const auto& up : uniq) {
                int len = up.len;
                if (len < diffLen) continue;
                int start = r0 - len + 1;
                if (start < 0) start = 0;
                int end = l0;
                if (start > end) continue;
                for (int pos = start; pos <= end; ++pos) {
                    ull hs = get_hash(ps, pos, len);
                    if (hs != up.h1) continue;
                    ull ht = get_hash(pt, pos, len);
                    if (ht != up.h2) continue;
                    ans += up.cnt;
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}
//如果你看到这里了 ，那我就可以告诉你一个“惊喜 ”
//我不知道会不会有人看这个代码，工整吧
//半个小时 才写出来的
//这个没有road多
//我妈给我报的课我基本没上，纯跟AI学
//AI讲的可明白多了，还是1对1
//总之，看到的话不要惊讶
//昨天AI告诉我，可读的变量名可以让人读的更清楚 
//我本来没打算这么写来着，但是有趣的是Deepseek严厉的批评了我
//所以特意去英语速成啦 
//至于这个应该没人看见，因为是机器判题