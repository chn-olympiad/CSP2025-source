#include<bits/stdc++.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i ++)
#define per(i, s, t) for(int i = (s); i >= (t); i --)
using namespace std;
template<typename T>
inline void chmin(T& x, T y) { x = min(x, y); }
template<typename T>
inline void chmax(T& x, T y) { x = max(x, y); }
typedef long long ll;

const int N = 1e4 + 15, K = 15, M = 1e6 + 5;
int fa[N];
inline int find(int x) { while(x != fa[x]) x = fa[x] = fa[fa[x]]; return x; }

bool merge(int x, int y)
{
    x = find(x), y = find(y);
    if(x == y) return 0;
    fa[x] = y;
    return 1;
}

int u[M], v[M], w[M], id[M];

int c[K], a[K][N];

int n, m, k;

vector<tuple<int, int, int, int>> e;

struct fastio {
    static const int maxn = 1 << 20;
    char buf[maxn], *S = buf, *T = buf;
    char gc() { return ((S == T) ? T = (S = buf) + fread(buf, 1, maxn, stdin) : 0), ((S == T) ? EOF : *(S ++)); }
    void read(int &x)
    {
        bool f = 0;
        char c = gc();
        x = 0;
        while(!isdigit(c)) f |= c == '-', c = gc();
        while(isdigit(c)) x = x * 10 + c - '0', c = gc();
        if(f) x = -x;
    }
    fastio& operator>>(int& x) { read(x); return *this; }
} fin;

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    fin >> n >> m >> k;
    rep(i, 1, m) fin >> u[i] >> v[i] >> w[i], id[i] = i;
    sort(id + 1, id + m + 1, [](int x, int y) { return w[x] < w[y]; });
    rep(i, 1, k)
    {
        fin >> c[i];
        rep(j, 1, n) fin >> a[i][j], e.push_back({a[i][j], i - 1, n + i, j});
    }
    
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) if(merge(u[id[i]], v[id[i]]))
        e.push_back({w[id[i]], -1, u[id[i]], v[id[i]]});
    
    sort(e.begin(), e.end());
    ll ans = 1e18;
    // cerr << e.size() << endl;
    int C = 0;
    rep(i, 0, (1 << k) - 1)
    {
        rep(j, 1, n + k) fa[j] = j;
        ll res = 0;
        rep(j, 0, k - 1) if((i >> j) & 1) res += c[j + 1];
        // cerr << res << endl;
        C += e.size();
        for(auto [w, d, u, v] : e) if((d == -1 || ((i >> d) & 1)) && merge(u, v))
        {
            // cerr << w << " " << d << " " << u << " " << v << endl;
            res += w;
        }
        // cerr << i << " " << res << endl;
        chmin(ans, res);
    }
    // cerr << C << endl;
    cout << ans;

    return 0;
}