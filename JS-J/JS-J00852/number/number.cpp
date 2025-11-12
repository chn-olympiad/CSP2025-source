# include<bits/stdc++.h>
using namespace std ;
const int N = 1000000 + 10 ;
string a ;
int b[N] ;
int main(){
freopen( "number.in" , "r" , stdin ) ;
freopen( "number.out" , "w" , stdout ) ;
cin >> a ;
int cnt = 1 ;
for ( int i = 0 ; i < a.size() ; ++ i ){
if ( a[i] >='0' && a[i] <='9' ) {
int k = a[i] - '0' ;
b[cnt++] = k ;
}
}
sort( b + 1 , b + cnt + 1 ) ;
for ( int i = cnt ; i > 1 ; -- i ){
cout << b[i] ; }






return 0 ;}
