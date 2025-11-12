#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m;
int t,res;
int s[123];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++ ) cin >> s[i];
	t = s[1];
	sort(s + 1,s + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i ++ ) if(s[i] == t) res = i;
	for(int i = 1;i <= n;i += 2)
	{
		for(int j = 1;j <= m;j ++ )
		{
			a[j][i] = (i - 1) * n + j;
		}
	}
	for(int i = 2;i <= n;i += 2)
	{
		for(int j = 1;j <= m;j ++ )
		{
			a[j][i] = (i - 1) * n + m - j + 1;
		}
	}
	for(int i = 1;i <= n;i ++ )
	{
		for(int j = 1;j <= m;j ++ )
		{
			if(a[i][j] == res)
			{
				cout << j << " " << i;
			}
		}
	}
	
	return 0;
}
