#include <bits/stdc++.h>

using namespace std ;

inline int read()
{
	int x = 0 , f = 1 ; char ch = 0 ;
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1 ; ch = getchar() ;}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + (ch ^ 48) ; ch = getchar() ;}
	return x * f ;
}

const int N = 2e6 + 10 ;

int a[N] , b[N] , c[N] , n , sa[N] , sb[N] , sc[N] , cnt1 , cnt2 , cnt3 , ca[N] , num[N] ;

inline bool cmp(int x , int y)
{
	return x > y ;
}

signed main()
{
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	int t = read() ;
	while(t -- )
	{
		n = read() ;
		int ans = 0 ;
		cnt1 = cnt2 = cnt3 = 0;
		for(int i = 1 ; i <= n ; i ++ ) a[i] = read() , b[i] = read() , c[i] = read() ;
		for(int i = 1 ; i <= n ; i ++ )
		{
			if(a[i] >= b[i] && a[i] >= c[i])
			{
				sa[++cnt1] = i , ans += a[i] ;
				if(b[i] > c[i]) ca[i] = a[i] - b[i] ;
				else ca[i] = a[i] - c[i] ;
			}
			else if(b[i] >= a[i] && b[i] >= c[i])
			{
				sb[++cnt2] = i , ans += b[i] ;
				if(a[i] > c[i]) ca[i] = b[i] - a[i] ;
				else ca[i] = b[i] - c[i] ;
			}
			else 
			{
				sc[++cnt3] = i , ans += c[i] ;
				if(b[i] > a[i]) ca[i] = c[i] - b[i] ;
				else ca[i] = c[i] - a[i] ;
			}
		}
		if(cnt1 > n / 2)
		{
			for(int i = 1 ; i <= cnt1 ; i ++ ) num[i] = ca[sa[i]] ;
			sort(num + 1 , num + 1 + cnt1) ;
			for(int i = 1 ; i <= cnt1 - n / 2 ; i ++ ) ans -= num[i] ;
		}
		else if(cnt2 > n / 2)
		{
			for(int i = 1 ; i <= cnt2 ; i ++ ) num[i] = ca[sb[i]] ;
			sort(num + 1 , num + 1 + cnt2) ;
			for(int i = 1 ; i <= cnt2 - n / 2 ; i ++ ) ans -= num[i] ;
		}
		else if(cnt3 > n / 2)
		{
			for(int i = 1 ; i <= cnt3 ; i ++ ) num[i] = ca[sc[i]] ;
			sort(num + 1 , num + 1 + cnt3) ;
			for(int i = 1 ; i <= cnt3 - n / 2 ; i ++ ) ans -= num[i] ;
		}
		printf("%d\n" , ans) ;
	}
	return 0 ;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/