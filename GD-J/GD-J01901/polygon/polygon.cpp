#include <bits/stdc++.h>
using namespace std;
int maxn;
const int p = 998244353;
long long n,a[5005];
long long num,ans;
long long check(int x,int y)
{
	long long s = 0;
	if (x-y==3)
	{
		if (a[y]+a[y+1]+a[y+2]>maxn) return 1;
		return 0;
	}
	for (int i = 3;i <= x;i++)
	{
		s += check(i,x-1);
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if (n==3)
	{
		if (a[1]+a[2]+a[3]>a[3]*2)
		{
			ans = 1;
		}
	}
	else
	{
		for (int i = n;i >= 1;i--)
		{
			maxn = 2*a[i];
			cout << maxn << endl;
			for (int j = 1;j <= a[i];j++)
			{
				cout << num << " ";
				num = check(i,j);
				cout << num << endl;
				ans += num;
			}
		}
	}
	
	cout << ans%p;
	return 0;
}
