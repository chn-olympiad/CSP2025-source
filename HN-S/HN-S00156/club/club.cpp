# include <bits/stdc++.h>
# define int long long 
using namespace std ;
constexpr int N = 1e5 + 5 ;  
int n , s[3][N] ;
struct node { int x , y , z , mx ;  } a[N] ; 
void solve () {
	memset ( s , 0 , sizeof s ) ; 
	int cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , sum = 0 ; 
	cin >> n ; for ( int i = 1 ; i <= n ; ++ i ) {
		cin >> a[i].x >> a[i].y >> a[i].z ,
		a[i].mx = max ( a[i].x , max ( a[i].y , a[i].z ) ) ; 
	}
	sort ( a + 1 , a + n + 1 , [&] ( node a , node b ) { return a.mx > b.mx ; } ) ; 
	for ( int i = 1 ; i <= n ; ++ i ) {
		if ( a[i].mx == a[i].x ) {
			s[0][++cnt1] = i , sum += a[i].x ; 
		}
		else if ( a[i].mx == a[i].y ) {
			s[1][++cnt2] = i , sum += a[i].y ; 
		}
		else if ( a[i].mx == a[i].z ) {
			s[2][++cnt3] = i , sum += a[i].z ; 
		}
		flct : ; 
	} 
	for ( int tt = 0 ; tt <= 2 ; ++ tt ) {
		if ( cnt1 > n / 2 ) {
			sort ( s[0] + 1 , s[0] + cnt1 + 1 , [&] ( int i , int j ) 
			{ return max ( a[i].y , a[i].z ) - a[i].x > max ( a[j].y , a[j].z ) - a[j].x ; } ) ; 
			for ( int i = 1 ; i <= cnt1 - n / 2 ; ++ i ) {
				int p = s[0][i] ; 
				sum += max ( a[p].y , a[p].z ) - a[p].x ; 
				if ( a[p].y > a[p].z ) s[1][++cnt2] = p ;
				else s[2][++cnt3] = p ;
			}
			cnt1 = n / 2 ; 
		}
		if ( cnt2 > n / 2 ) {
			sort ( s[1] + 1 , s[1] + cnt2 + 1 , [&] ( int i , int j ) 
			{ return max ( a[i].x , a[i].z ) - a[i].y > max ( a[j].x , a[j].z ) - a[j].y ; } ) ; 
			for ( int i = 1 ; i <= cnt2 - n / 2 ; ++ i ) {
				int p = s[1][i] ; 
				sum += max ( a[p].x , a[p].z ) - a[p].y ; 
				if ( a[p].x > a[p].z ) s[0][++cnt1] = p ;
				else s[2][++cnt3] = p ;
			}
			cnt2 = n / 2 ;
		}
		if ( cnt3 > n / 2 ) {
			sort ( s[2] + 1 , s[2] + cnt3 + 1 , [&] ( int i , int j ) 
			{ return max ( a[i].x , a[i].y ) - a[i].z > max ( a[j].x , a[j].y ) - a[j].z ; } ) ; 
			for ( int i = 1 ; i <= cnt3 - n / 2 ; ++ i ) {
				int p = s[2][i] ; 
				sum += max ( a[p].x , a[p].y ) - a[p].z ; 
				if ( a[p].x > a[p].y ) s[0][++cnt1] = p ;
				else s[1][++cnt2] = p ;
			}
			cnt3 = n / 2 ; 
		}
	}
	return cout << sum << '\n' , void () ; 
}
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) , cout.tie ( 0 ) ;
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ; 
	int T ; cin >> T ; 
	while ( T-- ) solve () ; 
}
// 一个数被换掉就再也不会被换回来，至多进行一次交换操作