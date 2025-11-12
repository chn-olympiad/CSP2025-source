#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[105], R, score, sn, sm;

bool cmp(int a, int b){
  return a > b;
}

int main(){
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n * m; i++){
    cin >> a[i];
  }
  score = a[1];

  sort(a + 1, a + n * m + 1, cmp);

  for(int i = 1; i <= n * m; i++){
    if(a[i] == score){
      R = i;
    }
  }

  sm = (R - 1) / n + 1;
  if(sm % 2 == 0){
    sn = n - R % n + 1;
    if(sn == n + 1) sn = 1;
  }
  else{
    sn = R % n;
    if(sn == 0) sn = n;
  }
  cout << sm << ' ' << sn;
  fclose(stdin);
  fclose(stdout);

  return 0;
}
