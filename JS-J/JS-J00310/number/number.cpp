#include <bits/stdc++.h>
using namespace std;
string s ;
int a[1000010] ;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s ;
    int j = 1 ;
    for ( int i = 0 ; i < s.size() ; i ++ ){
        if ( s[i] >= '0' && s[i] <= '9' ){
            a[j] = s[i] - '0' ;
            j ++ ;
        }
    }
    sort(a+1,a+j) ;
    for ( j = j - 1 ; j >= 1 ; j -- ){
        cout << a[j] ;
    }
    return 0;
}
