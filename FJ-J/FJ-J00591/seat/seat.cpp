#include<bits/stdc++.h>
using namespace std;
int s[101],n,m,a[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> s[i];
	int r = s[1];
	for(int i = 1;i <= n * m;i++)
	{
		for(int j = i;j <= n * m;j++)
		{
			if(s[i] < s[j])
			{
				int l = s[i];
				s[i] = s[j];
				s[j] = l;
			}
		}
	}
	int l = 1;
	int o = 1;
	for(int i = 1;i <= m;i++)
	{
		if(o == 1)
		{
			for(int j = 1;j <= n;++j)
			{
				a[i][j] = s[l];
				l++;
			}
		}
		else
		{
			for(int j = n;j >= 1;--j)
			{
				a[i][j] = s[l];
				l++;
				
			}
		}
		o = 0 - o;
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(a[i][j] == r)
				cout << i << ' ' << j;
		}
	}
	return 0;
}
