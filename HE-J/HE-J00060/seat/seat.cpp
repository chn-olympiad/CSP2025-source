#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, x, y = 0;
	int a[110];
	cin >> n >> m;
	for(int i = 1;i<= n * m;i++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(;y <= n * m;y++)
		if(a[y] == x)
			break;
	if(y % n == 0 && y / n != 0)
	{
		cout << y / n << ' ' << n;
	}
	else if(y % n == 0 && y / n == 0)
	{
		cout<<y / n << ' ' << 1;
	}
	else if(y / n % 2 == 0)
	{
		cout << y / n + 1 << ' ' << y % n;
	}
	else if(y / n % 2)
	{
		cout << y / n + 1<< ' ' << n - (y % n) + 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
