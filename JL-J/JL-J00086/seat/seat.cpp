#include <bits/stdc++.h>
using namespace std ;
int n , m , a[105], cnt, b[15][15];
string s ;
int main(){
    freopen("seat.in","r",stdin) ;
    freopen("seat.out","w",stdout) ;
    cin >> n >> m ;
    for (int i = 1; i <= n * m ; i ++){
        cin >> a[i] ;
    }
    int x = a[1] ;
    sort (a + 1, a + (n * m) + 1) ;
    int l = 0 ;
    for (int i = m*n+1; i >=1; i--){
        if (a[i] == x){
            break ;
        }
        l++ ;
    }
    int sumx = (l / m);
    if (l % m != 0) sumx++ ;
    int sumy = l % n ;
    if (sumy == 0) sumy = m ;
    if (sumx % 2 == 0){
        sumy = n - (sumy - 1);
    }
    cout << sumx << ' ' << sumy ;
    return 0 ;
}
// CCF is good
