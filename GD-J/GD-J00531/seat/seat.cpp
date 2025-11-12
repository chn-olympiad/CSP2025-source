#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;

struct Node
{
	int id , num ;
}score[105] ;
bool cmp (Node x , Node y)
{
	return x.num > y.num ;
}
int main ()
{
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
//3 3
//94 100 99 98 97 96 95 93 92
	int n , m ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n * m ; i++)
	{
		cin >> score[i].num ;
		score[i].id = i ;
	}
	sort(score + 1 , score + n * m + 1 , cmp) ;
	int pos = -1 ;
	for (int i = 1 ; i <= n * m ; i++)
	{
		if (score[i].id == 1)
		{
			pos = i ;
		} 
	}
	int c = ceil(pos * 1.0 / n) , r = 0 ;
	if (c % 2 != 0)
	{
		r = pos % n ;
		if (pos % n == 0)
		{
			r = n ;
		}
	}
	else
	{
		r = n - pos % n + 1 ;
		if (pos % n == 0) 
		{
			r = 1 ;
		}
	} 
	cout << c << " " << r ;
	return 0 ;
}
