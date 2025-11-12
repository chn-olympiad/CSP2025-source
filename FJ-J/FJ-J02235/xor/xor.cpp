#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	int temp = 0, cnt = 1;
	for(int i=1; i<=n-1; i++)
	{
		if(i == 1)
		{
			temp = a[i];
		}
		else
		{
			temp ^= a[i];
		}
		if(temp == k)
		{
			cnt++;
			temp = 0;
		}
	}
	cout << cnt;
	return 0;
}

