#include <bits/stdc++.h> 
using namespace std;
struct road
{
	int u,v,w;
}s[1000001];
int f[10001];
bool cmp(road a,road b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,p=0;
	long long z=0;
	bool x=true;
	bool y=true;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
		if (s[i].u>s[i].v)
		swap(s[i].u,s[i].v);
	}
	sort(s+1,s+1+n,cmp);
	if (k==0)
	{
		for (int i=1;i<=m;i++)
		{
			if (p==n-1)
			break;
			x=true;
			y=true;
			for (int j=1;j<=p;j++)
			{
				if (s[i].u==f[j])
				x=false;
				if (s[i].v==f[j])
				y=false;
			}
			if (x==false && y==false)
			continue;
			z+=s[i].w;
			p++;
		}
	}
	printf("%lld",z);
	return 0;
}
