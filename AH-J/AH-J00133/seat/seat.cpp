#include <bits/stdc++.h>
using namespace std;
int a[15][15],b[110];
int main () {
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n,m;
    cin >>n >>m;
    for (int i=1;i<=n*m;i++) cin >>b[i];
    int c=b[1];
    sort (b+1,b+n*m+1);
    int sum=1,j2=m*n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (sum%2) {
               a[j][i]=b[j2--];
            }
            else a[n+1-j][i]=b[j2--];
        }
        sum++;
     }
     for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[j][i]==c) {
               cout <<i <<' ' <<j <<'\n';
               return 0;
            } 
        }
      }
      return 0;
}
