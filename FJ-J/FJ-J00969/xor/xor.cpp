#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum, xorr;
int xo(int x, int y)
{
	int ans=0, t=-1;
	while (y!=0 || x!=0)
	{
		t++;
		if (x%2!=y%2)
		{
			ans=ans+pow(2, t);
		}
		x>>=1;
		y>>=1;
	}
	return ans;
}
int main()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		xorr=xo(xorr, a[i]);
		if (a[i]==k || xorr==k)
		{
			sum++;
			xorr=0;
		}
	}
	cout << sum;
	return 0;
}

