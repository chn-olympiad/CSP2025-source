#include <bits/stdc++.h>
using namespace std;
struct S
{
	int f;
	int h;
}a[1005];
int n,m,jia,z[15][15]={},cnt = 0; 
bool cmp(S x,S y)
{
	return x.f > y.f;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i].f;
		a[i].h = i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i].h == 1)	
		{
			jia = i;
			break;
		}
	}
	for(int j = 1;j <= m;j++)
	{
		if(j%2==1)
		{
			for(int i = 1;i <= n;i++)
			{
				cnt++;
				z[i][j] = 1;
				if(cnt == jia)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		}
		else
		{
			for(int i = n;i >= 1;i--)
			{
				cnt++;
				z[i][j] = 1;
				if(cnt == jia)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
