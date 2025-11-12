#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  int a[100005], pre[100005];
  for (int i = 1;i <= n;i ++) {
    cin >> a[i];
  }
  pre[1] = a[1];
  for (int i = 2; i <= n;i++) {
    pre[i] = a[i] ^ pre[i-1];
  }
  int left, right;
  int book[100005];
  int ans=0;
  for (left = 1; left <= n; left++){
    for (right = left; right <= n; right++){
      int value;
      if (left == right) value = a[left];
      else if  (left == 1) value = pre[right];
      else value = pre[right] ^ pre[left-1];
      if (value == k){
        bool flag = true;
        for (int i = left; i <= right;i ++) {
          if (book[i] == 1){
            flag = false;
            break;
          }
          book[i] = 1;
        }
        if (flag) {
          ans ++;
        }
      }
    }
  }
  fclose(stdin);
  fclose(stdout);
  cout << ans;
  return 0;
}