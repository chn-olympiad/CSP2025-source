#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <random>
#define N 100005
using namespace std ;
int T , n ;
int f[205][3][105][105] ;
struct student {
	int a[4] ;
}a[N];

int ans[N] ;
int res = 0 ;
bool cmp(student A , student B) {
	return A . a[1] > B . a[1] ;
}
void check() {
	int tmp = 0 ;
	for(int i = 1 ; i <= n ; i++) {
		tmp += a[i] . a[ans[i]] ;
	}
	res = max(res , tmp) ;
}
void dfs(int pos , int cnta , int cntb , int cntc) {
	if(pos > n) {
		check() ;
		return ;
	}
	if(cnta + 1 <= n / 2) {
		ans[pos] = 1 ;
		dfs(pos + 1 , cnta + 1 , cntb , cntc) ;
		ans[pos] = 0 ;
	}
	if(cntb + 1 <= n / 2) {
		ans[pos] = 2 ;
		dfs(pos + 1 , cnta , cntb + 1 , cntc) ;
		ans[pos] = 0 ;
	}
	if(cntc + 1 <= n / 2) {
		ans[pos] = 3 ;
		dfs(pos + 1 , cnta , cntb , cntc + 1) ;
		ans[pos] = 0 ;
	}
}
bool type1 , type2 ;
void solve() {
	res = 0 , type1 = type2 = true ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] . a[1] >> a[i] . a[2] >> a[i] . a[3] ;
		if(a[i] . a[2] != 0 || a[i] . a[3] != 0)type2 = false ;
		if(a[i] . a[3] != 0) {
			type1 = false ; 
		}
	}

	if(n <= 10)dfs(1 , 0 , 0 , 0) ;
	else if(type1) {
		int f[2][4][N] ;
		int A = 1 , B = 0 ;
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 1 ; j <= min(i , n / 2) ; j++) {
				f[A][1][j] = max(f[B][1][j - 1] , f[B][2][i - j]) + a[i] . a[1] ;
				f[A][2][j] = max(f[B][2][j - 1] , f[B][1][i - j]) + a[i] . a[2] ;
				res = max(f[A][1][j] , f[A][2][j]) ;
			}
			swap(A , B) ;
		}
	}
	else if(n <= 200) {
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 0 ; j <= min(i , n / 2) ; j++) {
				for(int k = 0 ; k <= min(i , n / 2) && i - j - k >= 0 && (i - j - k) <= min(i , n / 2) ; k++) {
					if(j > 0) {
						f[i][1][j][k] = max(f[i - 1][1][j - 1][k], max(f[i - 1][2][j - 1][k] , f[i - 1][3][j - 1][k])) + a[i] . a[1] ;
					}
					if(k > 0) {
						f[i][2][j][k] = max(f[i - 1][1][j][k - 1] , max(f[i - 1][2][j][k - 1] , f[i - 1][3][j][k - 1])) + a[i] . a[2] ;
					}
					if(i - j - k > 0) {
						f[i][3][j][k] = max(f[i - 1][1][j][k] , max(f[i - 1][2][j][k] , f[i - 1][3][j][k])) ;
						f[i][3][j][k] += a[i] . a[3] ;
						
					}
					res = max(max(res , f[i][1][j][k]) , max(f[i][2][j][k] , f[i][3][j][k])) ;
					
				}
			}
		}
	}
	else if(type2) {
		sort(a + 1 , a + 1 + n , cmp) ;
		for(int i = 1 ; i <= n / 2 ; i++) {
			res += a[i] . a[1] ;
		}
	} 
	else {
		res = rand() ;
	}
	

	cout << res << '\n' ;
}
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios :: sync_with_stdio(false) ;
	cin . tie(0) , cout . tie(0) ;
	
	cin >> T ;
	while(T --)solve() ;
	
	return 0 ;

}

