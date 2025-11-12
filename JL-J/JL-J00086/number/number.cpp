#include <bits/stdc++.h>
using namespace std ;
int n , m , a[1000005], cnt, tong[10];
string s ;
int main(){
    freopen("number.in","r",stdin) ;
    freopen("number.out","w",stdout) ;
    cin >> s ;
    n = s.length() ;
    for (int i = 0; i < n; i++){
        if (s[i] >= '0' && s[i] <= '9'){
            tong[s[i] - '0'] ++ ;
            cnt++ ;
        }
    }
    for (int i = 9; i >= 0; i--){
        for (int j = 1; j <= tong[i]; j++){
            cout << i;
        }
    }
    return 0 ;
}
// CCF is good
