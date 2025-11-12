#include<bits/stdc++.h>
using namespace std;

int n, a[5005], ans;

bool cmp(int a, int b){
  return a > b;
}

void mod(){
  ans %= 998244353;
}

void dfs(int m, int now, int sum){
  if(now > n) return;
  for(int i = now; i <= n; i++){
    if(a[i] + sum > m){
      ans = ans + pow(2, n - i);
      mod();
    }
    else{
      dfs(m, i + 1, sum + a[i]);
    }
  }
}

int main(){
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  sort(a + 1, a + n + 1, cmp);

  for(int i = 1; i <= n - 2; i++){
    for(int j = i + 1; j <= n - 1; j++){
      for(int k = j + 1; k <= n; k++){
        if(a[i] + a[j] + a[k] > a[i] * 2){
          ans = ans + pow(2, n - k);
          mod();
        }
        else{
          dfs(a[i] * 2, k + 1, a[i] + a[j] + a[k]);
        }
      }
    }
  }
  cout << ans;
  fclose(stdin);
  fclose(stdout);

  return 0;
}
