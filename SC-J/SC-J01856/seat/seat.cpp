#include<bits/stdc++.h>
using namespace std ;
struct node
{
	int x , sum ;
}a[200] ;
int n , m , cnt ; 
bool cmp(node b , node c)
{
	return b.sum > c.sum ;
}
int main()
{
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	cin >> n >> m ;
	//cout << n * m ;
	for(int i = 1 ; i <= n * m ; i ++)
	{	
			cin >> a[i].sum ;
			a[i].x = i ;
	}
	sort(a + 1 , a + 1 + n * m , cmp) ;
	int t ;
	for(int i = 1 ; i <= n * m ; i ++)
	{
		if(a[i].x == 1 )
		{
			t = i ;
			break ;
		}
	}
	if(t % n == 0)
	{
		cout << t / n << ' ' ;
		if((t / n) % 2 == 0)
		{
			cout << 1 ;
		}
		else cout << n ;
	}
	else
	{
		int d = t / n + 1 ;
		cout << d << ' ' ;
		int dt = d * n - t ;
		if(d % 2 == 1)
		{
			cout << n - dt ;
		}
		else cout << 1 + dt ;
	}
	return 0 ;
}
/*
4 5
95 100 99 98 97 96 94 93 92 91 90 89 88 87 86 85 84 83 82 81
*/