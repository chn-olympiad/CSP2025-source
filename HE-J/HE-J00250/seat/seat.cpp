#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m,f1 = 0,f2 = 0,cnt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if(a[i] >= a[1])
		{
			cnt++;
		}
	}
	int x = cnt/n, y = cnt%n;
	if(y != 0) 
	{
		f1 = x + 1;
		if(f1 % 2 == 0) f2 = n - y + 1;
		else f2 = y;
	}
	else 
	{
		f1 = x;
		if(f1 % 2 == 0) f2 = 1;
		else f2 = n;
	}
	cout << f1 << " " << f2 << endl;
	return 0;
}
