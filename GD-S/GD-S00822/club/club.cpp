#include<bits/stdc++.h>

using namespace std ;

int t ;

int a[100005][5] ;

long long ans ; 
int  n ;

void dfs(int x , int cnt1 , int cnt2 , int cnt3 , long long sum){
	if(x == n + 1 && cnt1 <= n/2 && cnt2 <= n/2 && cnt3 <= n/2 ){
		ans = max( ans , sum ) ;
		return ;
	}
	if(cnt1 == n/2){
		dfs(x + 1 , cnt1 , cnt2 + 1 , cnt3 , sum + a[x][2]) ;
		dfs(x + 1 , cnt1 , cnt2 , cnt3 + 1  , sum + a[x][3]) ;
	}else if(cnt2 == n/2){
		dfs(x + 1 , cnt1 + 1 , cnt2 , cnt3 , sum + a[x][1]) ;
		dfs(x + 1 , cnt1 , cnt2 , cnt3 + 1  , sum + a[x][3]) ;
	}else if(cnt3 == n/2){
		dfs(x + 1 , cnt1 + 1 , cnt2 , cnt3 , sum + a[x][1]) ;
		dfs(x + 1 , cnt1 , cnt2 + 1 , cnt3 , sum + a[x][2]) ;
	}else{
		dfs(x + 1 , cnt1 + 1 , cnt2 , cnt3 , sum + a[x][1]) ;
		dfs(x + 1 , cnt1 , cnt2 + 1 , cnt3 , sum + a[x][2]) ;
		dfs(x + 1 , cnt1 , cnt2 , cnt3 + 1  , sum + a[x][3]) ;
	}
}

struct node{
	int k1 , k2 , k3 ; 
	int ca ; 
}v[100005] ;

bool cmp(node x, node y){
	return x.k1 > y.k1 ;
}

bool cmp1(node x ,node y){
	return x.ca > y.ca ; 
}

signed main() {
	
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ; 
	
	scanf("%d" , &t) ;
	while(t --) {
		
		scanf("%d" , &n) ;
		int flag = 0 ; 
		if(n <= 30) {
			ans = 0 ;
			for(int  i = 1 ;  i <= n ; i ++) {
				scanf("%d%d%d" , &a[i][1] , &a[i][2] , &a[i][3]) ;
			}
			dfs( 1 , 0 , 0 , 0 , 0 ) ;
			printf("%lld",ans) ;  
		}else{
			ans = 0 ;
			for(int i = 1 ; i <= n ; i ++){
				scanf("%d%d%d",&v[i].k1, &v[i].k2 , &v[i].k3 ) ;
				if(v[i].k2 != 0 || v[i].k3 != 0){
					flag = 1 ; 
				}
			}
			if(flag == 0){
				sort(v + 1 , v + n + 1 , cmp) ;
				for(int i = 1 ; i <= n / 2 ; i ++){
					ans += v[i].k1 ;
				}
				printf( "%lld" , ans ) ;
			}else{
				int flag2 = 0 ; 
				for(int i = 1 ; i <= n ;  i ++){
					if(v[i].k3 != 0){
						flag2 = 1 ; 
					}
				}
				if(flag2 == 0){
					for(int i = 1 ; i <= n ; i ++ ){
						v[i].ca = abs(v[i].k1 - v[i].k2) ;
					}
					int cnt1 = 0 , cnt2 = 0 ;
					sort(v + 1 , v + n + 1 , cmp1 ) ;
					for(int i = 1 ; i <= n ; i ++){
						if(v[i].k1 > v[i].k2 && cnt1 < n/2){
							cnt1 ++ ; 
							ans += v[i].k1 ;
						}else if(v[i].k2 > v[i].k1 && cnt2 < n/2){
							cnt2 ++ ; 
							ans += v[i].k2 ;
						}else{
							if(cnt1 < cnt2){
								ans += v[i].k1 ;
								cnt1 ++ ;
							}else{
								ans += v[i].k2 ;
								cnt2 ++ ; 
							}
						}
					}
					printf("%lld",ans) ; 
				}
			}
		}
	}

	return 0 ;
}
