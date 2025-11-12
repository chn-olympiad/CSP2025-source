#include <iostream>
using namespace std;

int a[500005]; 

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum1 = 0;
	bool flag1 = true;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1) flag1 = false;
		if(a[i] == 1) sum1++;
	}
	if(k == 0 && flag1 == true)
	{
		cout << n / 2;
		return 0;
	}
	else if(k == 0)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 0)
			{
				cnt++;
			}
			else
			{
				if(i < n && a[i + 1] == 1)
				{
					cnt++;
					i++;
				}
			}
		}
		cout << cnt;
		return 0;
	}
	else if(k == 1)
	{
		cout << sum1;
	}
	return 0;
}



