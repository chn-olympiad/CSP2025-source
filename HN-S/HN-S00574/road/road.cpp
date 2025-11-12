#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int xiang[10][10002];
struct bian
{
	int u,v,w;
}tu[1000002];
bool cmp(bian x,bian y)
{
	return x.w<y.w;
}
set<int>ct;
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&tu[i].u,&tu[i].v,&tu[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		for(int o=1;o<=n+1;o++)
		{
			scanf("%d",&xiang[i][o]);
		}
	}
	sort(tu+1,tu+m+1,cmp);
	for(int i=1;ct.size()!=n;i++)
	{
		if(!ct.count(tu[i].u)||!ct.count(tu[i].v))
		{
			ct.insert(tu[i].u),ct.insert(tu[i].v);
			ans+=tu[i].w;
		}
	}
	cout<<ans;
	return 0;
}
