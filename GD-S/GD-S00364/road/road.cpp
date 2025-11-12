#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e18;
vector<pair<long long,long long> >a[10001];
long long vis[10001];
multiset<long long>ms;
long long d[10001];
struct t{
	long long v,q[10001];
}b[11];
void dfs(long long p,long long sum,long long cn)
{
	cout<<p<<" "<<sum<<" "<<cn<<'\n';
	if(cn==n)
	{
		ans=min(ans,sum);
		return;
	}
	for(long long i=0;i<a[p].size();++i)
	{
		if(!vis[a[p][i].first])
		{
			vis[a[p][i].first]=1;
			dfs(a[p][i].first,sum+a[p][i].second,cn+1);
			vis[a[p][i].first]=0;
		}
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(long long i=1;i<=n;++i)d[i]=1e18;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;++i)
	{
		long long u,v,s;cin>>u>>v>>s;
		a[u].push_back({v,s});
		a[v].push_back({u,s});
	}
	for(long long i=1;i<=k;++i)
	{
		cin>>b[i].v;
		long long sum=0;
		for(long long j=1;j<=n;++j)
		{
			cin>>b[i].q[j];
			sum=max(b[i].q[j],sum);
		}
		if(sum==0)
		{
			cout<<0;
			return 0;
		}
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
