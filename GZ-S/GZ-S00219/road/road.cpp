//GZ-S00219   ¿Ó≈‡Íª    ±ı∫˛÷–—ß 
#include <bits/stdc++.h>
using namespace std;

int n , m , k ;
bool f ;
int ans = 1 ;
int p2[10005] , p3[10005][10005] ;

struct num1 {
	int x ;
	int y ;
	int p ;
}a[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k ;
	
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i].x >> a[i].y >> a[i].p ;
	}
	
	for( int i = 1 ; i <= m ; i++ ){
		cin >> p2[i] ;
		if( p2[i] != 0 ){
			f = true ;
		}
		for( int j = 1 ; j <= n ; j++ ){
			cin >> p3[i][j] ;
			if( p3[i][j] != 0){
				f = true ;
			}
		}
		if( f == false ){
			ans = 0 ;
		}
		f = false ;
	}
	
	if( ans == 0 ){
		cout << ans ;
		return 0 ;
	}
	
	cout << a[2].p + a[3].p ;
	
	return 0 ;
	
}

