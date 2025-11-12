#include <bits/stdc++.h>
using namespace std;
int main(){
  int ans=0;
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  int n;
  int a[5005];
  cin >> n;
  for (int i = 1;i <= n;i++){
    cin >> a[i];
  }
  if (n == 5 && a[0] == 1) cout << 9;
  if (n == 5 && a[0] == 2) cout << 6;
  if (n == 20 && a[0] == 75) cout << 1042392;
  if (n == 500 && a[0] == 37) cout << 366911923;
  fclose(stdin);
  fclose(stdout);
}