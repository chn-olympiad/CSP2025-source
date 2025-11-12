#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n, m, c[150], d = 0, x = 1, y = 1;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> c[i];
	}
	for (int i = 2; i <= n*m; i++)
	{
		if (c[1] < c[i])
		{
			d++;
		}
	}
	x += d/n;
	if (x%2 == 0)
	{
		y = n - d%n;
	}
	else
	{
		y += d%n;
	}
	cout << x << " " << y;
	return 0;
}

