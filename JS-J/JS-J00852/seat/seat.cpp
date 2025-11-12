# include<bits/stdc++.h>
using namespace std ;
# define ll long long
ll n , m ;
ll a[200] ;

int main(){
    freopen( "seat.in" , "r" , stdin ) ;
    freopen( "seat.out" , "w" , stdout ) ;
cin >> n >> m ;
ll k ;
cin >> a[1] ;
k = a[1] ;
ll wei = 1 ;
for ( ll i = 2 ; i <= n * m ; ++ i ){
cin >> a[i] ;
if ( a[i] > k ){
wei ++ ;
}
}
ll lie = ( wei - 1 ) / n + 1 ;
ll han = wei % n ;
if ( lie % 2 == 0 ){
if ( han == 0 ){
cout << lie << " " << 1 ;
}
else {
cout << lie << " " <<  n - han + 1;
}
}
else{
if ( han == 0 ){

cout << lie << " " << n ;}
else {
cout << lie << " " << han ;
}
}



return 0 ;}
