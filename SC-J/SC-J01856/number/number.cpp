#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6 + 10 ;
string s ;
int mp[10] ;
int cnt ;
int main()
{
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	cin >> s ;
	int len = s.size() ;
	memset(mp , 0 , sizeof mp) ;
	for(int i = 0 ; i < len ; i ++)
	{
		if(s[i] >='0' && s[i] <= '9')
		{
			mp[s[i] -'0' ] ++ ;
		}
		
	}
	for(int i = 9 ; i >= 0 ;  i--)
	{
		for(int j = 1 ; j <= mp[i] ; j ++)
		{
			cout << i ;
		}
	}
	return 0 ;
}