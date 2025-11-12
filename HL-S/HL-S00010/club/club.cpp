/*#include <bits/stdc++.h>
using namespace std ;
int t ;
int n ;
int num[5] ;
long long sum ;
struct club {
	int j1 , j2 , j3 ;
	int m1 , m2 , m3 ;
	int v1 , v2 , v3 ;
} a[1000005] ;
void fun2 (int x , int y , int z , int p) {
	a[p].m1 = max (x , max (y , z)) ;
	a[p].m3 = min (x , max (y , z)) ;
	if (x == a[p].m1) {
		a[p].v1 = 1 ;
	}
	if (y == a[p].m1) {
		a[p].v1 = 2 ;
	}
	if (z == a[p].m2) {
		a[p].v1 = 3 ;
	}
	if (x == a[p].m3) {
		a[p].v1 = 1 ;
	}
	if (y == a[p].m3) {
		a[p].v1 = 2 ;
	}
	if (z == a[p].m3) {
		a[p].v1 = 3 ;
	}
	a[p].v2 = 6 - a[p].v1 - a[p].v3 ;
	if (a[p].v2 == 1) a[p].m2 = x ;
	if (a[p].v2 == 2) a[p].m2 = y ;
	if (a[p].v2 == 3) a[p].m2 = z ;
}
bool cmp (club a , club b) {
	if (a.m1 == b.m1) {
		if (a.m2 == b.m2) {
			return a.m3 > a.m3 ;
		}
		return a.m2 > b.m2 ;
	}
	return a.m1 > b.m1 ;
}
void fun () {
	sum = 0 ;
	cin >> n ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i].j1 >> a[i].j2 >> a[i].j3 ;
		fun2 (a[i].j1 , a[i].j2 , a[i].j3 , i) ;
	}
	
	sort (a + 1 , a + 1 + n , cmp) ;
	for (int i = 1 ; i <= n ; i++) {
		num[a[i].v1]++ ;
		if (num[a[i].v1] > n / 2) {
			num[a[i].v1]-- ;
			num[a[i].v2]++ ;
			sum += a[i].m2 ;
		}
		else {
			sum += a[i].m1 ;
		}
	}
	cout << sum << endl ;
}
int main () {
	cin >> t ;
	for (int i = 1 ; i <= t ; i++) {
		fun () ;
	}
	return 0 ; 
}*//*
#include <bits/stdc++.h>
using namespace std ;
int t , n ;
int a[1000005][5] ;
struct club {
	long long x ;
	long long num1 ;
} f[1000005][5] ;
long long maxnumber (int p) {
	long long num = 0 ;
	for (int i = 1 ; i <= 3 ; i++) {
		if (f[p][i].x >= n / 2) {
			continue ;
		}
		num = max (num , f[p][i].num1) ;
	}
	return num ;
}
void fun () {
	cin >> n ;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= 3 ; j++) {
			cin >> a[i][j] ;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= 3 ; j++) {
			f[i][j].num1 = a[i][j] + maxnumber (i - 1) ;
			f[i][j].x++ ;
		}
	}
	cout << max (f[n][1].num1 , max (f[n][2].num1 , f[n][3].num1)) ;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= 3 ; j++) {
			f[i][j].num1 = 0 ;
			f[i][j].x = 0 ;
		}
	}
}
int main () {
	cin >> t ;
	for (int i = 1 ; i <= t ; i++) {
		fun () ;
	}
	return 0 ; 
}*/
#include <bits/stdc++.h>
using namespace std ;
int n , t ;
long long sum ;
struct club {
	int x , y , z ;
} a[1000005] ;
bool cmp (club a , club b) {
	return a.x > b.x ;
}
void fun () {
	cin >> n ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z ;
	}
	sort (a + 1 , a + 1 + n , cmp) ;
	for (int i = 1 ; i <= n / 2 ; i++) {
		sum += a[i].x ;
	}
	cout << sum << endl ;
	sum = 0 ;
}
int main () {
	freopen ("club.in" , "r" , stdin) ;
	freopen ("club.out" , "w" , stdout) ;
	cin >> t ;
	for (int i = 1 ; i <= t ; i++) {
		fun () ;
	}
	return 0 ;
}