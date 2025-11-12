#include <iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int m,n,c=0,R,ia;
	int all[0][0];
	cin>>m>>n;
	all[m][n];
	for(int i = 0; i < m ; i++)//输入 
	{
		
		for(int a = 0; a < n ; a++)
		{
			cin >> c;
			if(i == 0 && a ==0 )
			{
			
				R = c ;
			}
		
			all[i][a] = c;
			c=0;
		
		}
	}
	
	for(int i = 0;i < m ; i++)//排序 
	{
		for(int a = 0;a < n ;a++)
		{
			if(i >= 1 && a == 0)
			{
				if(all[i-1][n-1] < all[i][a])
				{
					all[i-1][n-1] = ia;
					all[i-1][n-1] = all[i][a];
					all[i][a]=ia;
				}
			}
			else if (i >= 0 && a>=1)
			{
				if(all[i][a-1] < all[i][a])
				{
					all[i][a-1] = ia;
					all[i][a-1] = all[i][a];
					all[i][a] = ia;
				}
			}
		}
	}
	for(int i = 0;i < m; i++)
	{
		for(int a = 0 ; a < n ;a++)
		{
			if(all[i][a] == R)
			cout<< i <<" "<< a;
			break; 
		}
	}
	
	return 0;
} 

/*
I'm too vegetable
*/ 
