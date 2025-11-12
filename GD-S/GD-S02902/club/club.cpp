#include <bits/stdc++.h>
using namespace std ;
int n , t ;
struct P
{
	int a , b , c , k , q ;
}a[114514] ;
int r1[114514] , r2[114514] , r3[114514] ;
bool cmp(int a , int b)
{
	return a > b ;
}
int main()
{
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	cin >> t ;
	while(t--) {
		memset(r1 , 0 , sizeof(r1)) ;
		memset(r2 , 0 , sizeof(r2)) ;
		memset(r3 , 0 , sizeof(r3)) ;
		int cnt1 , cnt2 , cnt3 , tmp1 , tmp2 , tmp3 , sum , ans ;
		bool f1 , f2 , f3 ;
		cnt1 = cnt2 = cnt3 = sum = ans = 0 ;
		tmp1 = tmp2 = tmp3 = 1 ;
		f1 = f2 = f3 = 1 ;
		cin >> n ;
		for (int i = 1 ; i <= n ; i++){
			cin >> a[i].a >> a[i].b >> a[i].c ;
			int m = max(a[i].a , max(a[i].b , a[i].c)) ;
			if (m == a[i].a) a[i].k = 1 , r1[++cnt1] = m;
			else if (m == a[i].b) a[i].k = 2 , r2[++cnt2] = m ;
			else if (m == a[i].c) a[i].k = 3 , r3[++cnt3] = m;
		} 
		if (n == 2) {
			int max1 = max(a[1].a + a[2].b , a[1].a + a[2].c) ;
			int max2 = max(a[1].b + a[2].a , a[1].b + a[2].c) ;
			int max3 = max(a[1].c + a[2].a , a[1].c + a[2].b) ;
			ans = max(max1 , max(max2 , max3)) ;
			cout << ans ;
			continue ;
		}
		sort(r1 + 1 , r1 + cnt1 + 1 , cmp) ;
		sort(r2 + 1 , r2 + cnt2 + 1 , cmp) ;
		sort(r3 + 1 , r3 + cnt3 + 1 , cmp) ;
		while(sum < n){
			if (!f1) tmp1 = 0 ; 
			if (!f2) tmp2 = 0 ; 
			if (!f3) tmp3 = 0 ; 
			int m = max(r1[tmp1] , max(r2[tmp2] , r3[tmp3])) ;
			ans += m ;
			if (m == r1[tmp1]) tmp1++ ;
			else if (m == r2[tmp2]) tmp2++ ;
			else if (m == r3[tmp3]) tmp3++ ;
			if (tmp1 > n / 2) f1 = 0 ;
			else if (tmp2 > n / 2) f2 = 0 ;
			else if (tmp3 > n / 2) f3 = 0 ;
			sum++ ;
		}
		cout << ans << endl ;
	} 
	return 0 ;
}
