#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	int n ;
	cin >> n ;
	int a[n] = {} ;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> a[i] ;
	}
	
	int last_out = 0 ;
	int use_a[n] ;
	if(n==3)
	{
		if(a[0]+a[1]+a[2] > 2*(max( max( a[0],a[1]),a[2] ) ) )
		{
			last_out++ ;
		}
	}
	if( 3 < n && n <= 10)
	{
		for(int i = 0 ; i < n*n ; i++ )
		{
			
		}
	}
	cout << last_out ;
	return 0;
}
