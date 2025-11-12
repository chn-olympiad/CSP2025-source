#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k[110][110];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	int r = a[1],idx = 0;
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= m;j++)
				k[i][j] = a[++idx];
		}
		else
		{
			for(int j = m;j >= 1;j--)
				k[i][j] = a[++idx];
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(k[i][j] == r)
				cout << i << ' ' << j;
	return 0;
}
