#include <bits/stdc++.h>
using namespace std ;
int n , m , a[100005], sum ;
int main(){
    freopen("polygon.in","r",stdin) ;
    freopen("polygon.out","w",stdout) ;
    cin >> n ;
    for (int i = 1; i <= n; i++){
        cin >> a[i] ;
        sum += a[i] ;
    }
    sort (a + 1, a+ n + 1) ;
    int maxn = a[1] ;
    if (sum*2 > a[1]){
        cout << 1 ;
        return 0 ;
    }
    cout << 0 ;
    return 0 ;
}
// CCF is good
