#include <bits/stdc++.h>
using namespace std;
int n , m;
int a[107];
int xiaoming;
int cnt = 0;
int main()
{
	freopen("seat.in", "r" ,stdin);
	freopen("seat.out", "w" ,stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n * m; i++)
	{
		scanf("%d",&a[i]);
	}
	xiaoming = a[1];
	sort(a + 1, a + (n * m) + 1);
	cnt = n * m + 1;
	for(int i = 1; i <= m; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1; j <= n; j++)
			{
				cnt--;
				if(xiaoming == a[cnt])
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j = n; j >= 1; j--)
			{
				cnt--;
				if(xiaoming == a[cnt])
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
