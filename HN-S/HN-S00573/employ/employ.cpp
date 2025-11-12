#include<bits/stdc++.h>

using namespace std;

const int MAXN = 11;

int n, m, c[MAXN], p[MAXN], ans;
bool vis[MAXN];
string s;

void dfs(int u){
  if(u == n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
      if(i - cnt < c[p[i]] && s[i] == '1') cnt++;
    }
    ans += (cnt >= m);
    return;
  }
  for(int i = 0; i < n; i++){
    if(!vis[i]){
      vis[i] = 1;
      p[u] = i;
      dfs(u + 1);
      vis[i] = 0;
    }
  }
}

int main(){
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  if(n > 10) return 0;
  for(int i = 0; i < n; i++){
    cin >> c[i];
  }
  dfs(0);
  cout << ans;
  return 0;
}
