#include <bits/stdc++.h>
using namespace std;

struct Node{
	int id,v;
};

int n,m;
Node a[110];

bool cmp(Node x,Node y)
{
	return x.v > y.v;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n * m;i++)
	{
		scanf("%d",&a[i].v);
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	int k;
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i].id == 1) k = i - 1;
	}
	int l = 1,r = 1; bool f = 0;
	while (k--)
	{
		if (f == 0)
		{
			if (r == n)
			{
				f = 1;
				l++;
			}
			else
			{
				r++;
			}
		}
		else
		{
			if (r == 1)
			{
				f = 0;
				l++;
			}
			else
			{
				r--;
			}
		}
	}
	printf("%d %d\n",l,r);
	return 0;
}
