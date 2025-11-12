#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct NODE{
	int u,v,w;
}a[N];
bool cmp(NODE x,NODE y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int xc[1001][1001],f[1001]={};
	int jl[1001][1001];
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>xc[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>xc[i][j];
		}
	}
	int juq=0;
	for(int i=1;i<=m;i++)
	{
		if(i==1)
		{
			juq+=a[i].w;
			f[a[i].u]=1;
			f[a[i].v]=1;
		}
		if(f[a[i].u]==1&&f[a[i].v]==1) continue;
		
	}
	cout<<juq;
	return 0;
}
