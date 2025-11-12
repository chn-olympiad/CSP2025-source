#include <bits/stdc++.h>
using namespace std;
#define FULL(v) begin(v), end(v)
#define ALL(v, l, r) begin(v) + l, begin(v) + r + 1
using tp = int;
constexpr tp INF = 2e9;

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

constexpr tp mod = 998244353;
tp norm(tp x) { return x + (x < 0) * mod - (x >= mod) * mod; }
void add(tp &x, tp y) { x = norm(x + y); }
tp pow(tp x, tp y) {
   tp z = 1;
   for (; y; x = 1ll * x * x % mod, y >>= 1ll)
      if (y & 1ll) z = 1ll * z * x % mod;
   return z;
}

void QWQ() {
   freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   return ;
}

constexpr tp N = 1e5 + 5;
tp n;

tp HARUTO() {
   cin >> n;
   tp sum = 0;
   array<vector<tp>, 3> p;
   for (tp i = 1; i <= n; ++i) {
      tp a, b, c; cin >> a >> b >> c;
      if (a >= max(b, c)) p[0].emplace_back(a - max(b, c)), sum += a;
      else if (b >= max(a, c)) p[1].emplace_back(b - max(a, c)), sum += b;
      else p[2].emplace_back(c - max(a, b)), sum += c;
   }
   tp m = n >> 1;
   for (tp i = 0; i <= 2; ++i) {
      sort(FULL(p[i]));
      tp k = p[i].size() - m;
      for (tp j = 0; j < k; ++j) sum -= p[i][j];
   }
   cout << sum << "\n";
   return 0;
}

int main() {
   QWQ();
   tp t = 1; cin >> t;
   while (t--) HARUTO();
   return 0;
}