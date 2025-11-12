#include <iostream>
#include <set>
#include <ctime>
using namespace std;
using pii = pair <int, int>;
using ll = long long;
const int maxn = 100010;
int n, a[maxn][3];
multiset <pii> s;
ll ans;
int dx, p[maxn];
int s0, s1, s2;
void solve (int A, int B, int C) {
  // cout << A << ' ' << B << ' ' << C << endl;
  dx = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i] == A) {
      dx++;
      s.insert ({a[i][B] - a[i][A], i});
      s.insert ({a[i][C] - a[i][A], i});
    }
  }
  dx -= n / 2;
  // cout << s.size () << ' ' << dx << endl;
  for (int _ = 1; _ <= dx; _++) {
    // if (s.size () == 0) {
    //   cerr << "KK";
    //   break;
    // }
    auto [v, i] = *s.rbegin ();
    // cout << ' ' << v << ' ' << i << endl;
    ans += v;
    s.erase (s.find ({a[i][B] - a[i][A], i}));
    s.erase (s.find ({a[i][C] - a[i][A], i}));
  }
}
int main () {
  freopen ("club.in", "r", stdin);
  freopen ("club.out", "w", stdout);
  cin.tie (0)->sync_with_stdio (false);
  int T; cin >> T;
  while (T--) {
    s0 = s1 = s2 = 0;
    cin >> n;
    ans = 0;
    s.clear ();
    for (int i = 1; i <= n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
      if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
        ans += a[i][0];
        p[i] = 0; 
        s0++;
      } else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
        ans += a[i][1];
        p[i] = 1; 
        s1++;
      } else {
        ans += a[i][2];
        p[i] = 2; 
        s2++;
      }
    }
    // cout << s[0].size () << ' ' << s[1].size () << ' ' << s[2].size () << endl;

    if (s0 > n / 2) {
      solve (0, 1, 2); 
    } else if (s1 > n / 2) {
      solve (1, 0, 2); 
    } else if ((s2 > n / 2)) {
      solve (2, 0, 1); 
    }
    cout << ans << '\n';
  }
  // cerr << clock () / 1000 << '\n';
  return 0;
}