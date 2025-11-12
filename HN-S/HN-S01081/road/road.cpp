# include<bits/stdc++.h>
using namespace std;
struct Edge{
	int v,w;
	bool operator <(const Edge e) const
	{
		return w>e.w;
	}
};
int n,m,k,minl=INT_MAX,c[15];
bool f[10015];
priority_queue<Edge>q;
vector<Edge>e[10005];
int solve(int num,int sum)
{
	int ans=sum,cnt=1;
	f[1]=1;
	for(int i=0;i<e[1].size();i++) q.push(e[1][i]);
	while(!q.empty())
	{
		while(f[q.top().v] and !q.empty()) q.pop();
		Edge temp=q.top();
		q.pop();
		f[temp.v]=1;
		for(int i=0;i<e[temp.v].size();i++) q.push(e[temp.v][i]);
		ans+=temp.w;
		cnt++;
		if(cnt==n+num) break;
	}
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) f[i]=0;
	return ans;
}
void dfs(int x,int num,int sum)
{
	if(x==k+1)
	{
		minl=min(minl,solve(num,sum));
		return;
	}
	f[n+x]=1;
	dfs(x+1,num,sum);
	f[n+x]=0;
	dfs(x+1,num+1,sum+c[x]);
	f[n+x]=1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back((Edge){v,w});
		e[v].push_back((Edge){u,w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			e[i+n].push_back((Edge){j,x});
			e[j].push_back((Edge){i+n,x});
		}
	}
	dfs(1,0,0);
	printf("%d",minl);
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
