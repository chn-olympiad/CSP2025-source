#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int kMaxN = 1e5 + 10;

ll n, ans;

struct Node {
  ll v, id;
  bool operator< (const Node &b) const {
    return v > b.v;
  } 
} d[kMaxN][5];

struct Node2 {
  ll v, id, d;
  bool operator< (const Node2 &b) const {
    return d > b.d;
  }
};
priority_queue<Node2> q[4];

void S(ll i, ll forbid) {
  for (int j = 1; j <= 3; ++ j) {
    if (j <= forbid) {
      continue;
    }
    if (q[d[i][j].id].size() == n / 2) {
      auto x = q[d[i][j].id].top();
      if (j == 3 || d[x.id][j].v - d[x.id][j + 1].v < d[i][j].v - d[i][j + 1].v) {
        ans += d[i][j].v;
        ans -= x.v;
        S(x.id, j);
        q[d[i][j].id].pop();
        q[d[i][j].id].push({d[i][j].v, i, d[i][j].v - d[i][j + 1].v});
        break;
      }
    } else {
      q[d[i][j].id].push({d[i][j].v, i, d[i][j].v - d[i][j + 1].v});
      ans += d[i][j].v;
      break;
    }
  }
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  for (cin >> t; t; -- t) {
    cin >> n, ans = 0;
    for (ll i = 1; i <= n; ++ i) {
      cin >> d[i][1].v >> d[i][2].v >> d[i][3].v;
      d[i][1].id = 1, d[i][2].id = 2, d[i][3].id = 3;
      sort(d[i] + 1, d[i] + 4);
      S(i, 0);
    }
    for (int i = 1; i <= 3; ++ i) {
      for (; q[i].size(); q[i].pop());
    }
    cout << ans << '\n';
  } 
  return 0; 
} 
