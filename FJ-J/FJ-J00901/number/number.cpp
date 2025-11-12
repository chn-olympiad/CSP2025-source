#include <iostream>
#include <algorithm>
using namespace std ;

bool cmp(char x , char y)
{
	return int(x) < int(y) ;
}
string s ;
const int MAXN = 1e6 ;
int a[MAXN] , cnt = 1 ;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout) ;
	cin >> s ;
	int n = s.size() ;
	for(int i = 0 ; i < n ; i++)
	{
		s[i] -= 48 ;
		if(s[i] >= 48 && s[i] <= 57)
		{
			a[cnt] = int(s[i]-48) ;
			cnt++;
		}
	}
	sort(a+1 , a+cnt+1) ;
	for(int i = 1 ; i <= cnt ; i++)
	{
		cout << a[i] ;
	}
	return 0 ;
}