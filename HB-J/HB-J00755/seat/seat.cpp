#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	breopen("seat.in" , "r" , stdin);
	breopen("seat.out" , "w" , stdout);
	int n , m ;
	cin >> n >> m ;
	int a[105];
	for(int i=0;i<n*m;i++)
	{
		cin >> a[i];
	}
	int c , r , cut=1;
	int s = a[0];
	for(int i=0;i<n*m;i++)
	{
		if(a[i] > s)
		{
			cut++;
		}
	}
    int o;
	if(cut <= n)
	{
		r = 1;
		c = cut;
		cout << r << " " << c;
		return 0;
	}
	else
	{
		r = cut / n + 1;
        o = cut / n;
	}
	if(r % 2 != 0)
	{
		c = cut - o * m;
	}
	else
	{
		c = m - (cut - o * m)+1;
	}
	cout << r << " "  << c;
	return 0;
}
