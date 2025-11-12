#include <bits/stdc++.h>
using namespace std;

int a[500007], k;

struct Miao
{
	int x, y;
	bool operator<(const Miao m)const
	{
		return y < m.y;
	}
}b[500007];

bool check(int x, int y)
{
	int num = 0;
	for (int i = x; i <= y; i++)
	{
		num ^= a[i];
	}
	return num == k;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n <= 10000)
	{
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (check(i, j))
				{
					b[cur].x = i, b[cur].y = j;
					cur++;
				}
			}
		}
		sort(b, b + cur);
		int t = -1, cnt = 0;
		for (int i = 0; i < cur; i++)
		{
			if (b[i].x > t)
			{
				cnt++;
				t = b[i].y;
			}
		}
		cout << cnt;
		return 0;
	}
	else if (k == 0)
	{
		bool flag1 = true;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 1)
			{
				flag1 = false;
			}
		}
		if (flag1)
		{
			cout << n / 2;
			return 0;
		}
		return 0;
	}
	return 0;
}
