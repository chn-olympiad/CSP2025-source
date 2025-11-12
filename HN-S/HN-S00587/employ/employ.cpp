#include<bits/stdc++.h>

using namespace std;

const int maxn = 505, mod = 998244353;

int n, m, q, f2 = 1, ans, a[15], b[15], c[maxn], v[maxn];
string s;

bool C(){
  int tot = 0, u = 0;
  for(int i = 1; i <= n; i++){
    if(tot >= c[a[i]]) {
      tot++;
      continue;
    }
    if(s[i] == '0'){
      tot++;
    } else {
      u++;
    }
  }
  return u >= m;
}

void F(int x){
  if(x > n){
    ans = (ans + C()) % mod;
    return;
  }
  for(int i = 1; i <= n; i++){
    if(!v[i]){
      a[x] = i, v[i] = 1;
      F(x + 1);
      v[i] = 0;
    }
  }
}

int main(){
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  s = ' ' + s;
  for(int i = 1; i <= n; i++){
    cin >> c[i];
    if(s[i] == '0') f2 = 0;
  }
  if(n <= 10){
    F(1);
    cout << ans;
    return 0;
  }
  if(f2){
    long long s = 1;
    for(int i = 1; i <= n; i++){
      if(c[i]) q++;
    }
    for(int i = 1; i <= q; i++){
      s = s * i % mod;
    }
    cout << s;
    return 0;
  }
  return 0;
}
