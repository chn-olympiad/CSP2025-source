#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+20;
int n,m,k,cnt,ans=LONG_LONG_MAX-INT_MAX,num[N],c[N],b[N],vis[N];
struct node{
	int dis;
	int to;
	bool operator<(const node &a)const{
		return dis>a.dis;
	}
};
vector<node>q[10020];
priority_queue<node>p;
int prim()
{
	int sum=0;
	while(!p.empty())
	{
		int t=p.top().to,l=p.top().dis;
		p.pop();
		if(vis[t]||(t>n&&c[t]==0))
			continue;
		vis[t]=1;
		sum+=l;
		for(int i=0;i<q[t].size();i++)
		{
			int to=q[t][i].to,dis=q[t][i].dis;
			if(vis[to]||num[to]<=dis)
				continue;
			num[to]=dis;
			p.push({dis,to});
		}
	}
	return sum;
}
void dfs(int x)
{
	if(x>k)
	{
		p.push({0,1});
		memset(num,0x3f,sizeof num);
		num[1]=0;
		ans=min(ans,cnt+prim());
		memset(vis,0,sizeof vis);
		return;
	}
	c[x+n]=1;
	cnt+=b[x];
	dfs(x+1);
	cnt-=b[x];
	c[x+n]=0;
	dfs(x+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		q[x].push_back({w,y});
		q[y].push_back({w,x});
	}
	for(int i=1;i<=k;i++)
	{
		int w;
		for(int j=0;j<=n;j++)
		{
			if(j==0)
			{
				cin>>b[i];
				continue;
			}
			cin>>w;
			q[n+i].push_back({w,j});
			q[j].push_back({w,n+i});
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
