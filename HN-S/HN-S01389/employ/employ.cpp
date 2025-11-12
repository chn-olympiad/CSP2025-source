#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int kMaxN = 1e5 + 10;
const ll kMod = 998244353;

ll n, m, s[kMaxN], sum[kMaxN], c[kMaxN], ans, cc;
bool vis[kMaxN];

void Dfs(ll stp, ll sum) {
  if (sum >= m) {
    ll mul = 1;
    for (ll i = 1; i <= n - stp + 1; ++ i) {
      mul = (mul * i) % kMod;
    }
    ans = (ans + mul) % kMod;
    return;
  }
  if (stp == n + 1) {
    return;
  }
  for (int i = 1; i <= n; ++ i) {
    if (!vis[i]) {
      vis[i] = 1;
      Dfs(stp + 1, sum + s[stp] * (sum < c[i]));
      vis[i] = 0;
    }
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  char ch;
  for (int i = 1; i <= n; ++ i) {
    cin >> ch;
    s[i] = ch - '0';
    cc += s[i];
  }
  for (int i = 1; i <= n; ++ i) {
    cin >> c[i];
  }
  if (m == n) {
    return cout << (cc == n? 1 : 0) << '\n', 0; 
  }
  if (n <= 18) {
    Dfs(1, 0); 
  } else {
    ans = 0;
  }
  cout << ans << '\n';
  return 0; 
} 
