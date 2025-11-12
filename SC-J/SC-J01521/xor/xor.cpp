#include <bits/stdc++.h>
using namespace std;
int n, a[5003], all;
long long num;
int dd[5000];

void for_(int max, int min, int date, int want)
{
	if (want == 0)
	{
		for (int i = 0;dd[i] != -1;i++)
		{
			all += a[dd[i]];
		}
		if (all > 2*a[dd[0]])
		{
			all++;
		}
		return;
	}
	for (int i = min;i < max;i++)
	{
		dd[5000 - want] = i;
		for_(n - date, date + 1, date, want - 1);
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 0;i < 5000;i++)
	{
		dd[i] = -1;
	}
	
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (int j = 0;j < n;j++)
	{
		for_(n, 0, 0, j);
	}
	
	
	
	freopen("polygon.out", "w", stdout);
	
	cout << all;
	
	return 0;
}