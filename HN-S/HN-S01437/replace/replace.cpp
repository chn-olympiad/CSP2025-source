#include <iostream>
#include <unordered_map>
#include <map>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200010; 
using ll = long long;

int n, m;

namespace case1 {
#define mod 1000001011
string s[maxn][2];
const ll b = 27;
struct V {
  ll v0, v1;
  bool operator < (const V& _) const {
    if (v0 == _.v0) return v1 < _.v1;
    return v0 < _.v0;
  }
};

map <V, int> p;
void solve () {

  for (int i = 1; i <= n; i++) {
    cin >> s[i][0] >> s[i][1];
    int len = s[i][0].size ();
    V v = V {0, 0};
    for (int j = 0; j < len; j++) {
      v.v0 = (v.v0 * b % mod + s[i][0][j] - 'a' + 1) % mod;
      v.v1 = (v.v1 * b % mod + s[i][1][j] - 'a' + 1) % mod;
    }
    p[v]++;
  }
  while (m--) {
    string t0, t1;
    cin >> t0 >> t1;
    t0 = ' ' + t0;
    t1 = ' ' + t1;
    int len = t1.size ();
    ll res = 0;
    int l, r;
    l = 1; r = len;
    while (t0[l] == t1[l] && l <= len) l++;
    while (t0[r] == t1[r] && r > 0) r--;

    for (int i = 1; i <= l; i++) {
      V v = V {0, 0};
      for (int j = i; j <= len; j++) {
        v.v0 = (v.v0 * b % mod + t0[j] - 'a' + 1) % mod;
        v.v1 = (v.v1 * b % mod + t1[j] - 'a' + 1) % mod;
        if (j >= r) {
          res += p[v];
          // cout << i << ' ' << j << endl;
        }
      }
    }
    cout << res << '\n';
  }
}
}

struct E {
  int x, y, id;
}; 

int res[maxn];
unordered_map <int, vector <E>> p;
 
int c[10000010];
int N = 5e6 + 100;
void add (int x, int v) {
  if (!x) {
    c[0] += v;
    x = 1;
  }
  for (; x <= N; x += (x & -x)) c[x] += v;
}

int Q (int x) {
  int sum = 0;
  for (; x; x -= (x & -x)) sum += c[x];
  return sum + c[0];
}
int main () {

  freopen ("replace.in", "r", stdin);
  freopen ("replace.out", "w", stdout); 
  cin.tie (0)->sync_with_stdio (false);
  cin >> n >> m;

  if (n <= 1000 && m <= 1000) {
    case1::solve ();
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    string s0, s1;
    cin >> s0 >> s1;
    s0 = ' ' + s0;
    s1 = ' ' + s1;
    int i0, i1;
    int len = s0.size ();
    for (int j = 1; j <= len; j++)
      if (s0[j] == 'b') i0 = j;
    for (int j = 1; j <= len; j++)
      if (s1[j] == 'b') i1 = j;
    p[i0 - i1].push_back (E {i0 - 1, len - i0, 0});
  }
  for (int i = 1; i <= m; i++) {
    string s0, s1;
    cin >> s0 >> s1;
    int i0, i1;
    s0 = ' ' + s0;
    s1 = ' ' + s1;
    int len = s0.size ();
    for (int j = 1; j <= len; j++)
      if (s0[j] == 'b') i0 = j;
    for (int j = 1; j <= len; j++)
      if (s1[j] == 'b') i1 = j;
    p[i0 - i1].push_back (E {i0 - 1, len - i0, i});
    // if (i == m - 1) cerr << i0 - i1 << endl;
  }

  for (auto [_, t] : p) {
    if (t.size () == 1) continue;
    sort (t.begin (), t.end (), [] (E A, E B) {
      if (A.x == B.x) {
        if (A.y == B.y) return A.id < B.id;
        return A.y < B.y;
      }
      return A.x < B.x;
    });
    // if (_ == -29) {   
    //   cerr << _ << ' ' << t.size () << endl;
    // }
    for (auto [x, y, id] : t) {
      if (id == 0) add (y, 1);
      else res[id] = Q (y);
    }
    for (auto [x, y, id] : t) {
      if (id == 0) add (y, -1);
    }
  } 
  for (int i = 1; i <= m; i++) cout << res[i] << '\n';

  // cerr << clock () / 1000 << endl;
  return 0;
}