#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0;
	int x[15][15]={0};
	int s[105]={0}; 
	cin >> n >> m;
	for(int i = 1; i <= (n*m); i++)
	{
		cin >> s[i];
		k++;
	}
	int t = s[1];
	sort(s+1,s+k+1,greater<int>());
	k = 1;
	for(int i = 1; i <= m; i++)
	{
		if(i % 2 != 0)
		{
			for(int j = 1; j <= n; j++)
			{
				x[j][i] = s[k];
				k++;
			}
		}
		if(i % 2 == 0)
		{
			for(int j = n; j >= 1; j--)
			{
				x[j][i] = s[k];
				k++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(x[i][j] == t)
			{
				cout << j  << " " << i;
				return 0;
			}
		}
	}
} 