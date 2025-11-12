#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c = 1, r = 1;
	cin >> n >> m;
	int score[m * n], cnt = m * n - 1;
	for (int i = 0; i < m * n; i++)
	{
		cin >> score[i];
	}
	const int xiaoR = score[0];
	sort(score + 0, score + m * n);
	for (int i = 1; i <= m; i++)
	{
		c = i;
		if(i % 2 == 0)
		{
			for (int j = n; j >= 1; j--)
			{
				r = j;
				if(score[cnt] == xiaoR)
				{
					cout << c << " " << r;
				}
				cnt--;
			}
		}
		else
		{
			for (int j = 1; j <= n; j++)
			{
				r = j;
				if(score[cnt] == xiaoR)
				{
					cout << c << " " << r;
				}
				cnt--;
			}
		}
	}
	return 0;
}