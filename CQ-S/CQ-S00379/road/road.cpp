#include<bits/stdc++.h>
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define rep2(i, a, b) for(int i = a; i >= b; --i)
#define ft first
#define sd second
#define pii pair <int, int>
#define ll long long
#define pb push_back
#define gmin(a, b) a = min(a, b)
#define gmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define debug cout << "------------------\n"
const int N = 2e4 + 10, M = 2e6 + 10;
using namespace std;
struct node {
    int u, v, w;
} e[M];
int pa[N], c[15], hd[15]; pii a[15][N];
int find(int x) {return pa[x] == x ? x : pa[x] = find(pa[x]);}
void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return ; pa[u] = v;
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    rep1(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    int flg = 1;
    rep1(i, 1, k) {
        cin >> c[i];
        rep1(j, 1, n) cin >> a[i][j].ft, a[i][j].sd = j;
        sort(a[i] + 1, a[i] + n + 1);
        if(c[i] || a[i][1].ft) flg = 0;
    }
    if(flg) {
        // cout << flg << "!!!\n";
        rep1(i, 1, k) {
            int u = a[i][1].sd;
            rep1(j, 2, n) {
                int v = a[i][j].sd;
                e[++m] = {u, v, a[i][j].ft};
            }
        }
    }
    sort(e + 1, e + m + 1, [&](const node &x, const node &y) {
        return x.w < y.w;
    });
    int tot = 0; ll ans = 0;
    rep1(i, 1, n) pa[i] = i;
    rep1(i, 1, m) {
        auto [u, v, w] = e[i];
        // cout << find(u) << ' ' << find(v) << ' ' << w << '\n';
        if(find(u) == find(v)) continue;
        e[++tot] = {u, v, w}; merge(u, v); ans += w;
    }
    if(flg) return cout << ans << '\n', void();

    int lmt = (1 << k) - 1;
    rep1(S, 0, lmt) {
        vector <int> id;
        ll sum = 0;
        rep1(i, 0, k - 1) if(S >> i & 1) {
            id.pb(i + 1), hd[i + 1] = 1;
            sum += c[i + 1];
        }
        int cnt = 0;
        rep1(i, 1, n + k) pa[i] = i;
        rep1(i, 1, tot) {
            auto [u, v, w] = e[i];
            auto getnw = [&]() {
                int idx = 0;
                for(auto x : id) {
                    if(a[x][hd[x]].ft < w) idx = x;
                }
                return idx;
            };
            while(true) {
                int x = getnw(), y = a[x][hd[x]].sd;
                if(!x) break;
                if(find(n + x) != find(y)) {
                    sum += a[x][hd[x]].ft;
                    // cout << n + x << ' ' << y << '\n';
                    merge(n + x, y); cnt += hd[x] > 1;
                }
                ++hd[x]; if(cnt == n - 1) break;
            }
            if(find(u) != find(v)) {
                sum += w; merge(u, v); ++cnt;
            } if(cnt == n - 1) break;
            // rep1(j, 1, n) cout << find(j) << " \n"[j == n];
        }
        // cout << S << ' ' << sum << '\n';
        gmin(ans, sum);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int T = 1; //cin >> T;
    while(T--) solve();
    return 0;
}