#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using LL = long long;

const LL kMaxN = 2e4 + 5, kMaxM = 1e6 + 5, kMaxK = 11;

ifstream cin("road.in");
ofstream cout("road.out");

struct Edge {
  LL u, v, w;
} e[kMaxM];

LL f[kMaxN], siz[kMaxN], c[kMaxK], ptr[kMaxK], n, m, k, ans;
pair<LL, LL> a[kMaxK][kMaxN];
vector<LL> id;
vector<Edge> v;

LL F(LL x) {
  return !f[x] ? x : f[x] = F(f[x]);
}

void U(LL u, LL v) {
  u = F(u), v = F(v);
  if (siz[u] > siz[v]) {
    swap(u, v);
  }
  f[u] = v;
  siz[v] += siz[u];
}

void init() {
  fill(f + 1, f + n + k + 1, 0);
  fill(siz + 1, siz + n + k + 1, 1);
  fill(ptr + 1, ptr + k + 1, 1);
}

LL solve() {
  init();
  LL res = 0, now = 0;
  while (1) {
    LL m1 = 1e18, m2 = 1e18, p2 = 0;
    for (; now < (LL)v.size() && F(v[now].u) == F(v[now].v); now++) { }
    if (now < (LL)v.size()) {
      m1 = v[now].w;
    }
    for (LL i : id) {
      for (; ptr[i] <= n && F(n + i) == F(a[i][ptr[i]].second); ptr[i]++) { }
      if (ptr[i] <= n && a[i][ptr[i]].first < m2) {
        m2 = a[i][ptr[i]].first;
        p2 = i;
      }
    }
    if (m1 == 1e18 && m2 == 1e18) {
      break;
    }
    if (m1 <= m2) {
      U(v[now].u, v[now].v);
      now++;
      res += m1;
    } else {
      U(n + p2, a[p2][ptr[p2]].second);
      ptr[p2]++;
      res += m2;
    }
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  v.reserve(n - 1);
  for (LL i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  for (LL i = 1; i <= k; i++) {
    cin >> c[i];
    for (LL j = 1; j <= n; j++) {
      cin >> a[i][j].first;
      a[i][j].second = j;
    }
    sort(a[i] + 1, a[i] + n + 1);
  }
  sort(e + 1, e + m + 1, [](const Edge &a, const Edge &b) {
    return a.w < b.w;
  });
  init();
  for (LL i = 1; i <= m; i++) {
    if (F(e[i].u) == F(e[i].v)) {
      continue;
    }
    U(e[i].u, e[i].v);
    v.push_back(e[i]);
    ans += e[i].w;
  }
  for (LL i = 1; i < 1 << k; i++) {
    id.clear();
    LL sum = 0;
    for (LL j = 1; j <= k; j++) {
      if (i >> (j - 1) & 1) {
        id.push_back(j);
        sum += c[j];
      }
    }
    ans = min(ans, sum + solve());
  }
  cout << ans << '\n';
  return 0;
}
