#include<bits/stdc++.h>
using namespace std;
#define PII pair<long long,int>
const int N=1e4+5,M=2e6+5;
struct Edge{
	int to,next;
	long long w;
}e[M*2];
int cnt,head[N];
void add(int u,int v,long long w)
{
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void csh(int i)
{
	e[i].to=0;
	e[i].w=0;
	e[i].next=-1;
}
bool vis[N],b[N],vis2[N];
int n,m,k;
long long num=LLONG_MAX,d[N],a[15][N],c[15],y[N];
priority_queue<PII,vector<PII>,greater<PII> > q;
long long prim(int u,int o,int sum)
{
	for(int i=1;i<=o;i++) d[i]=0x7f7f7f7f;
	for(int i=1;i<=o;i++) vis[i]=false;
	long long ans=0,l=0; 
	d[u]=0;
	q.push({d[u],u});
	while(!q.empty())
	{
		
		PII t=q.top();
		q.pop();
		long long di=t.first;int ui=t.second;
		if(vis[ui]) continue;
		vis[ui]=true;
		ans+=d[ui];
		l++;
//		if(ans+sum>num) return ans;
		if(l==o) break;
		for(int i=head[ui];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(d[v]>e[i].w)
			{
				d[v]=e[i].w;
				q.push({d[v],v});
			}
		} 
	}
	return ans;
}
void dfs(int x,long long sum)
{
	if(sum>num) return ;
	if(x>k)
	{
		int o=0;
		cnt=2*m;
		for(int i=2*m+1;i<=2*m+k*2*n;i++) csh(i);
		for(int i=1;i<=n+k;i++) head[i]=y[i];
		for(int i=1;i<=k;i++)
		{
			if(b[i])
			{
				o++;
				for(int j=1;j<=n;j++)
				{
					add(n+i,j,a[i][j]),add(j,i+n,a[i][j]);
				}
			}
		}
		long long x=prim(1,o+n,sum);
		num=min(num,x+sum);
		
		return ;
	}	
	if(vis2[x]==true)
	{
		b[x]=true;
		dfs(x+1,sum+c[x]);
		return ;
	}
	b[x]=true;
	dfs(x+1,sum+c[x]);
	b[x]=false;
	dfs(x+1,sum);
	return ;
}

int main()
{ 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	memset(head,-1,sizeof(head));
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w),add(v,u,w);
	}
	memset(y,-1,sizeof(y)); 
	for(int i=1;i<=n;i++) y[i]=head[i];
	for(int i=1;i<=k;i++) 
	{
		int cnt2=0;
		cin>>c[i];
		if(c[i]==0) vis2[i]=true;
		for(int j=1;j<=n;j++) 
		{
			cin>>a[i][j];
			if(a[i][j]==0) cnt2++;
		}
		if(cnt<2) vis2[i]=false;
	}
	dfs(1,0);
	cout<<num<<"\n";
	return 0;
}
