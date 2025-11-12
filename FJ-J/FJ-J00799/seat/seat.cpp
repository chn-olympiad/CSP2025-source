#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int a[105] = {}, cnt = 1, b[11][11] = {};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, R;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int k=1; k<=m; k++)
	{
		if(k%2)
		{
			for(int j=1; j<=n; j++)
			{
				b[j][k] = a[cnt];
				cnt++;
			}
		}
		else
		{
			for(int j=n; j>=1; j--)
			{
				b[j][k] = a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(b[i][j] == R)
			{
				cout << j << ' ' << i;
			}
		}
	}
	return 0;
}
