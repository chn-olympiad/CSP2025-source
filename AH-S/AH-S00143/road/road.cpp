//exam: road.cpp
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
//#define OI
using namespace std;
struct node {
    int u, v, w;
    bool flag;
    bool operator < (const node &nxt) const {
        return w < nxt.w;
    }
};
const int MAXN = 1e4+5, MAXM = 1e6+5;
void init(int);
bool unite(int, int);
bool same(int, int);
vector<node> a;
bool book[15];
int cnt[15], cost[15];
int c[MAXN];
int n, m, k;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("road.in", "r", stdin);
    #ifndef OI
    freopen("road.out", "w", stdout);
    #endif

    cin >> n >> m >> k;
    init(n + k);

    a.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].flag = false;
    }
    for(int u = n + 1; u <= n + k; u++) {
        cin >> c[u];
        for(int v = 1, w; v <= n; v++) {
            cin >> w;
            a.push_back((node){u, v, w, false});
            a.push_back((node){u, v, w + c[u], true});
        }
    }

    sort(a.begin(), a.end());

    int res = 0;
    for(auto e : a) {
        if(!same(e.u, e.v)) {
            if(e.u > n && (e.flag ^ book[e.u - n])) { // the country
                book[e.u - n] = true;
                cnt[e.u - n]++;
                cost[e.u - n] = e.w;
                res += e.w;
                unite(e.u, e.v);
                //cout << "!" << e.u << " " << e.v << " " << e.w << endl;
            } else if(e.u <= n) { // the city
                res += e.w;
                unite(e.u, e.v);
                //cout << e.u << " " << e.v << " " << e.w << endl;
            }
        }
    }

    for(int i = 1; i <= k; i++) {
        //cout << i + n << " " << cnt[i] << endl;
        if(cnt[i] == 1) { // foolish edge
            res -= cost[i];
        }
    }
    cout << res;
    return 0;
}
int fa[MAXN];
void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
int find(int x) {
    if(fa[x] == x) {
        return x;
    }
    return fa[x] = find(fa[x]);
}
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
        fa[x] = y;
        return true;
    }
    return false;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
