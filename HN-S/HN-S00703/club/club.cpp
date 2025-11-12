#include <fstream>
#include <queue>

using namespace std;
using LL = long long;

const LL kMaxN = 1e5 + 5;

ifstream cin("club.in");
ofstream cout("club.out");

struct Node {
  LL val, id, grp;
  
  Node(LL val, LL id, LL grp):
    val(val), id(id), grp(grp) { }
  
  friend bool operator<(const Node &a, const Node &b) {
    return a.val < b.val;
  }
};

LL cnt[3], f[kMaxN], a[kMaxN][3], t, n, ans;
priority_queue<Node> q[3];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> t; t; t--) {
    cin >> n;
    for (LL i = 1; i <= n; i++) {
      f[i] = -1;
      for (LL j = 0; j < 3; j++) {
        cin >> a[i][j];
      }
    }
    for (LL i = 0; i < 3; i++) {
      cnt[i] = 0;
      for (; q[i].size(); q[i].pop()) { }
    }
    ans = 0;
    for (LL i = 1; i <= n; i++) {
      LL mx = 0, p = 0;
      for (LL j = 0; j < 3; j++) {
        if (cnt[j] < n / 2) {
          if (a[i][j] > mx) {
            mx = a[i][j];
            p = j;
          }
        } else {
          if (q[j].empty()) {
            continue;
          }
          Node t = q[j].top();
          for (; j != f[t.id] || cnt[t.grp] >= n / 2; q[j].pop(), t = q[j].top()) { }
          LL x = t.val + a[i][j];
          if (x > mx) {
            mx = x;
            p = j;
          }
        }
      }
      ans += mx;
      if (cnt[p] < n / 2) {
        cnt[p]++;
        f[i] = p;
        for (LL j = 0; j < 3; j++) {
          if (j != p) {
            q[p].emplace(a[i][j] - a[i][p], i, j);
          }          
        }
      } else {
        Node t = q[p].top();
        cnt[t.grp]++;
        f[t.id] = t.grp;
        for (LL j = 0; j < 3; j++) {
          if (j != t.grp) {
            q[t.grp].emplace(a[t.id][j] - a[t.id][t.grp], t.id, j);
          }
        }
        f[i] = p;
        for (LL j = 0; j < 3; j++) {
          if (j != p) {
            q[p].emplace(a[i][j] - a[i][p], i, j);
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
