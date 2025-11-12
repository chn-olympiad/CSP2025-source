#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],Num;
int main(){
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
     cin >> t;
     for (int i = 1;i <= t;i++){
           Num = 0;
           cin >> n;
           for (int j = 1;j <= n;j++){
                  cin >> a[j][0] >> a[j][1] >> a[j][2];
                  if (j % 2 == 0){
                       Num += a[j][1];
                  }
                  else{
                       Num += a[j][2];
                  }
            }
            cout << Num;
     }
     return 0;
}
