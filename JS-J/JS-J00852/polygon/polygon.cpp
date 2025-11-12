# include<bits/stdc++.h>
using namespace std ;
# define ll long long
const int N = 5005 ;
int a[N] ;
int n ;
int ans ;
ll p = 998244353 ;

inline void dfs( int now , int sum , int num , int maxn ){
if( now > n ) {
    if ( sum >= 3  &&  num > (2*maxn) ) ans ++ ;
    return ;
}

dfs( now + 1 , sum + 1 , num + a[now] , max(maxn , a[now] ) ) ;
dfs( now + 1 , sum , num , maxn ) ;

}
inline ll solveA( ){
ll sum = 0 ;
for ( int i = n - 2 ; i >= 1 ; -- i ) sum += i ;
return sum ;

}
int main(){
    freopen("polygon.in" , "r" , stdin ) ;
    freopen("polygon.out" , "w" , stdout ) ;
cin >> n ;
bool ddd = true ;
for ( ll i = 1 ; i <= n ; ++ i ){
    cin >> a[i] ;
    if ( a[i] != 1 ){
        ddd = false ;
    }
}
if ( ddd == true ){
    cout << solveA()%p ;
    return 0 ;
}
dfs( 1 , 0 , 0 , 0 ) ;
cout << ans % p ;



return 0 ;}
