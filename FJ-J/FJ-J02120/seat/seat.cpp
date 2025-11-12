#include <iostream>
#include <algorithm>
using namespace std;

int a[110];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int ans = a[1];
	
	for (int i = 1; i <= n * m - 1; i++)
	{
		for (int j = i + 1; j <= n * m; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
	
	int now = 0;
	for (int j = 1; j <= m; j++)
	{
		if (j % 2 == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				now++;
				if (a[now] == ans)
				{
					cout << j << " " << i << endl;
					break;
				}
			}
		}
		else
		{
			for (int i = n; i >= 1; i--)
			{
				now++;
				if (a[now] == ans)
				{
					cout << j << " " << i << endl;
					break;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
