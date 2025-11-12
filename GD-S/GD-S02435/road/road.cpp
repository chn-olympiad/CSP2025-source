#include<bits/stdc++.h>//Ren5Jie4Di4Ling5%
#define ll long long//n 1e4,m 1e6,k 10,a 1e9
#define endl "\n"
using namespace std;
ll n,m,k,ans=9999999999;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >e[10005];
//first长度，second v 
int a[12][10005];
bool ok[12];
map<int,map<int,bool> >vis;//边 
void dfs(int x,int cost)//城市化的乡镇
{
	if(cost>=ans)return;
	if(x==k+1)
	{
		vis.clear();
		for(int i=1;i<=k;i++)
		{
//			cout<<ok[i]<<' ';
			if(!ok[i])continue;
			for(int j=1;j<=n;j++)
			{
				e[j].push({a[i][j],n+i});
//				cout<<a[i][j]<<' ';
			}
//			cout<<endl;
		}
//		cout<<endl;
		ll temp=0;
		for(int i=1;i<=n;i++)
		{
			while(!e[i].empty() && e[i].top().second>n && !ok[e[i].top().second-n])e[i].pop();
			if(e[i].empty())return;//不连通 
			if(!vis[i][e[i].top().second])temp+=e[i].top().first,vis[i][e[i].top().second]=1,vis[e[i].top().second][i]=1;
//			cout<<e[i].top().first<<' ';
		}
//		cout<<endl;
		ans=min(ans,temp+cost);
		return;
	}
	ok[x]=1;
	dfs(x+1,cost+a[x][0]);
	ok[x]=0;
	dfs(x+1,cost);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		e[u].push({w,v});
		e[v].push({w,u});
	}
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)cin>>a[i][j];
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
