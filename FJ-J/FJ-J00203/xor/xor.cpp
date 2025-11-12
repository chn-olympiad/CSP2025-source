#include<iostream>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n = 0 , k = 0 ;
	cin >> n >> k ;
	int a[n] = {} ;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> a[i] ;
	}
	
	int XB[n] = {} ;
	int last_number = 0 ;
	
	int L = 0 , R = 0 ;
	for(int i = 0 ; i < n ; i++ )
	{
		R = L ;
		if( XB[L] == 0 )
		{
			for(int j = L ; j < n ; j++ )
			{
				int help_a = 0 ;
				
				if( XB[R] == 0 && XB[L] == 0 )
				{
					for(int ii = L ; ii <= R ; ii++ )
					{
						help_a = help_a xor a[ii] ;
					}
					if(help_a == k)
					{
						last_number++ ;
						for(int ii = L ; ii <= R ; ii++ )
						{
							XB[ii] = 1 ;
						}
					}
				
				}
				R++ ;
			}
		}
		L++ ;
	}
	cout << last_number ;
	return 0 ;

}
