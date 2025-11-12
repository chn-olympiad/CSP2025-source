#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define per(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define PII pair<int, int>

struct num {
    int x, y, v;
};

const int N = 10010, K = 20;
int n, m, k;
int x, y, v;
int c[K], a[K][N], fa[N], mi[K];
vector<num> e;
vector<int> C;
int s[N], opt;
ll ans;

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void dijkstra() {
    ll res = 0;
    rep(i, 1, n)
        fa[i] = i;
    int sz = e.size();
    rep(i, 0, sz - 1) {
        auto [x, y, v] = e[i];
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            res += v, fa[fy] = fx;
            s[++opt] = i;
        }
    }
    ans = res;
}

bool cmp(const num &x, const num &y) {
    return x.v < y.v;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 1, m) {
        scanf("%d%d%d", &x, &y, &v);
        e.push_back({x, y, v});
    }
    sort(e.begin(), e.end(), cmp);
    dijkstra();
    rep(i, 1, k) {
        mi[i] = 1 << 30;
        scanf("%d", &c[i]);
        rep(j, 1, n)
            scanf("%d", &a[i][j]), mi[i] = min(mi[i], a[i][j]);
    }
    rep(i, 0, (1 << k) - 1) {
        ll res = 0;
        rep(j, 1, k)
            if(i & (1 << (j - 1)))
                res += c[j], C.push_back(j);
        rep(j, 1, opt) {
            auto [x, y, v] = e[s[j]];
            ll ma = v;
            int xx = 0;
            for(auto l : C)
                if(a[l][x] + a[l][y] < ma)
                    xx = l, ma = a[l][x] + a[l][y];
            res += ma;
        }
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
}
