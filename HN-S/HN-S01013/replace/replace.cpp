#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 4e5 + 10, M = 5e6 + 10;
const int B1 = 31, B2 = 37;
const int mod1 = 1e9 + 7, mod2 = 998244353;

struct Node {
    ll a, b, c, d;
    bool operator < (const Node &i) const {
        return a == i.a ? (b == i.b ? (c == i.c ? d < i.d : c < i.c) : b < i.b) : a < i.a;
    }
    bool operator == (const Node &i) const {
        return a == i.a && b == i.b && c == i.c && d == i.d;
    }
};

int n, q, c, tr[N * 100], rt[N], ls[N * 100], rs[N * 100], last[N * 100], top, stk[N * 100], lls[N * 100], lrs[N * 100];
ll P1[M], P2[M], h1[M], h2[M];
vector<Node> p, id;
vector<ll> tmp;

ll Get1(int l, int r) {
    return r < l ? 0 : (h1[r] - h1[l - 1] * P1[r - l + 1] % mod1 + mod1) % mod1;
}

ll Get2(int l, int r) {
    return r < l ? 0 : (h2[r] - h2[l - 1] * P2[r - l + 1] % mod2 + mod2) % mod2;
}

void pushup(int i) {
    tr[i] = tr[ls[i]] + tr[rs[i]];
}

void modify(int &i, int l, int r, int pos, int x) {
    if (!i) i = ++c;
    if (l == r) {
        tr[i] += x; return ;
    }
    int mid = (l + r) >> 1;
    pos <= mid ? modify(ls[i], l, mid, pos, x) : modify(rs[i], mid + 1, r, pos, x);
    pushup(i);
}

int Merge(int x, int y, int l, int r) {
    if (!x || !y) {
        stk[++top] = x + y;
        return x + y;
    }
    if (l == r) {
        tr[x] += tr[y], stk[++top] = x;
        return x;
    }
    int mid = (l + r) >> 1;
    ls[x] = Merge(ls[x], ls[y], l, mid);
    rs[x] = Merge(rs[x], rs[y], mid + 1, r);
    pushup(x), stk[++top] = x; return x;
}

int query(int i, int l, int r, int pos) {
    if (!i) return 0;
    stk[++top] = i;
    if (l == r) return tr[i];
    int mid = (l + r) >> 1;
    return pos <= mid ? query(ls[i], l, mid, pos) : query(rs[i], mid + 1, r, pos);
}

void Clear() {
    while (top) {
        int u = stk[top--];
        tr[u] = last[u], ls[u] = lls[u], rs[u] = lrs[u];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q, P1[0] = P2[0] = 1;
    for (int i = 1; i < N; i++) {
        P1[i] = P1[i - 1] * B1 % mod1;
        P2[i] = P2[i - 1] * B2 % mod2;
    }
    for (int i = 1; i <= n; i++) {
        string s1, s2; cin >> s1 >> s2;
        int len = s1.size(), l = -1, r = -1;
        s1 = ' ' + s1, s2 = ' ' + s2;
        for (int j = 1; j <= len; j++) {
            if (s1[j] != s2[j]) {
                if (l == -1) l = j;
                r = j;
            }
            h1[j] = (h1[j - 1] * B1 % mod1 + s1[j] - 'a' + 1) % mod1;
            h2[j] = (h2[j - 1] * B2 % mod2 + s2[j] - 'a' + 3) % mod2;
        }
        if (l == -1) continue;
        p.push_back({Get1(l, r), Get2(l, r), Get1(1, l - 1), Get1(r + 1, len)});
        tmp.push_back(Get1(r + 1, len));
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    sort(p.begin(), p.end());
    for (int i = 0, j; i < p.size(); ) {
        Node k = p[i]; k.d = -1, id.push_back(k);
        for (j = i; j < p.size() && k.a == p[j].a && k.b == p[j].b & k.c == p[j].c; j++);
        rt[id.size()] = ++c;
        for (; i < j; i++) {
            int t = lower_bound(tmp.begin(), tmp.end(), p[i].d) - tmp.begin() + 1;
            modify(rt[id.size()], 1, tmp.size(), t, 1);
        }
    }

    for (int i = 1; i <= c; i++) last[i] = tr[i], lls[i] = ls[i], lrs[i] = rs[i];

    for (int ttt = 1; ttt <= q; ttt++) {
        string t1, t2; cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << "0\n"; continue;
        }
        int len = t1.size(), l = -1, r = -1; t1 = ' ' + t1, t2 = ' ' + t2;
        for (int i = 1; i <= len; i++) {
            if (t1[i] != t2[i]) {
                if (l == -1) l = i;
                r = i;
            }
            h1[i] = (h1[i - 1] * B1 % mod1 + t1[i] - 'a' + 1) % mod1;
            h2[i] = (h2[i - 1] * B2 % mod2 + t2[i] - 'a' + 3) % mod2;
        }
        int nowrt = ++c;
        for (int i = 1; i <= l; i++) {
            Node k = {Get1(l, r), Get2(l, r), Get1(i, l - 1), -1};
            int pos = lower_bound(id.begin(), id.end(), k) - id.begin() + 1;
            if (id[pos - 1] == k) Merge(nowrt, rt[pos], 1, tmp.size());
        }
        int ans = 0;
        for (int i = r; i <= len; i++) {
            int pos = lower_bound(tmp.begin(), tmp.end(), Get1(r + 1, i)) - tmp.begin() + 1;
            if (tmp[pos - 1] == Get1(r + 1, i)) ans += query(nowrt, 1, tmp.size(), pos);
        }
        cout << ans << '\n', Clear();
    }
    return 0;
}
