#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int g[20],gg[20][110000],open[20];
vector<pair<int,int>>vv[110000];
vector<pair<int,int>>vvv[110000];
int shu()
{
	map<int,int>mp;
	mp[1]=1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for(int i=0;i<vv[1].size();i++)
	{
		pq.push({vv[1][i].second,vv[1][i].first});
	}
	int ans=0,cnt=1;
	while(pq.size())
	{
		int x=pq.top().first,y=pq.top().second;pq.pop();
		if(mp.count(y)!=0)continue;
		ans+=x;
		mp[y]=1;
		cnt++;
		if(cnt==n)break;
		for(int i=0;i<vv[y].size();i++)
		{
			if(mp.count(vv[y][i].first)==0)pq.push({vv[y][i].second,vv[y][i].first});
		}
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		vv[x].push_back({y,z});
		vv[y].push_back({x,z});
	}
	cout<<shu();
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
