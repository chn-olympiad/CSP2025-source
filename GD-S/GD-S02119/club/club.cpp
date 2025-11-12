#include <bits/stdc++.h>
#define N 100010
#define rint register int
using namespace std;
int n , ans;
int que[4][N] , p[4];

inline void init(){
	ans = 0;
	memset( p , 0 , sizeof(p) );
}

inline void deal( const int &k ){
	stable_sort( que[k]+1 , que[k]+1+p[k] , []( int a,int b ){ return a>b; } );
	while( p[k] > n/2 )	ans -= que[k][ p[k]-- ];
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d", &T );
	while( T-- ){
		init();
		scanf("%d", &n );
		int s1 , s2 , s3;
		for( rint i=1; i <= n; ++i ){
			scanf("%d%d%d", &s1 , &s2 , &s3 );
			if( s1>=s2 && s1>=s3 ){
				ans += s1;
				if( s2 > s3 )	que[1][ ++p[1] ] = s1-s2;
				else	que[1][ ++p[1] ] = s1-s3;
			}
			else if( s2>=s1 && s2>=s3 ){
				ans += s2;
				if( s1 > s3 )	que[2][ ++p[2] ] = s2-s1;
				else	que[2][ ++p[2] ] = s2-s3;
			}
			else{
				ans += s3;
				if( s1 > s2 )	que[3][ ++p[3] ] = s3-s1;
				else	que[3][ ++p[3] ] = s3-s2;
			}
		}
		int tt=0;
		for( rint i=1; i <= 3; ++i )	
			if( p[i] > n/2 )	tt = i;
		if( tt )	deal(tt);
		printf("%d\n", ans );
	}
}
