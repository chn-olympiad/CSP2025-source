#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
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
using i32 = ll; using i64 = ll; using i128 = __int128;
using u32 = unsigned int; using u64 = unsigned ll;
using namespace std;
const i32 N = 1e5 + 5, inf = 1e16;
i32 n, ans, cnt[10], a[N][5], id[N];
fv sol() {
  cin >> n, ans = cnt[1] = cnt[2] = cnt[3] = 0;
  rep (i, 1, n) {
    vector <pii> S;
    rep (j, 1, 3) cin >> a[i][j], S.pb({a[i][j], j});
    sort(S.begin(), S.end(), greater <pii>());
    id[i] = S[0].se, ans += S[0].fi;
    cnt[id[i]]++;
  }
  i32 p = 0;
  rep (i, 1, 3) if (cnt[i] > n / 2) p = i;
  if (!p) return cout << ans << "\n", void();
  vi S;
  rep (i, 1, n) {
    if (id[i] != p) continue;
    i32 mx = inf;
    rep (j, 1, 3) if (j != p) mx = min(mx, a[i][p] - a[i][j]);
    S.pb(mx); 
  }
  sort(S.begin(), S.end());
//  cerr << cnt[p] << " " << ans << " ";
  i32 m = cnt[p] - n / 2;
//  cerr << S.size() << " " << m << "\n";
  rep (i, 0, m - 1) ans -= S[i];
  cout << ans << "\n";
}
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  IOS;
  i32 T; cin >> T;
  while (T--) sol();
}
