#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5;
int a[N];
int n, k;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	int cntg0 = 0;
	int cntg1 = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 1)
		{
			cntg1++;
		}
		else
		{
			cntg0++;
		}
	}
	if(cntg0 == 0)
	{
		cout << n / 2;
	}
	else if (k <= 1)
	{
		if(k == 1)
		{
			int minn = min(cntg0, cntg1);
			if(minn == cntg1)
			{
				cout << minn / 2;
			}
			else
			{
				cout << minn / 2 + cntg1 - cntg0;
			}
		}	
		else
		{
			cout << cntg1 / 2 + cntg0;
		}
	}
	return 0;
}
