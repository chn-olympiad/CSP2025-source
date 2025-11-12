#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, cnt, r, x, j;
signed main() {
   freopen("seat.in", "r", stdin);
   freopen("seat.out", "w", stdout);
   cin >> n >> m;
   cin >> r;
   cnt = 1;
   for(int i = 2; i <= n * m; i ++){
      cin >> x;
      if(x > r)   cnt ++;
   }
   if(cnt % n == 0){
      j = cnt / n;
      if(j % 2 == 1){
         cout << j << " " << n << endl;
      }else{
         cout << j << " " << 1 << endl;
      }
   }else{
      j = cnt / n + 1;
      cnt %= n;
      if(j % 2 == 1){
         cout << j << " " << cnt << endl;
      }else{
         cout << j << " " << n - cnt + 1 << endl;
      }
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}