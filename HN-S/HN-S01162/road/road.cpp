#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1,M=1e6+1;
struct E{
	int u,v,w;
}e[M];
int a[N];
bool cmp(E a,E b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
			cin>>e[i].u>>e[i].v>>e[i].w;
		for(int i=1;i<=n;i++)
			f[i]=i;
		int mst=0;
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v,fu,fv;
			fu=find(u);fv=find(v);
			if(fu!=fv)
			{
				f[fu]=fv;
				mst+=e[i].w;
			}
		}
		cout<<mst;
	}
	return 0;
}
