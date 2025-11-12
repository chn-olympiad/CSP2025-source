#include<bits/stdc++.h>
using namespace std;
namespace hqk{
	int t, n, s, c[100005], a[100005][5], b[100005][5];
	priority_queue<pair<int, int> > o[5];
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> t;
		while (t--)
		{
			cin >> n;
			s = 0;
			for (int i = 1; i <= 3; i++)
			{
				while (o[i].size())
				{
					o[i].pop();
				}
			}
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i][1] >> a[i][2] >> a[i][3];
				c[i] = 1;
				b[i][1] = 1;
				b[i][2] = 2;
				b[i][3] = 3;
				for (int j = 1; j <= 3; j++)
				{
					for (int k = 1; k <= 2; k++)
					{
						if (a[i][b[i][k]] < a[i][b[i][k + 1]])
						{
							swap(b[i][k], b[i][k + 1]);
						}
					}
				}
				o[b[i][c[i]]].push({a[i][b[i][c[i] + 1]] - a[i][b[i][c[i]]], i});
				s = s + a[i][b[i][c[i]]];
				int x = i;
				while (o[b[x][c[x]]].size() > n / 2)
				{
					x = o[b[x][c[x]]].top().second;
					s = s + o[b[x][c[x]]].top().first;
					o[b[x][c[x]]].pop();
					c[x]++;
					o[b[x][c[x]]].push({a[x][b[x][c[x] + 1]] - a[x][b[x][c[x]]], x});
				}
			}
			cout << s << "\n";
		}
		return 0;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	return hqk::main();
}
//0.2s 7M
//1s 512M
