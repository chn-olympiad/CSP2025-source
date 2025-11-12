#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int MAXN = 1e5 + 10 ;
int t ;
struct node{
	int a1 , a2 , a3 , max ;
	bool vis ;
}a[MAXN];
bool cmp(node a , node b){
	return a.a1 > b.a1 ;
}
bool cmp1(node a , node b){
	return a.a2 > b.a2 ;
}
bool cmp2(node a , node b){
	return a.a3 > b.a3 ;
}
int main(){
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	scanf("%d" , &t);
	while(t--){
		int n ;
		scanf("%d" , &n);
		int book[10] ;
		memset(book , 0 , sizeof(book)) ;
		int cnt2 = 0 , cnt3 = 0 ;
		for (int i = 1 ; i <= n ;++i){
			scanf("%d%d%d" , &a[i].a1 , &a[i].a2 , &a[i].a3) ;
			a[i].vis = false ;
			a[i].max = max(max(a[i].a1 , a[i].a2) , a[i].a3) ;
			if (a[i].a2 == 0){
				++cnt2 ;
			}	
			if (a[i].a3 == 0){
				++cnt3 ;
			}
		}
		if (cnt2 == cnt3 && cnt2 == n){
			sort(a + 1 , a + 1 + n , cmp) ;
			int List = n / 2 , MAX_ans = 0;
			for (int i = 1 ; i <= List ; ++i){
				MAX_ans += a[i].a1 ;
			}
			printf("%d\n" , MAX_ans) ;
			continue ;
		}
		int ans1 = 0 , ans2 = 0 ;
		int List = n / 2 ;
		for (int i = 1 ; i <= n;  ++i){
			if (a[i].max == a[i].a1){
				if (book[1] < List){
					++book[1] ;
					ans1 += a[i].a1 ;
					continue ;
				}else{
					int max_nxt = 0 ;
					max_nxt = max(a[i].a2 , a[i].a3) ;
					if (max_nxt == a[i].a2){
						if (book[2] < List){
							++book[2] ;
							ans1 += a[i].a2 ;
							continue ;
						}
					}
					if (max_nxt == a[i].a3){
						if (book[3] < List){
							++book[3] ;
							ans1 += a[i].a3 ;
							continue ;
						}
					}
				}
			}
			if (a[i].max == a[i].a2){
				if (book[2] < List){
					++book[2] ;
					ans1 += a[i].a2 ;
					continue ;
				}else{
					int max_nxt = 0 ;
					max_nxt = max(a[i].a1 , a[i].a3) ;
					if (max_nxt == a[i].a1){
						if (book[1] < List){
							++book[1] ;
							ans1 += a[i].a1 ;
							continue ;
						}
					}
					if (max_nxt == a[i].a3){
						if (book[3] < List){
							++book[3] ;
							ans1 += a[i].a3 ;
							continue ;
						}
					}
				}
			}
			if (a[i].max == a[i].a3){
				if (book[3] < List){
					++book[3] ;
					ans1 += a[i].a3 ;
					continue ;
				}else{
					int max_nxt = 0 ;
					max_nxt = max(a[i].a1 , a[i].a2) ;
					if (max_nxt == a[i].a1){
						if (book[1] < List){
							++book[1] ;
							ans1 += a[i].a1 ;
							continue ;
						}
					}
					if (max_nxt == a[i].a2){
						if (book[2] < List){
							++book[2] ;
							ans1 += a[i].a2 ;
							continue ;
						}
					}
				}
			}
		}
		sort(a + 1 , a + 1 + n , cmp) ;
		int list = n / 2 ;
		int cnt = 0 ;
		for (int i = 1 ; i <= n ; ++i){
			if (!a[i].vis){
				ans2 += a[i].a1 ;
				a[i].vis = true ;
				++cnt ;
			}
			if (cnt == list){
				break ;
			}
		}
		cnt = 0 ;
		sort(a + 1 , a + 1 + n , cmp1) ;
		for (int i = 1 ; i <= n ;++i){
			if (!a[i].vis){
				ans2 += a[i].a2 ;
				a[i].vis = true ;
				++cnt ;
			}
			if (cnt == list){
				break ;
			}
		}
		cnt = 0 ;
		sort(a + 1 , a + 1 + n , cmp2) ;
		for (int i = 1 ; i <= n ;++i){
			if (!a[i].vis){
				ans2 += a[i].a3 ;
				a[i].vis = true ;
				++cnt ;
			}
			if (cnt == list){
				break ;
			}
		}
		printf("%d\n" ,max(ans1 , ans2)) ;
	}
	return 0 ;
}
