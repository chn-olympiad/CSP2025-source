#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
const int N=10086;
long long a,ans;
struct city{
	vector<pair<int,long long>> brother_city;
	long long sum,minn,jianshe;
	bool vis,jian;
}c[10004];
void dfs(int p,int total)
{
	long long mini=0,minx=0x3f3f3f3f;
	c[p].vis=1,c[p].jian=0;
	if(total==n) return;
	for(auto u:c[p].brother_city)
	{
		if(c[u.first].vis==0)
		{
			c[u.first].minn=min(u.second+c[u.first].jianshe*c[u.first].jian,c[u.first].minn);
			if(u.second+c[u.first].jianshe*c[u.first].jian<minx)
			{
				mini=u.first;
				minx=u.second+c[u.first].jianshe*c[u.first].jian;
			}
		}
	}
	if(mini!=0)
	{
		//cout<<mini<<" "<<minx<<"\n ";
		ans+=minx;
		if(c[mini].jian==1) total--;
		dfs(mini,total+1);
	}
	
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		c[i].minn=0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		c[x].brother_city.push_back({y,z});
		c[y].brother_city.push_back({x,z});
	}
	for(int i=n+1;i<=k+n;i++)
	{
		int x;
		cin>>c[i].jianshe;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			c[j].brother_city.push_back({i,x});
			c[i].brother_city.push_back({j,x});
		}
		c[i].jian=1;
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		if(c[i].vis==0)
		ans+=c[i].minn;
	}
	cout<<ans;
	return 0;
}