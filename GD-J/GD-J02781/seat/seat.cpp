#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],p,num,r,c;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
		if (i == 1)
			p = a[i];
	}
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == p)
			num = i;
	}
	//cout << num << " ";
	if (num % n == 0)
		r = num / n;
	else
		r = num / n + 1;
	if (r % 2 == 1)
	{
		int g = (r - 1) * n + 1;
		c = num - g + 1;
	}
	else
	{
		int g = r * n;
		c = g - num + 1;
	}
	cout << r << " " << c;
}
