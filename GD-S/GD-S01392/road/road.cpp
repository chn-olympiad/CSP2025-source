#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int v,w;
	bool operator<(const node& a)const
	{
		return a.w<w;
	}
};
vector<node>t[25010];
int n,m,k,a[15][10025],vc[15],vis[10025],lcc,lcr[25],sum;
ll mans=1e18;
priority_queue<node>q;
ll build()
{
	ll minn=0;
	sum=1;
	for(int i=1;i<=lcc;i++)minn+=(ll)(vc[lcr[i]]);
	vis[1]=1;
	for(int i=0;i<t[1].size();i++)
	{
		q.push(t[1][i]);
	}
	node now,net;
	for(int i=1;i<=lcc;i++)
	{
		now.v=n+lcr[i];
		now.w=a[lcr[i]][1];
		q.push(now);
	}
	while(!q.empty())
	{
		now=q.top();
		q.pop();
		if(vis[now.v])continue;
		if(sum>=n+lcc)break;
		sum++;
		vis[now.v]=1;
		minn+=(ll)now.w;
		if(now.v<=n)
		{
			for(int i=0;i<t[now.v].size();i++)
			{
				if(vis[t[now.v][i].v])continue;
				q.push(t[now.v][i]); 
			}
			for(int i=1;i<=lcc;i++)
			{
				if(vis[n+lcr[i]])continue;
				net.v=n+lcr[i];
				net.w=a[lcr[i]][now.v];
				q.push(net);
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i])continue;
				net.v=i;
				net.w=a[now.v-n][i];
				q.push(net);
			}
		}
	}
	while(!q.empty())q.pop();
//	for(int i=1;i<=lcc;i++)cout<<lcr[i]<<" ";
//	cout<<minn<<endl;
	return minn;
}
void dfs(int h)
{
	if(h>k)
	{
		memset(vis,0,sizeof(vis));
		while(!q.empty())q.pop();
		mans=min(mans,build());
		return ;
	}
	if(h<=k)dfs(h+1);
	lcc++;
	lcr[lcc]=h;
	dfs(h+1);
	lcc--;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u;
	node v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v.v,&v.w);
		t[u].push_back(v);
		swap(u,v.v);
		t[u].push_back(v);
	}
	for(int i=1;i<=k;i++)
	{
		if(k>3)
		{
			lcc++;
			lcr[lcc]=i;
		}
		cin>>vc[i];
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(k<=3)
	{
		dfs(1);
		cout<<mans;
	}
	else cout<<build();
	return 0;
}
