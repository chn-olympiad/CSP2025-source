#include <bits/stdc++.h>
using namespace std;
int k,n;
int a[100000],sum,a1,a2;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] == 1)
		{
			a1++;
		}
	}
	if (k == 1)
	{
		cout << a1;
		return 0;
	}
	if (k == 0)
	{
		cout << n -a1;
		return 0;
	}
	cout << 0;
	return 0;
}
