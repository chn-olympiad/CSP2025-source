#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500],se[105][105],ta,cnt=1,fa[105],aaa;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i];
	ta = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n;i++)
	{
		for(int j= 1;j <= m;j++)
		{
			se[j][i] = a[cnt];
			cnt++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		if(i%2== 0)
		{
			memset(fa,0,sizeof(fa));
			aaa=n;
			for(int j=1;j <= n;j++)
				fa[j] = se[j][i];
			for(int j=1;j <= n;j++)
			{
				se[j][i] = fa[aaa];
				aaa--;
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(se[i][j] == ta)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
