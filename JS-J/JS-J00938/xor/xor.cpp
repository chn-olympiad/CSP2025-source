#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  int n, k; scanf("%d%d", &n, &k);
  vector<int> vec(n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &vec[i]);
  
  }
  vector<int> add(n);
  add[0] = vec[0];
  for (int i = 1; i < n; i ++) {
    add[i] = add[i - 1] ^ vec[i];
  }
  int j = 0;
  while (j < n) {
    bool flag = true;
    for (int i = j + 1; i < n; i ++) {
      if (add[i] ^ add[j] == k) {
        j = i;
        ans ++;
        flag = false;
        break;
      }
    }
    if (flag) {
      j ++;
    }
  }
  cout << ans;
  return 0;
}