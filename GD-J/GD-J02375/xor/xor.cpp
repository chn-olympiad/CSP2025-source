#include<iostream>
using namespace std;
const int N = 5e5 + 1;
int n, k, a[N], ans;
bool pd;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 0) pd = 1;
	}
	if(!pd)
	{
		cout << n / 2;
	}
	else
	{
		if(k == 1) 
		{
			for(int i = 1; i <= n; i++)
				if(a[i] == 1) ans++;
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 0) ans++;
				else if(a[i + 1] == 1)
				{
					ans++;
					i++;
				}
			}	
		}
		cout << ans;
	}
	return 0;
}
