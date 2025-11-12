#include <bits/stdc++.h>
using namespace std ;
int m , n , a[114] , k , p , pos , ansn , ansm ;
bool cmp(int a , int b)
{
	return a > b ;
}
int main()
{
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	cin >> n >> m ;
	p = n * m ;
	for (int i = 1 ; i <= p ; i++) cin >> a[i] ;
	k = a[1] ;
	sort(a + 1 , a + p + 1 , cmp) ;
	for (int i = 1 ; i <= p ; i++) if (a[i] == k) pos = i ;
	if (pos % n != 0) ansm = (pos / n) + 1 ;
	else ansm = pos / n ;
	if (pos % n == 0 && ansm % 2 == 0) ansn = 1 ;
	else if (pos % n == 0 && ansm % 2 == 1) ansn = n ;
	else if (ansm % 2 == 0) ansn = n - pos % n + 1;
	else  ansn = pos % n ;
	cout << ansm << " " << ansn ; 
	return 0 ;
}

