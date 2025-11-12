#include<bits/stdc++.h>
using namespace std;
int n,m,k,j2[100005],vj[100005],dis[100005],dis1[100005],vis[100005],kk,mi,v[100005],v2[100005];
vector<pair<int,int> > e[100005],e1[100005];
string r[100005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q,q1;
void dfs(int s)
{
	memset(dis1,127,sizeof(dis1));
	memset(v2,0,sizeof(v2));
	dis1[s]=0;
	q1.push({0,s});
	while(!q1.empty())
	{
		int x=q1.top().first,y=q1.top().second;
		q1.pop();
		if(v2[y])continue;
		v2[y]=1;
		for(int i=0;i<e1[y].size();i++)
		{
			int ww=e1[y][i].first;
			int vv=e1[y][i].second;
			if(vj[vv]==0&&vv>n)
			{
				ww+=j2[vv];
				vj[vv]=1;
			}
			if(dis1[vv]>x+ww)
			{
				dis1[vv]=x+ww;
				e1[y][i].second=0;
			}
			q1.push({dis1[vv],vv});
		}
		
	}
	
}
void ds(int s)
{
	
	memset(dis,127,sizeof(dis));
	dis[s]=0;
	r[s]="1";
	q.push({0,s});
	while(!q.empty())
	{
		
		int x=q.top().first,y=q.top().second;
		q.pop();
		
		if(v[y]==1)continue;
		v[y]=1;
		for(int i=0;i<e[y].size();i++)
		{
			int ww=e[y][i].first;
			int vv=e[y][i].second;
			if(vj[vv]==0&&vv>n)
			{
				ww+=j2[vv];
				vj[vv]=1;
			}
			if(dis[vv]>x+ww)
			{
				dis[vv]=x+ww;
				e[y][i].second=0;
				char no=(char)(vv+'0');
				r[vv]=r[y]+' '+no;
			}
			q.push({dis[vv],vv});
		}
		
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({w,v});
		e[v].push_back({w,u});
		e1[u].push_back({w,v});
		e1[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>j2[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			e[i+n].push_back({w,j});
			e[j].push_back({w,i+n});
			e1[i+n].push_back({w,j});
			e1[j].push_back({w,i+n});
		}
		
	}
	ds(1);
	int cnt=0;
	for(int i=0;i<r[n].size();i++)
	{
		if(r[n][i]==' ')
		{
			vis[cnt]=1;
			cnt=0;
		}
		else
		{
			cnt=cnt*10+r[n][i]-'0';
		} 
		if(i==r[n].size()-1)
		{
			vis[cnt]=1;
			cnt=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			mi=1e9;
			dfs(i);
			for(int j=1;j<=n&&j!=i;j++)
			{
				mi=min(mi,dis1[j]);
			}
			dis[n]+=mi;
			
		}
	}
	cout<<dis[n];
	return 0;
}

