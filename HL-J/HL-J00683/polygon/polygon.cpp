#include <bits/stdc++.h>
//flt
using namespace std;
int n;
unsigned long long int zuida,changdu,zs;
int a[5001];
bool x[5001];
bool pd()
{
	zuida = 0;
	changdu = 0;
	if (count(x,x+n,1) >= 3)
	{
		for (int i = 0;i < n;i++)
		{
			if (x[i])
			{
				if (a[i] > zuida)
				{
					zuida = a[i];
				}
				changdu += a[i];
			}
		}
		if (changdu > zuida*2)
		{
			return 1;
			//zs++;
		}
	}
	return 0;
}
void bfs(int pthis)
{
	if (pthis == n)
	{
		return;
	}
	x[pthis] = 1;
	if (pd())
	{
		zs++;
	}
	bfs(pthis+1);
	
	x[pthis] = 0;
	if (pd())
	{
		zs++;
	}
	bfs(pthis+1);
	
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	/*for (int i = 0;i < n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			for (int k = 0;k < n;k++)x[k] = 0;
			for (int k = i;k <= j;k++)
			{
				x[k] = 1;
			}
			if (pd())
			{
				zs++;
			}
		}
	}*/
	bfs(0);
	//x[2] = 1;x[1] = 1;x[3] = 1;
	//cout << pd();
	cout << zs % 998244353;
	
	
	return 0;
}
