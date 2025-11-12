#include <bits/stdc++.h>
using namespace std;
int n,a[100000],b[10000];
long long s = 1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		s %= 998244353;
		s *= n;
	}
	cout << s;
	return 0;
}
