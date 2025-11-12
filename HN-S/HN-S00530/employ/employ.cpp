#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e2 + 1;
const int mod = 998244353;

int n, m, ans, cnt, fact = 1, c[MAXN], a[MAXN];
string s;
bool f = 1, f1, f2, f3 = 1;

inline bool check(){
  int cnt = 0, p = 0;
  for(int i = 1; i <= n; i++){
    if(cnt >= c[a[i]] || s[i - 1] == '0'){
      cnt++;
    }else{
      p++;
    }
  }
  return p >= m;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  for(int i = 1; i <= n; i++){
    cin >> c[i];
    f2 |= (!c[i]);
    f3 &= (!c[i]);
    fact = 1ll * fact * i % mod;
    a[i] = i;
  }
  for(int i = 0; i < n; i++){
    f &= (s[i] == '1');
    f1 |= (s[i] == '1');
    cnt += (s[i] == '1');
  }
  if(cnt < m){
    cout << 0;
    return 0;
  }
  if(f){
    cout << fact;
    return 0;
  }
  if(m == 1){
    if(f1 && !f3){
      cout << fact;
    }else{
      cout << 0;
    }
    return 0;
  }
  if(m == n){
    if(f && !f2){
      cout << fact;
    }else{
      cout << 0;
    }
    return 0;
  }
  do{
    (ans += check()) %= mod;
  }while(next_permutation(a + 1, a + 1 + n));
  cout << ans;
  return 0;
}
