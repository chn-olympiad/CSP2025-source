#include <bits/stdc++.h>
using namespace std;
#define FULL(v) begin(v), end(v)
#define ALL(v, l, r) begin(v) + l, begin(v) + r + 1
using tp = long long int;
constexpr tp INF = 1e18;

template <typename T>
bool ckmin(T &x, T y) {
   if (y < x) return x = y, 1;
   return 0;
}
template <typename T>
bool ckmax(T &x, T y) {
   if (y > x) return x = y, 1;
   return 0;
}

constexpr tp b1 = 13331, mod = 1e9 + 21;
tp norm(tp x) { return x + (x < 0) * mod - (x >= mod) * mod; }
void add(tp &x, tp y) { x = norm(x + y); }
tp pow(tp x, tp y) {
   tp z = 1;
   for (; y; x = 1ll * x * x % mod, y >>= 1ll)
      if (y & 1ll) z = 1ll * z * x % mod;
   return z;
}

void QWQ() {
   freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   return ;
}

constexpr tp N = 2e5 + 5, M = 5e6 + 5;
tp n, m, q;
struct Info {
   tp l, r, h1, h2, m;
};
array<Info, N> a;
array<tp, M> h1, h2, pw;
tp h_1(tp l, tp r) {
   if (l < 0 || r >= m) return INF;
   if (l == 0) return h1[r];
   return (h1[r] - h1[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}
tp h_2(tp l, tp r) {
   if (l < 0 || r >= m) return INF;
   if (l == 0) return h2[r];
   return (h2[r] - h2[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

tp HARUTO() {
   pw[0] = 1;
   for (tp i = 1; i < M; ++i) pw[i] = pw[i - 1] * b1 % mod;
   cin >> n >> q;
   for (tp i = 1; i <= n; ++i) {
      string s, t; cin >> s >> t;
      a[i].m = s.size(), a[i].h1 = a[i].h2 = a[i].l = 0, a[i].r = a[i].m - 1;
      while (a[i].l < a[i].m && s[a[i].l] == t[a[i].l]) ++a[i].l;
      while (a[i].r >= 0 && s[a[i].r] == t[a[i].r]) --a[i].r;
      for (tp j = 0; j < a[i].m; ++j)
         a[i].h1 = (a[i].h1 * b1 + s[j]) % mod, a[i].h2 = (a[i].h2 * b1 + t[j]) % mod;
      //cout << a[i].l << ' ' << a[i].r << ' ' << a[i].m << ' ' << a[i].h1 << ' ' << a[i].h2 << "\n";
   }
   for (tp i = 1; i <= q; ++i) {
      string s, t; cin >> s >> t;
      m = s.size();
      if (t.size() != m) { cout << "0\n"; continue; }
      h1[0] = s[0] % mod, h2[0] = t[0] % mod;
      for (tp j = 1; j < m; ++j)
         h1[j] = (h1[j - 1] * b1 + s[j]) % mod, h2[j] = (h2[j - 1] * b1 + t[j]) % mod;
      tp ans = 0;
      tp L = 0, R = m - 1;
      while (L < m && s[L] == t[L]) ++L;
      while (R >= 0 && s[R] == t[R]) --R;
      //cout << h1[m - 1] << ' ' << h2[m - 1] << "\n";
      for (tp j = 1; j <= n; ++j) {
         tp ll = L - a[j].l, rr = R + a[j].m - a[j].r - 1;
         if (a[j].h1 == h_1(ll, rr) && a[j].h2 == h_2(ll, rr)) ans++;
      }
      cout << ans << "\n";
   }
   return 0;
}

int main() {
   QWQ();
   tp t = 1; // cin >> t;
   while (t--) HARUTO();
   return 0;
}