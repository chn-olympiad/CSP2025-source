#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
typedef long long LL;

const int N = 1e4 + 305, kS = (1 << 5) + 5;

int n, m, k;

struct dsu {
  int fa[N];
  void clear(int n) {
    rep (i, 1, n) fa[i] = i;
  }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  bool chk(int i, int j) { return find(i) == find(j); }
  void mrg(int i, int j) { fa[find(i)] = find(j); }
} d;

struct graphs {
  vector<tuple<int, int, int>> eg, ne;
  void res(int m) { eg.reserve(m); }
  void add(int u, int v, int w) {
    eg.emplace_back(w, u, v);
  }
  LL mst(bool _sorted = 0) {
    ne.clear(), d.clear(n + k);
    LL ans = 0;
    if (!_sorted) sort(eg.begin(), eg.end());
    for (auto [w, u, v] : eg) {
      if (d.chk(u, v)) continue;
      d.mrg(u, v), ans += w, ne.emplace_back(w, u, v);
    }
    vector<tuple<int, int, int>>().swap(eg), swap(eg, ne);
    return ans;
  }
  LL mrg(const graphs &x) {
    int i = 0, j = 0;
    while (i < eg.size() && j < x.eg.size()) {
      if (get<0>(eg[i]) < get<0>(x.eg[j]))
        ne.push_back(eg[i]), i ++;
      else ne.push_back(x.eg[j]), j ++;
    }
    while (i < eg.size()) ne.push_back(eg[i]), ++ i;
    while (j < x.eg.size()) ne.push_back(x.eg[j]), ++ j;
    vector<tuple<int, int, int>>().swap(eg), swap(eg, ne);
    return mst(1);
  }
} L[kS], R[kS], G, hg[15];

LL vL[kS], vR[kS], c[15];


void fakemain() {
  cin >> n >> m >> k, G.res(m);
  rep (i, 1, m) {
    int u, v, w; cin >> u >> v >> w;
    G.add(u, v, w);
  }
  LL ans = G.mst();
  rep (i, 1, k) {
    cin >> c[i];
    rep (j, 1, n) {
      int w; cin >> w, hg[i].add(n + i, j, w);
    }
    sort(hg[i].eg.begin(), hg[i].eg.end());
  }
  int ll = k / 2, rr = k - ll;
  L[0] = R[0] = G;
  rep (i, 1, (1 << ll) - 1) {
    int p = __lg(i);
    L[i] = L[i ^ (1 << p)], L[i].mrg(hg[p + 1]);
    vL[i] = vL[i ^ (1 << p)] + c[p + 1];
  }
  rep (i, 1, (1 << rr) - 1) {
    int p = __lg(i);
    R[i] = R[i ^ (1 << p)], R[i].mrg(hg[p + ll + 1]);
    vR[i] = vR[i ^ (1 << p)] + c[p + 1 + ll];
  }
  graphs tmp;
  rep (i, 0, (1 << ll) - 1) {
    rep (j, 0, (1 << rr) - 1) {
      tmp = L[i];
      LL vv = tmp.mrg(R[j]) + vL[i] + vR[j];
      ans = min(ans, vv);
    }
  }
  cout << ans << '\n';
}

void file(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(0), cout.tie(0);
  file("road");
  int tc, T = 1;
  // cin >> T;
  while (T --) fakemain();
  cerr << 1. * clock() / CLOCKS_PER_SEC << "s\n";
}