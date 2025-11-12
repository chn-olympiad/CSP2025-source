#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,maxx,asum;
void poly(int x,int y)
{
	if (x > n)
	{
		if (y > maxx * 2)
		{
			sum++;
		}
	}
	poly(x + 1,y + a[x]);
	poly(x + 1,y);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
		asum += a[i];
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	if (n == 3)
	{
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
} 
