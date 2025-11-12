#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long n,m,k,g=0,sum=0,num=0;
long long u[N],v[N],w[N],a[N][10],c[10],fa[N];
long long z[N];
int find(int x)
{
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]); 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];if(c[i]!=0)g=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][i];
			if(a[j][i]!=0)g=1;
		}
	}
	if(g==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(find(u[i])==find(v[i]))
		{
			z[i]=1;
			continue;
		}
		else
		{
			fa[find(u[i])]=find(v[i]);
			sum+=w[i];
		}
	}
	if(k==0)cout<<sum;

	return 0;
}
