#include <iostream>
#include <cstdio>

using namespace std;
int a[110];
int n , m ;
int main()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin >> n >> m ;
	{
	for(int i = 1; i <= n ; i++)
	{
		cin >> a[i] ;
		
	}
	a[i]++;
	cout << a[i] ;
	}	
	return 0;
}
