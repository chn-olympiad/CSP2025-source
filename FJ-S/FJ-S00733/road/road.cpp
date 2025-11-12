#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
};
road a[1000005];
bool b[10005];
bool tmp(road x,road y)
{
	if(x.w>y.w)
	{
		return 0;
	}
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k!=0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort (a+1,a+m+1,tmp);
	int sum=0;
	sum+=a[1].w;
	b[a[1].u]=1;
	b[a[1].v]=1;
	int i=2;
	while(1)
	{
		int x=0;
		for(int j=1;j<=n;j++)
		{
			x+=b[j];
		}
		if(x==n)
		{
			cout<<sum;
			return 0;
		}
		if((b[a[i].u]==0&&b[a[i].v]==1)||(b[a[i].u]==1&&b[a[i].v]==0))
		{
			b[a[i].u]=1;
			b[a[i].v]=1;
			sum+=a[i].w;
		}
		i++;
	}
	return 0;
}

