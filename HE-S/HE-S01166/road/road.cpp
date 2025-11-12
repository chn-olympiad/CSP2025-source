#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P ;
int cnt,n,m,k,f[10005],minn=INT_MAX,a[20][10005];
int c[20];
int val[1000005],to[1000005],nxt[1000005],head[10005];
priority_queue<P,vector<P>,greater<P> > q;
void add(int u,int v,int w)
{
	cnt++;
	val[cnt]=w;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
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
		add(u,v,w);
		add(v,u,w);
	}
	int ans=0;
	q.push(P(0,1));
	while(!q.empty())
	{
		int u=q.top().second;
		int ww=q.top().first;
		q.pop();
		
		if(f[u]==0)
		{
			ans+=ww;
			f[u]=1;
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i],w=val[i];
				q.push(P(w,v));
			}
		}
	}
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	minn=min(minn,ans);
	ans=0;
	for(int i=1;i<=k;i++)
	{
		int l=1;
		cin>>c[i];
		if(c[i]==0)
		{
			for(int j=1;j<=n;j++)
			{
				int a;
				cin>>a;
				add(i+m,j,a);
				add(j,i+m,a);
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				int a;
				cin>>a;
			}
		}
	}
	q.push(P(0,1));
	while(!q.empty())
	{
		int u=q.top().second;
		int ww=q.top().first;
		q.pop();
		if(f[u]==0)
		{
			ans+=ww;
			f[u]=1;
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i],w=val[i];
				q.push(P(w,v));
				
			}
		}
	}
	minn=min(minn,ans);
	cout<<minn;
	return 0;
}
