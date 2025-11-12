#include<bits/stdc++.h>
using namespace std;
struct node{int u,v;long long w;};
bool operator<(node x,node y)
{
	return x.w<y.w;
}
int n,m,k,f[10001];
long long ans=100000000000000000,c[20];
node edge[2000000];
int find(int x)
{
	if(f[x]==x)
		return x;
	int r=find(f[x]);
	f[x]=r;
	return r;
}
void merge(int x,int y)
{
	int rx=find(x),ry=find(y);
	if(rx==ry)
		return;
	f[rx]=ry;
	return;
}
long long Kruskal(int x)
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(edge+1,edge+x+1,less<node>());
	long long res=0;
	for(int i=1;i<=x;i++)
	{
		int u=edge[i].u,v=edge[i].v;
		long long w=edge[i].w;
		int ru=find(u),rv=find(v);
		if(ru==rv)
			continue;
		res+=w;
		f[ru]=rv;
		//~ cerr<<'$'<<x<<' '<<u<<' '<<v<<' '<<w<<'\n';
	}
	//~ cerr<<'#'<<x-m<<' '<<res<<'\n';
	return res;
}
int main()
{ 	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	if(k==0)
	{
		ans=Kruskal(m);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			long long x;
			cin>>x;
			int idx=n+i;
			edge[m+(i-1)*n+j].u=idx;
			edge[m+(i-1)*n+j].v=j;
			edge[m+(i-1)*n+j].w=x;
		}
	}
	for(int i=0;i<=k;i++)
	{
		long long tmp=Kruskal(m+i*n);
		cerr<<'#'<<i<<' '<<tmp<<' '<<c[i]<<'\n';
		tmp+=c[i];
		ans=min(ans,tmp);
	}
	return 0;
}
