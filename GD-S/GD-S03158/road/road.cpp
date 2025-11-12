#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10,K=20;
struct node
{
	int u,v,w;
	bool operator<(const node&x)const&
	{
		return w<x.w;
	}
}e[M];
vector<node> E[1024];
int a[K][N];
int f[N];
int num[1024];
int c[K],dp[K];
int n,m,k;
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y) 
{
	f[find(y)]=find(x);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++) 
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m);
	for(int i=1;i<=n;i++) f[i]=i;
	int tot=0; ll mina=0;
	for(int i=1;i<=m;i++)
		if(find(e[i].u)!=find(e[i].v))
		{
			merge(e[i].u,e[i].v);
			E[0].push_back(e[i]);
			mina+=e[i].w;
			if((++tot)==n-1) break;
		}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<(1<<k);i++) 
		num[i]=num[i&(i-1)]+1;
	for(int i=1;i<(1<<k);i++)
	{
		vector<node> ee;
		for(auto v:E[i&(i-1)])
			ee.push_back(v);
		int lw,cnt=0; ll ans=0;
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1)
			{
				lw=j;
				break;
			}
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1)
				ans+=c[j];
		for(int j=1;j<=n;j++)
			ee.push_back({n+lw,j,a[lw][j]});
		sort(ee.begin(),ee.end());
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(auto it:ee)
			if(find(it.u)!=find(it.v))
			{
				merge(it.u,it.v);
				E[i].push_back(it);
				ans+=it.w;
				if((++cnt)==n+num[i]-1) break;
			}
		mina=min(mina,ans);
	}
	cout<<mina;
	return 0;
}
