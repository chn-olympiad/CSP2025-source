#include<bits/stdc++.h>
using namespace std ;
int a[1005] ;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m ;
	scanf("%d%d",&n,&m) ;
	for(int i = 1 ; i <= n * m ; i++)
		scanf("%d",&a[i]) ;
	int h = 1 ;
	int l = 1 ;
	int p = 1 ;
	for(int i = 2 ; i <= n * m ; i++)
	{
		if(a[i] > a[1])
		{
			h += p ;
			if(h > n)
			{
				l++ ;
				h = n ;
				p = -1 ;
			}
			if(h < 1)
			{
				l++ ;
				h = 1 ;
				p = 1 ;
			}
		}
	}
	printf("%d %d",l,h) ;
	return 0 ;
}
