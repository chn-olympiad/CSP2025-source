#include <bits/stdc++.h>
using namespace std;
int a[1000005], n, sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int maxn = -1;
	if (n < 3)
	{
		cout << "0";
		return 0;
	}
	else if (n == 3)
	{
		for(int i = 1;i <= n;i++)
		{
			sum += a[i];
			maxn = max(maxn, a[i]); 
		}
		if (sum > maxn*2)
		{
			cout << "1";
			return 0;
		}
		else
		{
			cout << "0";
		}
	}
    return 0;	
} 
