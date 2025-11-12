#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
int a[10005],b[10000005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	if (n == 3)
	{
		int y = max(a[1],a[2]);
		y = max(y,a[3]);
		if (2 * (a[1] + a[2]) <= y || 2 * (a[1] + a[3]) <= y || 2 * (a[2] + a[3]) <= y)
		{
			cout << 0;
			return 0;
		} 
		else
		{
			cout << 1;
			return 0;
		}
	} 
	else
	{
		
	}
	return 0;
} 
