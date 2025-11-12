#include<iostream>
using namespace std;

const int MAXN = 5e5 + 10;

int n, k, a[MAXN], t[2];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		t[a[i]]++;
	}
	
	if (t[0] = 0)
	{
		cout << t[1] / 2;
	}
	else
	{
		if (k == 0)
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 1 && a[i + 1] == 1)
				{
					ans++;
					i++;
				}
			}
			cout << ans + t[0];
		}
		else
		{
			cout << t[1];
		}
	}
	
	return 0;
}
