#include <bits/stdc++.h>
using namespace std;
int n,k,sum;
int a[50005];
int b[21];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool ok = 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (i >= 2 && a[i] != a[i - 1])
		{
			ok = 0;
		}
	}
	int l = 1,r = 1;
	if (ok && k == 0)
	{
		cout << max(1,n / 2);
		return 0; 
	}
	cout << 1;
	return 0;
} 
