#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> mp(10005,vector<pair<int,int>>());
struct node2
{
	int c1,c2[10005];
}c[15];
int n,m,k,u,v,weigh,cnt,minn=1000000005,best,ans,vis[10005];
vector<int> p;
bool cmp(vector<pair<int,int>> a,vector<pair<int,int>> b)
{
	return a.size()<b.size();
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v>>weigh;
		mp[u].push_back({v,weigh});
		mp[v].push_back({u,weigh});
	}
	sort(mp.begin(),mp.end(),cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i].c1;
		for(int j=1;j<=n;j++)	cin>>c[i].c2[j];
	}
	int o=1;
	while(mp[o].size()<1)
	{
		o++;
		p.push_back(o);
		vis[o]=1;
	}
	for(int i=0;i<p.size();i++)
	{
		int sum=0,j=1;
		for(;j<=k;j++)	sum+=c[j].c2[p[i]];
		if(sum<minn)
		{
			minn=sum;
			best=j;
		}
	}
	cnt+=p.size();
	ans+=minn;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])	continue;
		if(mp[i].size()==1)
		{
			if(mp[i][0].first<=c[best].c2[i])
			{
				vis[mp[i][0].second]=1;
				cnt+=2;
			}
			else	cnt++;
			ans+=min(mp[i][0].first,c[best].c2[i]);
		}
		else
		{
			minn=1000000005;
			for(auto q:mp[i])
			{
				if(q.first<minn)
				{
					minn=q.first;
					best=q.second;
				}
			}
			ans+=minn;
			vis[best]=1;
		}
		vis[i]=1;
	}
	cout<<ans;
	return 0;	
} 
