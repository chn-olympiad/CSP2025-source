#include <bits/stdc++.h>

#define fin(s) freopen(s".in", "r", stdin)
#define fout(s) freopen(s".out", "w", stdout)

using i64 = long long;
using namespace std;

template<typename T>
void read(T &x) {
    char ch = getchar();
    x = 0;
    T f = 1;

    while (!isdigit(ch)) {
        f -= (ch == '-') << 1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch & 15);
        ch = getchar();
    }

    x *= f;
}
template<typename T, typename ...L>
void read(T &x, L &...y) {
    read(x);
    read(y...);
}

constexpr int N = 2E5 + 5, L = 5E6 + 5, L2 = 2.5E6 + 5;

constexpr i64 P1 = 1145141923, B1 = 13331;
constexpr i64 P2 = 1E9 + 7, B2 = 233;

int n, q;
int ans[N];
string S, T;

struct Hashh {
    i64 h1, h2;
    Hashh() {
        h1 = h2 = 0;
    }
    void add(char c) {
        int id = c - 'a' + 1;
        h1 = (h1 * B1 + id) % P1;
        h2 = (h2 * B2 + id) % P2;
    }
    bool operator<(const Hashh &p) const {
        return h1 == p.h1 ? h2 < p.h2 : h1 < p.h1;
    }
    bool operator==(const Hashh &p) const {
        return h1 == p.h1 && h2 == p.h2;
    }
};

struct Data {
    int a, b;
    Hashh x, y;
    int i;
    bool operator<(const Data &p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
} a[N * 2];

struct Trie {
    int tr[L][26];
    int cnt, l[L], r[L];
    int tot, rt;
    string ti;
    
    int ins(int &x, int i) {
        if (!x) {
            x = ++tot;
        }
        if (i == ti.size()) {
            return x;
        }
        int v = ti[i] - 'a';
        return ins(tr[x][v], i + 1);
    }

    int query(int x, int i) {
        if (i == ti.size()) {
            return x;
        }
        int v = ti[i] - 'a';
        if (!tr[x][v]) {
            return x;
        }
        return query(tr[x][v], i + 1);
    }

    void dfs(int x) {
        l[x] = ++cnt;
        for (int i = 0; i < 26; ++i) {
            if (tr[x][i]) {
                dfs(tr[x][i]);
            }
        }
        r[x] = cnt;
    }
} A, B;

pair<int, int> getlr() {
    int len = S.size();
    int l = len, r = -1;
    for (int j = 0; j < len; ++j) {
        if (S[j] != T[j]) {
            l = min(l, j);
            r = max(r, j);
        }
    }
    return {l, r};
}

vector<array<int, 3>> v;

int fen[L];

void add(int x, int val) {
    for (; x <= B.tot; x += x & -x) {
        fen[x] += val;
    }
}
int query(int x) {
    int res = 0;
    for (; x; x -= x & -x) {
        res += fen[x];
    }
    return res;
}

void solve(int l, int r) {
    // for (int i = l; i <= r; ++i) {
    //     cerr << "(" << a[i].a << ", " << a[i].b << ", " << a[i].i << ")\n";
    // }
    // cerr << "-------------\n";
    v.clear();
    for (int i = l; i <= r; ++i) {
        if (a[i].i != 0) {
            v.push_back({A.l[a[i].a], B.l[a[i].b], a[i].i});
        } else {
            v.push_back({A.l[a[i].a], B.l[a[i].b], 0});
            v.push_back({A.l[a[i].a], B.r[a[i].b] + 1, -1});
            v.push_back({A.r[a[i].a] + 1, B.l[a[i].b], -1});
            v.push_back({A.r[a[i].a] + 1, B.r[a[i].b] + 1, 0});
        }
    }
    sort(v.begin(), v.end());
    for (auto _ : v) {
        auto x = _[0], y = _[1], i = _[2];
        if (i <= 0) {
            i += (i == 0);
            add(y, i);
        } else {
            ans[i] += query(y);
        }
    }
    for (auto _ : v) {
        auto x = _[0], y = _[1], i = _[2];
        if (i <= 0) {
            i += (i == 0);
            add(y, -i);
        }
    }
}

int main() {
    fin("replace");
    fout("replace");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> S >> T;
        
        auto _ = getlr();
        auto l = _.first, r = _.second;
        int len = S.size();
        if (r == -1) {
            a[i].i = -1;
            continue;
        }

        string As = S.substr(0, l);
        reverse(As.begin(), As.end());
        string Bs = (r == len - 1 ? "" : S.substr(r + 1, len - 1 - r));
        A.ti = As;
        B.ti = Bs;
        a[i].a = A.ins(A.rt, 0);
        a[i].b = B.ins(B.rt, 0);

        for (int j = l; j <= r; ++j) {
            a[i].x.add(S[j]);
            a[i].y.add(T[j]);
        }

        a[i].i = 0;

        // cerr << As << " " << Bs << "\n";
        // cerr << S << " " << T << "\n";
        // cerr << "i : " << i << "\n";
        // cerr << l << " " << r << "\n";
        // cerr << a[i].a << " " << a[i].b << " " << a[i].x.h1 << " " << a[i].y.h1 << "\n";
    }

    for (int i = n + 1; i <= n + q; ++i) {
        cin >> S >> T;
        if (S.size() != T.size()) {
            a[i].i = -1;
            continue;
        }

        int len = S.size();
        auto _ = getlr();
        auto l = _.first, r = _.second;
        assert(~r);

        string As = S.substr(0, l);
        reverse(As.begin(), As.end());
        string Bs = (r == len - 1 ? "" : S.substr(r + 1, len - 1 - r));
        A.ti = As;
        B.ti = Bs;

        a[i].a = A.query(A.rt, 0);
        a[i].b = B.query(B.rt, 0);

        for (int j = l; j <= r; ++j) {
            a[i].x.add(S[j]);
            a[i].y.add(T[j]);
        }

        a[i].i = i - n;
    }

    A.dfs(A.rt);
    B.dfs(B.rt);

    sort(a + 1, a + 1 + n + q);

    for (int i = 1, j = 1; i <= n + q; i = j) {
        if (a[i].i == -1) {
            j = i + 1;
            continue;
        }
        while (j <= n + q && a[i].x == a[j].x && a[i].y == a[j].y) {
            j++;
        }
        solve(i, j - 1);
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}