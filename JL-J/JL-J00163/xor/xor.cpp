#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(k==0)
	{
		//if(n == 1)
		//{
		//	cout << 0;
		//}
		//else if(n == 2)
		//{
		//	cout << 1;
		//}
		//cout << n/2;
		for(int i=1;i<=n;i++)
		{
			if(a[i] == 0)
			{
				ans++;
			}
			else if(a[i] +a[i + 1]==2)
			{
				ans++;
				i++;
			}
		}
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i] == 1)
			{
				ans++;
			}
			//if(a[i] +a[i + 1]==1)
			//{
				//ans++;
				//i++;
			//}
			else if(a[i]+a[i + 1] + a[i + 2] == 3)
			{
				ans++;
				i+=2;
			}
		}
	}
	cout << ans;
	return 0;
}
