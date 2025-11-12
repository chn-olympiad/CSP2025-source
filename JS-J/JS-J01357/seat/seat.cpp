#include <bits/stdc++.h>
using namespace std;
int a[50][50],b[120],d[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,c;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> b[i];
	}
	int tmp=b[1];
	sort(b+1,b+n*m+1);
	for(int i = 1,j = n*m; i <= n*m&&j>=1; i++,j--)
	{
		d[j] = b[i];
	}
	int k = 0;
	for(int i = 1; i <= m; i++)
	{
		if(i%2==1)
		{
			for(int j = 1; j <= n; j++)
			{
				k++;
				a[j][i] = d[k];
			}
		}
		else
		{
			for(int j = n; j >=1; j--)
			{
				k++;
				a[j][i] = d[k];
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == tmp)
			{
				r = i, c = j;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
