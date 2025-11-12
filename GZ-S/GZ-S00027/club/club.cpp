// GZ-S00027 贵阳中天中学 何棂宸
// 不知道。去看T2T3部分分去了。 
#include <bits/stdc++.h>
using namespace std ;

const int maxn = 1e5+5 ;
int t , n , c[5] ;

struct stu{
	int id , num , cl ;
}a[maxn];

bool cmp ( stu a , stu b ){
	return a.num > b.num ;
}

int main(){
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	cin >> t ;
	while ( t-- ){
		cin >> n ;
		int ans = 0 ;
		bool sel[maxn] = {0} ;
		for ( int i = 1 ; i <= 3 ; i++ ) c[i] = 0 ;
		for ( int i = 1 ; i <= n ; i++ ){
			cin >> a[3*i-2].num >> a[3*i-1].num >> a[3*i].num ;
			a[3*i-2].id = i ;
			a[3*i-2].cl = 1 ;
			a[3*i-1].id = i ;
			a[3*i-1].cl = 2 ;
			a[3*i].id = i ;
			a[3*i].cl = 3 ;
		}
		sort(a+1,a+1+3*n,cmp) ;
		for ( int i = 1 ; i <= 3*n ; i++ ){
			if ( c[a[i].cl] < n/2 && !sel[a[i].id] ){
				ans += a[i].num ;
				c[a[i].cl]++ ;
				sel[a[i].id] = 1 ;
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}

