#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##e = (r); i <= i##e; i++)
#define repp(i, l, r) for (int i = (l), i##e = (r); i < i##e; i++)
#define per(i, r, l) for (int i = (r), i##e = (l); i >= i##e; i--)

using namespace std;
using ll = long long;

template <class T>
void chkMax(T &a, T b) {
  a = max(a, b);
}
template <class T>
void chkMin(T &a, T b) {
  a = min(a, b);
}
template <class... Args>
void println(Args... args) {
  ((cerr << args << " "), ...);
  cerr << "\n";
}

struct Edge {
  int u, v;
  ll w;
  bool operator<(const Edge &x) {
    return w < x.w;
  }
};

const int N = 1e4 + 4;
int n, m, k;
vector<Edge> e;
int fa[N];

int find(int x) {
  return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void combi(int u, int v) {
  u = find(u), v = find(v);
  fa[u] = v;
}

void Horuscal() {
  ll ans = 0;
  for(auto [u, v, w] : e) {
    if(find(u) != find(v)) {
      combi(u, v);
      ans += w;
    }
  }
  cout << ans << "\n";
}

int main() {
  freopen("road.in", "r", stdin);
  //freopen("road3.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m >> k;
  iota(fa, fa + 1 + n, 0);
  for(int i = 1, u, v, w; i <= m && cin >> u >> v >> w; i++)
    e.push_back({u, v, w});

  for(int i = 1, c; i <= k && cin >> c; i++) {
    vector<int> a(n + 1), ze; // ze:涓庢潙瀛愯窛绂讳负0鐨勫煄甯?
    rep(j, 1, n) {
      cin >> a[j];
      if(a[j] == 0) ze.push_back(j);
    }
    repp(j, 0, ze.size() - 1)
      combi(ze[j], ze[j + 1]);
    rep(j, 1, n)
      if(j != ze[0]) e.push_back({j, ze[0], a[j]});
  }
  //cerr << "T\n";
  sort(e.begin(), e.end());
  Horuscal();
  return 0;
}