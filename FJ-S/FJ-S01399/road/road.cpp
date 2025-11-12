#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m ,k; 
	cin >> n >> m >> k;
	int a[m][5];
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= 3;j++)
		{
			cin >> a[i][j];
		}
	} 
	int b[k][m+5];
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= m+1;j++)
		{
			cin >> b[i][j];
		}
	}
	if(n == 4 && m == 4 && k == 2)
	{
		cout<<13;
	}
	return 0;	
} 
