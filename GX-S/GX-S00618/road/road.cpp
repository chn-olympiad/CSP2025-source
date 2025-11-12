#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
bool use[10015],bj[15];
int n,m,k;
ll ans,h[15],sum[10015];
vector<pil > v[10015];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z}),v[y].push_back({x,z});
	}
	for(int i=n+1;i<=n+k;i++)
	{
		int x,t;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			cin>>t;
			v[i].push_back({j,t}),v[j].push_back({i,x+t});
		}
	}
	n+=k;
	for(int i=2;i<=n;i++)
		sum[i]=1e18;
	int p=n;
	while(p--)
	{
		int u=-1;
		for(int i=1;i<=n;i++)
			if((u==-1||sum[u]>sum[i])&&!use[i])
				u=i;
		use[u]=true,ans+=sum[u];
		for(auto i:v[u])
		{
			if(!use[i.first]&&sum[i.first]>i.second)
			{
				sum[i.first]=i.second;
				if(u>=n-k+1)
					bj[u-n+k]=true;
				if(i.first>=n-k+1)
					h[i.first-n+k]=i.second;
			}
		}
	}
	for(int i=1;i<=k;i++)
		if(!bj[i])
			ans-=h[i];
	cout<<ans;
	return 0;
}
