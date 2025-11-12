#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e12;
int n,m,k,ans;
struct edge{
	int u,v,w;
}arr[8000001];
vector<vector<int> >vt(100001);
int d[100001],p,brr[50001][11],r[50001];
bool vis[100001];
map<pair<int,int>,int > mp;
void f(int u,int x)
{
	d[u]=x;
	vis[u]=1;
	for(auto ne:vt[u])
	{
		if(vis[ne]==0)
		{
			f(ne,x);
		}
	}
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		arr[i].u=u,arr[i].v=v,arr[i].w=w;
	}
	for(int j=1;j<=n;j++)
	{
		for(int k=j+1;k<=n;k++)
		{
			mp[{j,k}]=inf;	
		} 
	}
	for(int i=1;i<=k;i++)
	{
		cin>>r[i];
		for(int j=1;j<=n;j++)
		{
			cin>>brr[j][i];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				mp[{j,k}]=min(mp[{j,k}],brr[k][i]+r[i]+brr[j][i]);	
			} 
		}
	}
	
	for(int j=1;j<=n;j++)
	{
		for(int k=j+1;k<=n;k++)
		{
			arr[++m]={j,k,mp[{j,k}]};	
		} 
	}
//	cout<<idx<<" "; 
//	cout<<1;
	for(int i=1;i<=n;i++)d[i]=i;
	sort(arr+1,arr+m+2,cmp);
	for(int i=1;i<=m;i++)
	{
		if(d[arr[i].u]!=d[arr[i].v])
		{
			ans+=arr[i].w;
			f(d[arr[i].u],d[arr[i].v]);
			vt[arr[i].u].push_back(arr[i].v);
			vt[arr[i].v].push_back(arr[i].u);
			
		//	cout<<arr[i].u<<" "<<arr[i].v<<" "<<arr[i].w<<"\n";
			memset(vis,0,sizeof(vis));
		}
	//	cout<<1;
	}
	cout<<ans;
	return 0;
}
