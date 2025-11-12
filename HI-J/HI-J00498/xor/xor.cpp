#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w".stdout);
	long long n,x,l = 1,r = 1,a[100005],num = 0,sum = 0,ans = 0,of = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	while(r == n)
	{
		if (r == 1 && a[r] == x)
		{
			num++;
		}
		if (r > 1)
		{
			ans = a[l];
			for (int i = l + 1;i <= r;i++)
			{
				of = ans |+ a[i];
			}
			if (of == x)
			{
				num++;
			}
		}
		r++;
	}
	sum += num;
	of = 0;
	num = 0;
	while(l == n)
	{
		if (l > 1)
		{
			ans = a[r];
			for (int i = l;i <= r;i++)
			{
				of = ans |+ a[i];
			}
			if (of == x)
			{
				num++;
			}
		}
		l++;
	}
	sum += num; 
	cout << sum;
}
