#include <bits/stdc++.h>

using namespace std;

int a[500010];

int XOR(int a, int b)
{
	if (a < b)
	{
		swap(a, b);
	}
	int sum = 0;
	int t = 1;
	while (a != 0)
	{
		if (a % 2 != b % 2)
		{
			sum += t;
		}
		a /= 2;
		b /= 2;
		t *= 2;
	}
	return sum;
}

int main(void)
{
	freopen("xor.in", "w", stdin);
	freopen("xor.out", "r", stdout);
	int n = 0;
	int k = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int num = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
		{
			sum++;
			num = 0; 
		}
		else
		{
			num = XOR(num, a[i]);
			if (num == k)
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
