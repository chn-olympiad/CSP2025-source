#include <bits/stdc++.h>
#define rep(i, l, r) for (int i (l); i <= (r); ++ i)
#define rrp(i, l, r) for (int i (r); i >= (l); -- i)
#define eb emplace_back
#define pii pair <long long, long long>
#define ls (p << 1)
#define rs (ls | 1)
using namespace std;
constexpr int N = 5e6 + 5, M = 2e5 + 5, P = 1e9 + 9, Q = 998233853, B = 131; //注意模数
typedef long long ll;
inline int rd () {
  int x (0), f (1);
  char ch = getchar ();
  while (! isdigit (ch)) {
    if (ch == '-') f = -1;
    ch = getchar ();
  }
  while (isdigit (ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar ();
  } return x * f;
} //冷静
int qpow (int x, int y, int p) {
  int ret (1);
  for (; y; y >>= 1, x = x * x % p) if (y & 1) ret = ret * x % p;
  return ret;
}
char s[N];
int32_t main () {
  // freopen ("replace.in", "r", stdin);
  freopen ("replace.in", "w", stdout);
  int n = 2500, q = 2500;
  cout<<n<<" "<<q<<endl;
  mt19937 rnd (time (0));
  rep (i, 1, n) {
    rep (j, 1, 1000) putchar (s[j] = rnd () % 26 + 'a'); puts ("");
    s[500] = rnd () % 26 + 'a';
    rep (j, 1, 1000) putchar (s[j]); puts ("");
  }
  rep (i, 1, n) {
    rep (j, 1, 1000) putchar (rnd () % 26 + 'a'); puts ("");
    rep (j, 1, 1000) putchar (rnd () % 26 + 'a'); puts ("");
  }
}