#include <bits/stdc++.h>
using namespace std;
int m, n, R;
int gride[110];
int num;
int c, r;


int main()
{
	freopen("seat.in", "r", stdin);
	
	cin >> n >> m;
	
	for (int i = 0;i < n*m;i++)
	{
		cin >> gride[i];
		if (i == 0)
		{
			R = gride[i];
		}
	}
	
	sort(gride, gride + n*m);
	
	for (int i = 0;i < n*m;i++)
	{
		if (gride[i] == R)
		{
			num = n*m - 1 - i;
			break;
		}
	}
	
	c = num/n + 1;
	r = num%n + 1;
	
	freopen("seat.out", "w", stdout);
	
	cout << c << " " << r;
	
	return 0;
}