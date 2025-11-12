#include <bits/stdc++.h>
#ifdef DEBUG
constexpr int test = 1;
#else
constexpr int test = 0;
#endif
#define err if constexpr (test) std::cerr
constexpr int N = 200'003, M = 27;
int n, q;
std::string s0[N], s1[N], t0[N], t1[N];
namespace trie {
    constexpr int K = 10'000'003;
    int nxt[K][M], tot;
    int w[K], fail[K];
    int insert(const std::string &s) {
        int p = 1;
        for(char _c : s) {
            int c = _c - 'a';
            if(!nxt[p][c]) nxt[p][c] = ++tot;
            p = nxt[p][c];
        }
        ++w[p];
        return p;
    }
    void init() {
        std::vector<int> qwq = {1};
        for(int l = 0, r = 0; l <= r; l++) {
            int p = qwq[l];
            for(int c = 0; c < M; c++) {
                if(nxt[p][c]) {
                    int q = nxt[p][c];
                    for(int i = fail[p]; i; i = fail[i]) {
                        if(nxt[i][c]) {
                            fail[q] = nxt[i][c];
                            break;
                        }
                    }
                    if(!fail[q]) fail[q] = 1;
                    qwq.push_back(q), ++r;
                } else {
                    for(int i = fail[p]; i; i = fail[i]) {
                        if(nxt[i][c]) {
                            nxt[p][c] = nxt[i][c];
                            break;
                        }
                    }
                    if(!nxt[p][c]) nxt[p][c] = 1;
                }
            }
        }
    }
    int getres(const std::string &s) {
        int p = 1, ans = 0;
        for(char _c : s) {
            int c = _c - 'a';
            p = nxt[p][c];
            ans += w[p];
        }
        return ans;
    }
}
std::unordered_map<int, int> getrt;
int ps[N];
std::string getw(const std::string &s0, const std::string &s1) {
    err << s0 << "," << s1 << "\n";
    if(s0.length() != s1.length()) return "";
    int len = s0.length();
    int l = -1, r = -1;
    for(int i = 0; i < len; i++) {
        if(s0[i] != s1[i]) {l = i; break;}
    }
    if(l == -1) return "";
    for(int i = len - 1; i >= 0; i--) {
        if(s0[i] != s1[i]) {r = i; break;}
    }
    std::string s;
    for(int i = 0; i < l; i++) s += s0[i];
    s += 'a' + 26;
    for(int i = l; i <= r; i++) s += s0[i];
    for(int i = l; i <= r; i++) s += s1[i];
    s += 'a' + 26;
    for(int i = r + 1; i < len; i++) s += s1[i];
    if constexpr (test) {
        std::cerr << s << "\n";
    }
    return s;
}
int init1(const std::string &s0, const std::string &s1) {
    std::string s = getw(s0, s1);
    return s.length() ? trie::insert(s) : 0;
}
void init2() {
    trie::init();
}
int query(const std::string &t0, const std::string &t1) {
    std::string t = getw(t0, t1);
    return t.length() ? trie::getres(t) : 0;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        std::cin >> s0[i] >> s1[i];
    }
    for(int i = 1; i <= q; i++) {
        std::cin >> t0[i] >> t1[i];
    }
    trie::tot = 1;
    for(int i = 1; i <= n; i++) {
        ps[i] = init1(s0[i], s1[i]);
    }
    init2();
    for(int i = 1; i <= q; i++) {
        std::cout << query(t0[i], t1[i]) << "\n";
    }
    return 0;
}
