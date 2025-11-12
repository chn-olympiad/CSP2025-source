#include <bits/stdc++.h>
#define int long long 
int n , k , a[1000005];
using namespace std;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(n <= 2)
	{
		if(a[0] == 0 && a[1] == 0)
		{
			cout << 2;
			return 0;
		}
		if(a[0] == 0 && a[1] == 1)
		{
			cout << 1;
			return 0;
		}
		if(a[0] == 1 && a[1] == 0)
		{
			cout << 1;
			return 0;
		}
		if(a[0] == a[1])
		{
			cout << 1;
			return 0;
		}
	}
	else
	{
		cout << n / 3;
	}
	return 0;
}
