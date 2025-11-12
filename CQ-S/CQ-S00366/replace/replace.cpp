// Author: lzm0107

// 17:07 expect 100

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using aii = array<int, 2>;
using ull = unsigned long long;

const int INF32 = 0x3f3f3f3f;

const int N = 2e5, Q = 2e5, L = 5e6, C = 26, LOG2_L = 23;

int n, q;

struct ac_automaton {
    struct node {
        int go[C], fail, dep, end_cnt;
    };

    node d[L + 10];
    int tot;

    int jump[LOG2_L + 2][L + 10];

    void insert(const string &s) {
        int cur = 0;
        for (auto i : s) {
            int dir = i - 'a';
            if (d[cur].go[dir] == 0) {
                d[cur].go[dir] = ++tot;
                d[tot].dep = d[cur].dep + 1;
            }
            cur = d[cur].go[dir];
        }
        ++d[cur].end_cnt;
    }

    void build() {
        queue<int> que;
        for (int i = 0; i < C; ++i) {
            if (d[0].go[i] != 0) {
                que.push(d[0].go[i]);
            }
        }
        while (!que.empty()) {
            int u = que.front();
            d[u].end_cnt += d[d[u].fail].end_cnt;
            que.pop();
            for (int i = 0; i < C; ++i) {
                if (d[u].go[i] == 0) {
                    d[u].go[i] = d[d[u].fail].go[i];
                } else {
                    d[d[u].go[i]].fail = d[d[u].fail].go[i];
                    que.push(d[u].go[i]);
                }
            }
        }
        for (int i = 1; i <= tot; ++i) {
            jump[0][i] = d[i].fail;
        }
        for (int i = 1; i <= LOG2_L; ++i) {
            for (int j = 1; j <= tot; ++j) {
                jump[i][j] = jump[i - 1][jump[i - 1][j]];
            }
        }
    }

    ll query(const string &s) {
        int len = s.size() / 2;
        int l = INF32, r = ~INF32;
        for (int i = 0; i < len; ++i) {
            if (s[2 * i] != s[2 * i + 1]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        int cur = 0;
        ll res = 0;
        for (int i = 0; i < len; ++i) {
            cur = d[cur].go[s[2 * i] - 'a'];
            cur = d[cur].go[s[2 * i + 1] - 'a'];
            if (i >= r) {
                res += d[cur].end_cnt;
                int u = cur;
                for (int j = LOG2_L; j >= 0; --j) {
                    if (d[jump[j][u]].dep >= 2 * (i - l + 1)) {
                        u = jump[j][u];
                    }
                }
                if (d[u].dep >= 2 * (i - l + 1)) {
                    res -= d[d[u].fail].end_cnt;
                } else {
                    res -= d[u].end_cnt;
                }
            }
        }
        return res;
    }
};

ac_automaton ac;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> q;
    string os[2], s;
    for (int i = 1; i <= n; ++i) {
        cin >> os[0] >> os[1];
        s = "";
        for (int j = 0; j < (int)os[0].size(); ++j) {
            s += os[0][j];
            s += os[1][j];
        }
        ac.insert(s);
    }
    ac.build();
    for (int i = 1; i <= q; ++i) {
        cin >> os[0] >> os[1];
        if (os[0].size() != os[1].size()) {
            cout << 0 << '\n';
            continue;
        }
        s = "";
        for (int j = 0; j < (int)os[0].size(); ++j) {
            s += os[0][j];
            s += os[1][j];
        }
        cout << ac.query(s) << '\n';
    }
    return 0;
}