#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, K = (1 << 20) + 5;

int f[N], a[N], sum[N], lst[K];

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) sum[i] = (sum[i - 1] ^ a[i]);
  memset(lst, -1, sizeof(lst));
  lst[0] = 0;
  for(int i = 1; i <= n; i++) {
    f[i] = f[i - 1];
    if(~lst[sum[i] ^ k]) f[i] = max(f[i], f[lst[sum[i] ^ k]] + 1);
    lst[sum[i]] = i;
  }
  cout << f[n] << '\n';
}

int main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}