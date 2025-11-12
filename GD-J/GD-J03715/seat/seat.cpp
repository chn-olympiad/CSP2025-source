#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,a[125],rps,st[11][11];

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	rps = a[1];
	sort(a+1,a+m*n+1,cmp);
	for (int i = 1;i <= m;i++) // 列遍历 
	{
		for (int j = 1;j <= n;j++) // 行遍历
		{
			if (a[(i-1)*n+j]==rps)
			{
				if (i%2)
				{
					printf("%d %d",i,j);
				}
				else
				{
					printf("%d %d",i,n-j+1);
				}
				return 0;
			}
		} 
	}
	return 0;
}
