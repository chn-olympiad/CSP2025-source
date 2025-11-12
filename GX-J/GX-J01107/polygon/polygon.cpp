#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n ;
int a , b , c ;
int  ans = 0 ;
int main()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin >> n ;
	cin >> a >> b >> c ;
	if((a + b + c)%998||(a + b + c)%244||(a + b + c)%353)
	ans ++ ;
	cout << ans ;
	return 0;
}
