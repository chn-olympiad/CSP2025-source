#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int l = m*n,num;
	int seat[n+1][m+1] = {},mk[l+1] = {},mk1[l+1] = {};
	for(int i = 1;i <= l;i++)
	{
		cin >> mk[i];
		if(i == 1)
		{
			num = mk[i];
		}
	}
	sort(mk+1,mk+l+1);
	int t = 1,u = 1,d = l;
	for(int i = l;i >= 0;i--)
	{
		mk1[t] = mk[i];
		t++;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(i % 2 != 0)
			{
				seat[i][j] = mk1[u];
				u++;
			}
			if(i % 2 == 0)
			{
				seat[i][j] = mk1[d];
				d--;
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(seat[i][j] == num)
			{
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
