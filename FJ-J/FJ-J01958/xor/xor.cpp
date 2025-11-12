#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 10;
int n, a[N], sum[N];

signed main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];
  
  set<int> st;
  st.emplace(0);
  
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (st.count(sum[i] ^ k)) cnt++, st.clear();
    
    st.emplace(sum[i]);
  }
  
  cout << cnt;
}
