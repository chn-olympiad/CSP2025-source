/*
Coder : CJSY242203 CXM
tips : 033999
Password : Ren5Jie4Di4Ling5%
Pass all simple On :
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 5;

int Test, n, a[N][4];

priority_queue<pii> que1, que2, que3;

void solve () {
  cin >> n;
  while (que1.size ()) que1.pop ();
  while (que2.size ()) que2.pop ();
  while (que3.size ()) que3.pop ();
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][1] >> a[i][2] >> a[i][3];
    int u = max (a[i][1], max (a[i][2], a[i][3]));
    if (a[i][1] == u) que1.push ({max (a[i][2], a[i][3]) - a[i][1], a[i][1]});
    else if (a[i][2] == u) que2.push ({max (a[i][1], a[i][3]) - a[i][2], a[i][2]});
    else que3.push ({max (a[i][1], a[i][2]) - a[i][3], a[i][3]});
    ans += u;
  }
  while (que1.size () > (n >> 1)) {
    ans += que1.top ().first;
    que1.pop ();
  }
  while (que2.size () > (n >> 1)) {
    ans += que2.top ().first;
    que2.pop ();
  }
  while (que3.size () > (n >> 1)) {
    ans += que3.top ().first;
    que3.pop ();
  }
  cout << ans << '\n';
}

int main () {
  freopen ("club.in", "r", stdin);
  freopen ("club.out", "w", stdout);
  ios :: sync_with_stdio (0), cin.tie (0);
  for (cin >> Test; Test--; solve ()) {
  }
  return 0;
}
/*
// freopen ()
  this is a never gonna give you up sentence.
  to day (11.1) is cxm's birthday, and I hope :
  CSP_J = 400, CSP_S = max (CSP_S, 300), rp += inf;
*/
