#include <bits/stdc++.h>
using namespace std ;
string s ;
int a[1145140] , cmp ;
int main()
{
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	cin >> s ;
	for (int i = 0 ; i < s.length() ; i++){
		if (s[i] >= '0' && s[i] <= '9') a[++cmp] = s[i] - '0' ;
	} 
	sort(a + 1 , a + cmp + 1) ;
	for (int i = cmp ; i >= 1 ; i--) cout << a[i] ;
	return 0 ;
} 
