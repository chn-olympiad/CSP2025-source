#include <bits/stdc++.h>

using namespace std;

int n,m,k,e;

struct Node
{
	int a,b,c;
}d[100005];
int f[12][1000005];

int main()
{
	freopen("roud.in","r",stdin);
	freopen("roud.out","w",stdout);
	cin >>n>>m>>k;
	for(int i = 1;i<=m;i++)
	{
		cin >>d[i].a>>d[i].b>>d[i].c;
		e+=d[i].c;
	}
	for(int i = 1;i<=k;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			cin >> f[i][j];
		}
	}
	cout<<e;
	
	return 0;
}
