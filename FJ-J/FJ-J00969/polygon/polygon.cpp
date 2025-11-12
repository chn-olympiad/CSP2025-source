#include <bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n, a[5005], sum, x, y;
int main()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (long long i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for (long long i=3; i<=n; i++)
	{
		x=1;
		for (long long j=n; j>=n-i+1; j--)
		{
			x=x*j/(n-j+1)%Mod;
		}
		sum=(sum+x)%Mod;
	}
	cout << sum;
	return 0;
}

