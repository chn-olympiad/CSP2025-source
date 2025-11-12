#include<bits/stdc++.h>
using namespace std;

int n, k, num, kk[25], lk, ans, jj;
bool flag;
struct node{
  int lself;
  bool self[25];
  int sum[25];
}a[500005];

void to2(int i){
  int ls = 0;
  while(num != 0){
    a[i].self[++ls] = num % 2;
    num /= 2;
  }
  if(ls != 0){
    a[i].lself = ls;
  }
  else{
    a[i].lself = 1;
  }
}

void kto2(){
  while(k != 0){
    kk[++lk] = k % 2;
    k /= 2;
  }
}

int main(){
  freopen("xor.in", "r", stdin);
  freopen("xor.out", "w", stdout);
  cin >> n >> k;
  kto2();
  for(int i = 1; i <= n; i++){
    cin >> num;
    to2(i);
  }
  for(int i = 1; i <= 24; i++){
    a[1].sum[i] = a[1].self[i];
  }
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= 24; j++){
      a[i].sum[j] = (a[i].self[j] + a[i - 1].sum[j]) % 2;
    }
  }
  for(int i = n; i >= 1;){
    for(int j = i - 1; j >= 0; j--){
        flag = 0;
      for(int m = 1; m <= 24; m++){
        if(abs(a[i].sum[m] - a[j].sum[m]) != kk[m]){
          flag = 1;
          break;
        }
      }
      if(!flag){
        ans++;
        jj = j;
        break;
      }
    }
    if(!flag){
      i = jj;
    }
    else{
      i--;
    }
  }
  cout << ans;
  fclose(stdin);
  fclose(stdout);

  return 0;
}
