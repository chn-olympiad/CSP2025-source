#include <bits/stdc++.h>
using namespace std;

int total[105];
int a[15][15];

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, cnt = 1;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >> total[i];
	}
	int goal = total[1];
	sort(total+1, total+n*m+1, cmp);
	for(int j=1; j<=m; j++)
	{
		if(j%2 == 1)
		{
			for(int i=1; i<=n; i++)
			{
				a[i][j] = total[cnt];
				cnt++;
			}
		}
		else
		{
			for(int i=n; i>=1; i--)
			{
				a[i][j] = total[cnt];
				cnt++;
			}
		}
	}
	for(int r=1; r<=n; r++)
	{
		for(int c=1; c<=m; c++)
		{
			if(a[r][c] == goal)
			{
				cout << c << " " << r;
			}
		}
	}
	return 0;
}

