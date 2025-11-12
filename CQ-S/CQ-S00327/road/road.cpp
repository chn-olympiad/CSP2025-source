#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> PII;
#define pb push_back
#define vi vector <int>
#define R(i, l, r) for (int i = (l); i <= (r); ++i)
#define debug cout << "-------------------------------\n"

const int N = 1e4 + 5, P = 998244353, M = 1e6 + 5, DF = 2e5 + 5;
int n, m, k;
int tot = 0;
struct edge {
    int u, v, w;
    bool operator < (const edge &t) const {
        return w < t.w;
    }
} arr[M], e[DF], o[DF];
int a[12][N], c[N];
ll ans = 0;
int fa[DF];
void init() {
    R(i, 1, n + k) {
        fa[i] = i;
    }
}
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    fa[find(x)] = find(y);
}
inline void mst(int num, ll ss) {
    init();
    sort(e + 1, e + tot + 1);
    ll sum = ss;
    int cnt = 0;
    R(i, 1, tot) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (find(u) == find(v)) continue;
        merge(u, v);
        sum += w;
        ++cnt;
        if (cnt == n - 1 + num) break;
    }
//    cout << num << ' ' << ss << ' ' << sum << endl;
    ans = min(ans, sum);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    R(i, 1, m) {
        cin >> arr[i].u >> arr[i].v >> arr[i].w;
    }
    R(i, 1, k) {
        cin >> c[i];
        R(j, 1, n) {
            cin >> a[i][j];
        }
    }
    sort(arr + 1, arr + m + 1);
    int cnt = 0;
    init();
    R(i, 1, m) {
        int u = arr[i].u, v = arr[i].v, w = arr[i].w;
        if (find(u) == find(v)) continue;
        merge(u, v);
        ans += w;
        ++cnt;
        e[++tot] = arr[i];
        if (cnt == n - 1) break;
    }
    R(i, 1, tot) {
        o[i] = e[i];
    }
//    cout << ans << '\n'; // ????mst ????????
    R(i, 1, (1 << k) - 1) {
        int len = tot;
        ll ss = 0;
        R(j, 1, tot) {
            e[j] = o[j];
        }
        R(j, 1, k) {
            if (i >> (j - 1) & 1) {
                ss += c[j];
                R(p, 1, n) {
                    e[++tot] = {n + j, p, a[j][p]};
                }
            }
        }
        int eg = __builtin_popcount(i);
        mst(eg, ss);
        tot = len;
    }
    cout << ans << '\n';
    return 0;
}

