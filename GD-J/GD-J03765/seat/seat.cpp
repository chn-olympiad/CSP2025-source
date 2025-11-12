#include<bits/stdc++.h>
using namespace std;
int a[105],b[12][12];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	int r = a[1];
	sort(a,a + n * m + 1);
	int d = n * m;
	for(int i = 1;i <= m;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				b[i][j] = a[d--];
			}
		}
		else
		{
			for(int j = n;j >= 1;j--)
			{
				b[i][j] = a[d--];
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(b[i][j] == r)
			{
				cout << i << ' ' << j;
			}
		}
	}
	
	return 0;
 } 
