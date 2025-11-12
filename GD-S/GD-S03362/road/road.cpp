#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int minx = 999999;
int b[1000];
int c[1000];
struct ap
{
	int u;
	int v;
	int w;
	int zx;
}a[1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int j = 1; j <= k;j++)
	{
		cin >> b[j];
	}
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n;i++)
		{
			if (i != j)
			{

					minx = min(minx,a[i].w+a[j].w);
			}
		}
	}
	cout << minx;
	return 0;
}
