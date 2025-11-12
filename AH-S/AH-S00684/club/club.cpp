#include<bits/stdc++.h>
using namespace std;

int t, n, ans;
int a[100005], fvv;

bool cmp(int a, int b){
  return a > b;
}

int main(){
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin >> t;
  while(t--){
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
      cin >> a[i] >> fvv >> fvv;
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n / 2; i++){
      ans += a[i];
    }
    cout << ans << endl;
  }

  return 0;
}
