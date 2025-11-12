#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct P{
  int val, cnt[3];
}f[N][3];
bool cmp(int a1, int a2){
  return a1 > a2;
}
int a[N][3], t, n, tmp[N];
void solve(){
  cin >> n;
  bool f1 = 1,f2 = 1;
  for(int i = 1; i <= n; i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    if(a[i][1] != 0){
      f1 = 0;
    }
    if(a[i][2] != 0){
      f2 = 0;
    }
    f[i][0].val = f[i][1].val = f[i][2].val = -1;
    f[i][0].cnt[0] = f[i][0].cnt[1] = f[i][0].cnt[2] = 0;
    f[i][1].cnt[0] = f[i][1].cnt[1] = f[i][1].cnt[2] = 0;
    f[i][2].cnt[0] = f[i][2].cnt[1] = f[i][2].cnt[2] = 0;
  }
  if(f1 && f2){
    for(int i = 1; i <= n; i++){
      tmp[i] = a[i][0];
    }
    sort(tmp + 1, tmp + 1 + n, cmp);
    int ans = 0;
    for(int i = 1; i <= n / 2; i++){
      ans += tmp[i];
    }
    cout << ans << '\n';
    return ;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        if(f[i - 1][k].cnt[j] + 1 <= n / 2){
          if(f[i - 1][k].val + a[i][j] > f[i][j].val){
            f[i][j].val = f[i - 1][k].val + a[i][j];
            f[i][j].cnt[0] = f[i - 1][k].cnt[0];
            f[i][j].cnt[1] = f[i - 1][k].cnt[1];
            f[i][j].cnt[2] = f[i - 1][k].cnt[2];
            f[i][j].cnt[j]++;
          }
        }
      }
      cout << f[i][j].val << '|' << f[i][j].cnt[0] << '|' << f[i][j].cnt[1] << '|' << f[i][j].cnt[2] << ' ';
    }
    cout << '\n';
  }
  cout << max({f[n][0].val, f[n][1].val, f[n][2].val}) << '\n';
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
