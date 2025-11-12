#include<iostream>
using namespace std;
int n, m, x = 1, t, xiaor, c, r;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> xiaor;
	for(int i = 2; i <= n * m; i++)
	{
		cin >> t;
		if(t > xiaor) x++;	
	} 
	c = x / n;
	r = x % n;
	if(r != 0) c++;
	else r = n;
	if(!(c & 1)) r = 1 + n - r;
	cout << c << ' ' << r;
	return 0;
}

