#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[130];
int ans[11][11];
bool cmp(int i, int j) {
  return i > j;
}
int main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  cin >> n >> m;
  for (int i = 0;i < n*m;i++) {
    cin >> a[i];
  }
  int mark = a[0];
  sort(a, a+n*m, cmp);
  for (int i = 0;i < n*m; i++) {
    if (a[i] == mark){
      int c, r;
      if ((i/n) % 2 == 0){
        c = (i / n) + 1, r = (i % n) + 1;
      }
      else {
        c = (i / n) + 1, r = n - (i % n);
      }
      cout << c << " " << r;
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}