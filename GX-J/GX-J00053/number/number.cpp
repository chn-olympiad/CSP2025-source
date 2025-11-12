#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std ;
string s ;
int a[100001] ;
bool cmp(int a , int b)
{
	return a > b ;
}
int main()
{
	freopen ("number.in","r",stdin) ;
	freopen ("number.out","w",stdout) ;
	cin >> s ;
	int len = s.size () , n = 1 ;
	for (int i=0 ; i<=len-1 ; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[n] = (int)s[i] ;
			n ++ ;
		}
	}
	sort (a+1 , a+n+1 , cmp) ;
	for (int i=1 ; i<=n ; i++)
	{
		cout << a[i] ;
	}
	return 0 ;
}
