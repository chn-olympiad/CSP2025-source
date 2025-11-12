#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 510, p = 998244353;

int n, m, c[N], ans;
bool f[N], vis[N];

vector<int> b;

ll fac(int n){
  ll sum = 1;
  for(int i = 2; i <= n; i++){
    sum = sum * i % p;
  }
  return sum;
}

void dfs(int x){
  if(x == n + 1){
    int cnt = 0, tot = 0;
    for(int i = 0; i < n; i++){
      if(f[i + 1] == 0 || cnt >= c[b[i]]){
        cnt++;
      }
      else{
        tot++;
      }
    }
    if(tot >= m){
      ans =(ans + 1) % p;
    }
    return ;
  }
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    vis[i] = 1;
    b.push_back(i);
    dfs(x + 1);
    b.pop_back();
    vis[i] = 0;
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m;
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    char ch;
    cin >> ch;
    f[i] = ch - '0';
    cnt += f[i];
  }
  for(int i = 1; i <= n; i++){
    cin >> c[i];
  }
  if(cnt == n){
    cout << fac(n);
    return 0;
  }
  dfs(1);
  cout << ans;
  return 0;
}
/*
1 3 2
*/
