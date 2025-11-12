#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define U(i, a, b) for (int i = (a); i <= (b); i++)
#define drep(i, a, b) for (int i = (a); i >= b; i--)
#define pii pair<ll, ll>
#define fi first
#define se second
#define ld lower_bound
#define ud upper_bound
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define fv inline void
#define fn inline static
#define mp make_pair
#define mem(s, k) memset(s, k, sizeof(s))
using i32 = ll; using i64 = ll; using i128 = __int128;
using u32 = unsigned int; using u64 = unsigned ll;
using namespace std;
const i32 N = 5e6 + 5, Q = 2e5 + 5, mod = 998244353;
bool bg;
#define puu pair<u64, u64>
struct Hash {
  u64 p1[N], h1[N], p2[N], h2[N];
  fv init(string s) {
    i32 n = s.length(); s = " " + s;
    h1[0] = h2[0] = p1[0] = p2[0] = 1;
    rep (i, 1, n) {
      p1[i] = p1[i - 1] * 1331, p2[i] = (p2[i - 1] * 13331) % mod;
      h1[i] = h1[i - 1] * 1331 + s[i], h2[i] = (h2[i - 1] * 13331 + s[i]) % mod;
    }
  }
  inline puu qry(i32 l, i32 r) {
    return {h1[r] - h1[l - 1] * p1[r - l + 1], (h2[r] - h2[l - 1] * p2[r - l + 1] % mod + mod) % mod};
  }
} H[2];
i32 n, q;
string s[Q][2], t[2];
fn u64 has1(string &s) {
  u64 H = 0;
  for (char x : s) H = H * 1331 + x;
  return H;
}
fn u64 has2(string &s) {
  u64 H = 0;
  for (char x : s) H = (H * 13331 + x) % mod;
  return H;
}

map <pair<puu, puu>, i32> T;
const i32 B = 90;
vi S;
puu ha[Q][2];
bool ed;
fv sol() {
  cin >> n >> q;
  rep (i, 1, n) {
    cin >> s[i][0] >> s[i][1];
    i32 m = s[i][0].size();
    ha[i][0] = mp(has1(s[i][0]), has2(s[i][0])), ha[i][1] = mp(has1(s[i][1]), has2(s[i][1]));
    if (m <= B) T[mp(ha[i][0], ha[i][1])]++;
    else S.pb(i);
  }
  rep (i, 1, q) {
    cin >> t[0] >> t[1];
    H[0].init(t[0]), H[1].init(t[1]);
    i32 n = t[0].size(), ans = 0;
    rep (l, 1, n) {
      if (H[0].qry(1, l - 1) != H[1].qry(1, l - 1)) break;
      rep (r, l, n) {
        if (r - l + 1 > B) break;
        if (H[0].qry(r + 1, n) != H[1].qry(r + 1, n)) continue;
        puu s1 = H[0].qry(l, r), s2 = H[1].qry(l, r);
        if (T.count(mp(s1, s2))) ans += T[mp(s1, s2)];
      }
    }
    for (i32 idx : S) {
      i32 m = s[idx][0].size();
      rep (i, 1, n - m + 1) {
        if (H[0].qry(1, i - 1) != H[1].qry(1, i - 1)) break;
        if (H[0].qry(i + m, n) != H[1].qry(i + m, n)) continue;
        if (H[0].qry(i, i + m - 1) == ha[idx][0] && H[1].qry(i, i + m - 1) == ha[idx][1]) ans++; 
      }
    }
    cout << ans << "\n";
  }
}
int main() {
//  cerr << (&bg - &ed) * 1.0 / 1024 / 1024 << "\n";
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  IOS;
  i32 T = 1;
//  cin >> T;
  while (T--) sol();
}
