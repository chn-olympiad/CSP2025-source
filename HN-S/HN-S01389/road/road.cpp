#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int kMaxN = 1e4 + 10;

ll n, m, k, fa[kMaxN], c[kMaxN], a[11][kMaxN], ans, cnt;
bool ok, okk;

struct Node {
  ll u, v, w;
  bool operator< (const Node &b) const {
    return w < b.w;
  }
}; 
vector<Node> v;

ll F(ll x) {
  return fa[x] == x? x : fa[x] = F(fa[x]);
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k, ok = 1;
  for (ll i = 1, u, _v, w; i <= m; ++ i) {
    cin >> u >> _v >> w;
    v.push_back(Node{u, _v, w});
  }
  for (int i = 1; i <= n + 1; ++ i) {
    fa[i] = i;
  }
  for (int i = 1; i <= k; ++ i) {
    cin >> c[i];
    ok &= (c[i] == 0);
    okk = 0;
    for (int j = 1; j <= n; ++ j) {
      cin >> a[i][j];
      okk |= (a[i][j] == 0);
    }
    ok &= okk;
  } 
  if (1) {
    for (int i = 1; i <= k; ++ i) {
      for (int j = 1; j <= n; ++ j) {
        v.push_back(Node{n + 1, j, a[i][j] + c[i]});
      }
    } 
    sort(v.begin(), v.end());
    ll x, y;
    for (auto i : v) {
      if (cnt == n - 1) {
        break;
      }
      x = F(i.u), y = F(i.v);
      if (x != y) {
        fa[x] = y;
        ++ cnt;
        ans += i.w;
      }
    }
    cout << ans << '\n';
  }
  return 0; 
} 

