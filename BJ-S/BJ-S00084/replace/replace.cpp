#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int L = 5e6 + 10;

struct Edge {
    int v, next;
} pool[L];
int ne, head[L];

void addEdge(int u, int v) {
    pool[++ne] = {v, head[u]};
    head[u] = ne;
}

struct Op {
    int x, y, z, w, id;
//      x, l, r, w, 0   for modify
//      x, y, 0, w, id  for query
    inline bool operator<(const Op &b) const {
        if(x != b.x) return x < b.x;
        return id < b.id;
    }
};

int n, q;
int ans[N];
int pt[N][2];

int chd[L][26], fail[L], nn;
int que[L], hd = 1, tl = 0;
int dfn[L], sz[L], dt;
int insert(string &s) {
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        int d = s[i] - 'a';
        if(!chd[cur][d]) chd[cur][d] = ++nn;
        cur = chd[cur][d];
    }
    return cur;
}
void dfs(int u) {
    dfn[u] = ++dt; sz[u] = 1;
    for(int e = head[u]; e; e = pool[e].next) {
        int v = pool[e].v;
        dfs(v);
        sz[u] += sz[v];
    }
}
void build() {
    for(int i = 0; i < 26; i++) if(chd[0][i]) que[++tl] = chd[0][i];
    while(hd <= tl) {
        int u = que[hd++];
        for(int i = 0; i < 26; i++) {
            if(chd[u][i]) {
                fail[chd[u][i]] = chd[fail[u]][i];
                que[++tl] = chd[u][i];
            } else chd[u][i] = chd[fail[u]][i];
        }
    }
    for(int i = 1; i <= nn; i++) addEdge(fail[i], i);
    dfs(0);
}

namespace BIT {
    int sum[L];
    inline void add(int l, int r, int v) {
        for(int i = l; i <= nn + 2; i += i & -i) sum[i] += v;
        for(int i = r + 1; i <= nn + 2; i += i & -i) sum[i] -= v;
    }
    inline int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i & -i) res += sum[i];
        return res;
    }
}

vector<Op> op;
void add_modify(int l1, int r1, int l2, int r2) {
    op.push_back({l1, l2, r2, 1, 0});
    op.push_back({r1 + 1, l2, r2, -1, 0});
}
void add_query(int x, int y, int id, int w) {
    op.push_back({x, y, 0, w, id});
}

signed main() {

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        string a, b; cin >> a >> b;
        pt[i][0] = insert(a);
        pt[i][1] = insert(b);
    }
    build();
    for(int i = 1; i <= n; i++) {
        int x = pt[i][0], y = pt[i][1];
        add_modify(dfn[x], dfn[x] + sz[x] - 1, dfn[y], dfn[y] + sz[y] - 1);
    }
    for(int i = 1; i <= q; i++) {
        string a, b; cin >> a >> b;
        if(a.size() != b.size()) continue;
        int mn = L + 5, mx = -1;
        for(int j = 0; j < a.size(); j++) {
            if(a[j] != b[j]) {
                mn = min(mn, j);
                mx = max(mx, j);
            }
        }
        int cur1 = 0, cur2 = 0;
        for(int j = 0; j < a.size(); j++) {
            int c1 = a[j] - 'a', c2 = b[j] - 'a';
            cur1 = chd[cur1][c1], cur2 = chd[cur2][c2];
            if(j >= mx) add_query(dfn[cur1], dfn[cur2], i, 1);
        }
        cur1 = 0, cur2 = 0;
        for(int j = mn + 1; j < a.size(); j++) {
            int c1 = a[j] - 'a', c2 = b[j] - 'a';
            cur1 = chd[cur1][c1], cur2 = chd[cur2][c2];
            if(j >= mx) add_query(dfn[cur1], dfn[cur2], i, -1);
        }
    }

    sort(op.begin(), op.end());
    for(Op &o : op) {
        if(o.id) ans[o.id] += BIT::query(o.y) * o.w;
        else BIT::add(o.y, o.z, o.w);
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';

    return 0;
}