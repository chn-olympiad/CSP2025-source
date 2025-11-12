# include <algorithm>
# include <array>
# include <iostream>
# include <queue>
# include <string>
# include <vector>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/hash_policy.hpp>

using std::cin;
using std::cout;
using std::array;
using std::string;
using std::vector;

typedef unsigned long long ull;

struct ACAM {
    struct node {
        array<int, 27> trans;
        int fail;
        long long cnt;
    };

    vector<node> dfa;

    ACAM() {
        dfa = {{{}, -1, 0}};
        dfa[0].trans.fill(-1);
    }

    void insert(int n, const string &str) {
        int cur = 0;

        for (int i = 0; i < n; ++i) {
            char c = str[i];

            if (dfa[cur].trans[c] < 0) {
                dfa[cur].trans[c] = int(dfa.size());
                dfa.push_back({{}, 0, 0});
                dfa.back().trans.fill(-1);
            }

            cur = dfa[cur].trans[c];
        }

        dfa[cur].cnt += 1;
    }

    void build() {
        std::queue<int> qq;

        for (int c = 0; c < 27; ++c) {
            if (dfa[0].trans[c] < 0) {
                dfa[0].trans[c] = 0;
            } else {
                dfa[dfa[0].trans[c]].fail = 0;
                qq.push(dfa[0].trans[c]);
            }
        }

        while (!qq.empty()) {
            int cur = qq.front();
            qq.pop();

            for (int c = 0; c < 27; ++c) {
                if (dfa[cur].trans[c] < 0) {
                    dfa[cur].trans[c] = dfa[dfa[cur].fail].trans[c];
                    continue;
                }

                qq.push(dfa[cur].trans[c]);

                int v = dfa[cur].trans[c];
                dfa[v].fail = dfa[dfa[cur].fail].trans[c];
            }
        }

        for (int u = 1; u < dfa.size(); ++u) {
            dfa[u].cnt += dfa[dfa[u].fail].cnt;
        }
    }

    int calc(int n, const string &str) const {
        long long res = 0;
        int cur = 0;

        for (int i = 0; i < n; ++i) {
            cur = dfa[cur].trans[str[i]];

            res += dfa[cur].cnt;
        }

        return res;
    }
};

constexpr int ba1 = 47, ba2 = 53;
constexpr int mod1 = 1'0000'99999, mod2 = 1'00000'9999;

struct hsh_str {
    int val1{0}, val2{0};

    void append(char c) {
        c += 1;
        val1 = int((1ll * val1 * ba1 + c) % mod1);
        val2 = int((1ll * val2 * ba2 + c) % mod2);
    }

    ull val() const {
        return 1ull * val1 * val2;
    }
};

vector<ACAM> info;
__gnu_pbds::gp_hash_table<ull, int> id;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);

    int n, Q;
    cin >> n >> Q;

    for (int _ = 0; _ < n; ++_) {
        string str1, str2;
        cin >> str1 >> str2;

        for (auto &ch: str1) {
            ch -= 'a';
        }
        for (auto &ch: str2) {
            ch -= 'a';
        }

        int len = int(str1.length());

        int l = -1, r = -1;
        for (int i = 0; i < len; ++i) {
            if (str1[i] != str2[i]) {
                l = i;
                break;
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            if (str1[i] != str2[i]) {
                r = i;
                break;
            }
        }

        if (l < 0) {
            continue;
        }

        hsh_str hsh;

        for (int i = l; i <= r; ++i) {
            hsh.append(str1[i]);
            hsh.append(str2[i]);
        }

        int cur_id = -1;
        if (id.find(hsh.val()) == id.end()) {
            id[hsh.val()] = (cur_id = int(info.size()));
            info.emplace_back();
        } else {
            cur_id = id[hsh.val()];
        }

        string rest;

        rest.reserve(l + len - r);

        for (int i = 0; i < l; ++i) {
            rest.push_back(str1[i]);
        }
        rest.push_back(char(('z' + 1) - 'a'));
        for (int i = r + 1; i < len; ++i) {
            rest.push_back(str1[i]);
        }

        info[cur_id].insert(int(rest.length()), rest);
    }

    for (auto &AM: info) {
        AM.build();
    }

    while (Q--) {
        string str1, str2;
        cin >> str1 >> str2;

        if (str1.length() != str2.length()) {
            cout << "0\n";
            continue;
        }

        for (auto &ch: str1) {
            ch -= 'a';
        }
        for (auto &ch: str2) {
            ch -= 'a';
        }

        int len = int(str1.length());

        int l = -1, r = -1;
        for (int i = 0; i < len; ++i) {
            if (str1[i] != str2[i]) {
                l = i;
                break;
            }
        }
        for (int i = len - 1; i >= 0; --i) {
            if (str1[i] != str2[i]) {
                r = i;
                break;
            }
        }

        hsh_str hsh;

        for (int i = l; i <= r; ++i) {
            hsh.append(str1[i]);
            hsh.append(str2[i]);
        }

        int cur_id = -1;
        if (id.find(hsh.val()) == id.end()) {
            cout << "0\n";
            continue;
        } else {
            cur_id = id[hsh.val()];
        }

        string rest;

        rest.reserve(l + len - r);

        for (int i = 0; i < l; ++i) {
            rest.push_back(str1[i]);
        }
        rest.push_back(char(('z' + 1) - 'a'));
        for (int i = r + 1; i < len; ++i) {
            rest.push_back(str1[i]);
        }

        cout << info[cur_id].calc(int(rest.length()), rest) << "\n";
    }

    return 0;
}
// {
