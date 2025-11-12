#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// #define int LL
int n;
const int maxn = 1e5 + 10;
int T;
struct staff {
  int v, id;
  inline bool operator < (const staff& t) const { 
    return v > t.v;
  }
} a[maxn][4];
vector<int>q[4]; 
inline void clear() {
  for(int i = 1; i <= 3; ++ i) q[i].clear();
}
inline void solve() {
  cin >> n;
  int ans = 0; 
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= 3; ++ j) cin >> a[i][j].v, a[i][j].id = j;
    sort(a[i] + 1, a[i] + 1 + 3); 
    q[a[i][1].id].emplace_back(i);
    ans += a[i][1].v;
  }
  if(q[1].size() <= n / 2 && q[2].size() <= n / 2 && q[3].size() <= n / 2) return cout << ans << '\n', void();
  int k;
  for(int i = 1; i <= 3; ++ i) if(q[i].size() > n / 2) k = i;
  sort(q[k].begin(), q[k].end(), [](const int x, const int y) {
    return a[x][2].v - a[x][1].v > a[y][2].v - a[y][1].v;
  });
  // cerr << k << ' ' << ans << '\n';
  for(int i = 1; i <= q[k].size() - n / 2; ++ i) ans += a[q[k][i - 1]][2].v - a[q[k][i - 1]][1].v;
  cout << ans << '\n'; 
}
signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while(T--) clear(), solve();
  return 0; 
}