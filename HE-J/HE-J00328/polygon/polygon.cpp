#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int n,cnt,oi;
int a[N],f[N][2];

bool check(int a,int b)
{
	return a > b * 2;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++)
	{
		cin>>a[i];
		oi += a[i];
	}
	sort(a+1,a+n+1);
	if (n <= 3)
	{
		if (n < 3)
		{
			cout<<0;
			return 0;
		}
		if (check(a[1] + a[2] + a[3],a[3]))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	/*for (int i = n;a[i] >= (oi / n);i--)
	{
		long long sum = 0,ans = 0;
		for (int j = 1;j < i;j++)
		{
			sum += a[j];
			if (sum >= i)
			{
				ans = j;
			}
		}
	}*/
	return 0;
}
