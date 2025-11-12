#include <bits/stdc++.h>
using namespace std;

int a[110] = {0};

bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	int r = a[1];
	for (int i = 2;i <= n * m;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + 1 + n * m,cmp);
	int x = 1,y = 1,w = 1,biao = 0;
	while (1)
	{
		if (a[w] == r)
		{
			printf("%d %d",y,x);
			return 0;
		}
		w += 1;
		if (!biao)
		{
			x += 1;
			if (x > n)
			{
				y += 1;
				x = n;
				biao = 1;
			}
		}
		else
		{
			x -= 1;
			if (x < 1)
			{
				y += 1;
				x = 1;
				biao = 0;
			}
		}
	}
	return 0;
}
