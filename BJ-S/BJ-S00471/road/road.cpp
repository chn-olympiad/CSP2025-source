#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
struct Edge
{
	int u,v,w,nxt;
}edge[N];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int cnt,head[N],town[N],fa[N];
void add(int u,int v,int w)
{
	cnt++;
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void kkl(int n,int m)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+m+1,cmp);
	int sum=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u==v) continue;
		fa[u]=v;
		sum+=edge[i].w;
		cnt++;
		if(cnt==n-1)
		{
			cout<<sum;
			return;
		}
	}
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m,k;		
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	int flag=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++) 
		{
			cin>>town[j];
			if(town[j]!=0) flag=1;
		}
	}
	if(k==0) kkl(n,m);
	else if(flag==0) cout<<0;
}