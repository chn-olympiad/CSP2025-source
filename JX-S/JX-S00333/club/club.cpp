#include<bits/stdc++.h>
using namespace std ;
int t , n , c1 , c2 , c3 , k ; 
struct stu{
	int a1 , a2 , a3 ;
}a[100005] ;
int dfs(int x){
	if(x == 0) return 0 ;
	int res = -1 ;

	if(c1 + 1 <= k){
		c1++ ;
		int temp = dfs(x - 1) ;
		if(res < temp + a[x].a1){
			res = temp + a[x].a1 ;
		}
		c1-- ;
	}
	
	if(c2 + 1 <= k){
		c2++ ;
		int temp = dfs(x - 1) ;
		if(res < temp + a[x].a2){
			res = temp + a[x].a2 ;
		}
		c2-- ;
	}
	
	if(c3 + 1 <= k){
		c3++ ;
		int temp = dfs(x - 1) ;
		if(res < temp + a[x].a3){
			res = temp + a[x].a3 ;
		}
		c3-- ;
	}
	return res ;
}
bool cmp(stu x , stu y){
	return x.a1 > y.a1 ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k = n >> 1 ;
		c1 = c2 = c3 = 0 ;
		bool A = 1 , B = 1 ;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d%d%d",&a[i].a1 , &a[i].a2 , &a[i].a3);
			if(a[i].a2 != 0 || a[i].a3 != 0) A = 0 ;
			if(a[i].a3 != 0) B = 0 ;
		}
		
		if(A){
			sort(a + 1 , a + n + 1 , cmp) ;
			int ans = 0 ;
			for(int i = 1 ; i <= k ; i++) ans += a[i].a1 ;
			printf("%d\n",ans) ;
		}
		else if(B){
			sort(a + 1 , a + n + 1 , cmp) ;
			int ans = 0 ;
			for(int i = 0 ; i <= n ; i++){
				if(c2 <= k && a[i].a2 > a[i].a1){
					ans += a[i].a2 ;
					c2++ ;
				}
				else ans += a[i].a1 ;
			}
			printf("%d\n",ans) ;
		}
		else printf("%d\n",dfs(n));
	}
	
	return 0 ;
}
