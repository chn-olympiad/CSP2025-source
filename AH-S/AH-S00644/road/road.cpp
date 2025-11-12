#include <bits/stdc++.h>
using namespace std;

#define filename "road"
//#define multicases

#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

template<class T> bool vmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool vmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
template<class T> void clear(T &a) { a.swap(T()); }

const int N = 1e5+5, M = 1e6+5;

int n, m;
struct edge {
    int u, v, w;
    bool operator < (edge &y) { return w < y.w; }
} orig[M];

int fa[N + 100], sz[N + 100];
int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
int unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return 0;
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    fa[y] = x;
    return 1;
}

int k, c[N];
edge e[N], a[15][N];

edge E[N * 15], t[N * 15];
int tot;
void Merge(edge *a, edge *b) {
    int i = 1, j = 1, len = 0;
    while(i <= tot && j <= n) {
        if(a[i] < b[j]) t[++len] = a[i++];
        else t[++len] = b[j++];
    }
    while(i <= tot) t[++len] = a[i++];
    while(j <= tot) t[++len] = b[j++];
    tot += n;
    upw(i, 1, tot) a[i] = t[i];
}

void WaterM() {
    cin >> n >> m >> k;
    upw(i, 1, m) scanf("%d%d%d", &orig[i].u, &orig[i].v, &orig[i].w);
    sort(orig+1, orig+m+1);

    upw(i, 1, n) fa[i] = i, sz[i] = 1;
    int etot = 0;
    upw(i, 1, m) {  // |E| ---> O(n)
        int u = orig[i].u, v = orig[i].v, w = orig[i].w;
        if(unite(u, v)) e[++etot] = {u, v, w};//, cerr << u << ' ' << v << ' ' << w << '\n';
    }

    upw(j, 1, k) {
        scanf("%d", &c[j]);
        upw(i, 1, n) {
            int w;
            scanf("%d", &w);
            a[j][i] = {j + n, i, w};
        }
        sort(a[j]+1, a[j]+n+1);
    }
    long long ans = Linf;
    upw(mask, 0, (1 << k) - 1) {    //select some vertices to urbanize
        tot = etot;
        upw(i, 1, tot) E[i] = e[i];

        //cerr << mask << '\n';

        //merge the ascending arrays
        long long res = 0;
        upw(j, 1, k) if(mask & (1 << (j-1))) {
            Merge(E, a[j]);
            res += c[j];
        }
        upw(i, 1, n+k) fa[i] = i, sz[i] = 1;
        upw(i, 1, tot) {
            int u = E[i].u, v = E[i].v, w = E[i].w;
            if(unite(u, v)) res += w;//, cerr << u << ' ' << v << ' ' << w << '\n';
        }
        vmin(ans, res);
        //cerr << res << '\n';
    }
    cout << ans << '\n';
}

signed main() {
#ifdef filename
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
#endif // filename

    signed _ = 1;
#ifdef multicases
    scanf("%d", &_);
#endif // multicases

    while(_--) WaterM();
}
