#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int u,v,w;
} e[1000010]; 
priority_queue<node> q;
int vis[114514],a[114514];
bool operator<(node a,node b)
{
	return a.w>b.w;
}
int money[114];
int ans,father[114514];
int find(int x)
{
	if(father[x]=x) return x;
	return find(father[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,k,n,m,tmp=0;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
		q.push(e[i]);
	}
	
	for(i=1;i<=k;i++)
	{
		cin>>money[i];
		for(j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			q.push({n+i,j,money[i]+w});
		}
	}
	for(i=1;i<=n+k;i++)
	{
		father[i]=i;
	}
	int u,v,w;
	while(!q.empty())
	{
		/*for(i=1;i<=n+k;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;*/
		node t=q.top();
		q.pop();
		u=t.u;
		v=t.v;
		w=t.w;
		if(father[u]==father[v]) continue;
		if(v<=n && u<=n) tmp++;
		father[v]=father[u];
		//cout<<father[v]<<" "<<father[u]<<endl;
		father[u]=find(u);
		//cout<<father[v]<<" "<<father[u]<<endl;
		if(tmp<=n) ans+=w;
	}

	cout<<ans;
	return 0;
	
}
