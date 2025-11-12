#include<iostream>

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n = 0 , m = 0 ; 
	cin >> n >> m ;
	int a[n*m] = {} ;

	int my_seat = 1 ;
	
	for(int i = 0 ; i < n*m ; i++ )
	{
		cin >> a[i] ;
		if(i!=0)
		{
				if( a[i] > a[0] )
			{
				my_seat++ ;
			}
		}
	}
	
	int my_m = my_seat / n ;
	if(my_seat % n == 0)
	{
		my_m-- ;
	}
	my_m++ ;
	

	
	int my_n =  my_seat % n ;
	if(my_seat % n == 0 )
	{
		my_n = n ;
	}
	
	if(my_m % 2 == 0)
	{
		my_n = n + 1 - my_n ;
	}
	
	cout << my_m << " " << my_n ;
	return 0;
}
