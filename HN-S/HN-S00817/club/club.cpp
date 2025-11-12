#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, f[N], c[4], cnt1;
long long ans;

struct Node{
  int x, y, z;
}a[N];

void dfs(int cnt, long long sum){
  if(cnt1 >= 1e7){
    return;
  }
  cnt1++;
  if(cnt == n + 1){
    ans = max(ans, sum);
    return;
  }
  if(c[1] < n / 2){
    c[1]++;
    dfs(cnt + 1, sum + a[cnt].x);
    c[1]--;
  }
  if(c[2] < n / 2){
    c[2]++;
    dfs(cnt + 1, sum + a[cnt].y);
    c[2]--;
  }
  if(c[3] < n / 2){
    c[3]++;
    dfs(cnt + 1, sum + a[cnt].z);
    c[3]--;
  }
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  ans = 0, cnt1 = 0;
  dfs(1, 0);
  cout << ans << '\n';
}

int main(){
  freopen("club3.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while(t--){
    solve();
  }//Çå¿Õ
  return 0;
}
