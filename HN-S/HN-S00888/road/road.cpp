#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,top=0,sum=0,cnt=0,maxn=0,minn=1e18;
struct edge
{
	int u,v,w;
}s[1100005],pre[1100005];
int a[15][10005],c[15];
bool vis[15];
bool cmp(edge q,edge h)
{
	return q.w<h.w;
}
int da[10005];
int find(int x)
{
//	cout<<x<<'\n';
	if(x==da[x]) return x;
	return da[x]=find(da[x]);
}
void uni(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y) da[x]=y;
	return;
}
void kruskal()
{
	sum=0;
	cnt=n;
	for(int i=1;i<=cnt+k;i++) da[i]=i;
	int id=0;
	while(cnt>1)
	{
		id++;
		int u=s[id].u,v=s[id].v;
		if(find(u)!=find(v))
		{
			if(max(find(u),find(v))<=n) cnt--;
			sum+=s[id].w;
			uni(u,v); 
		}
	}
	return;
}
void dfs(int step,int add)
{
	if(step>k)
	{
		int tmp=m;
		for(int i=1;i<=m;i++) s[i]=pre[i];
		for(int i=1;i<=k;i++)
		{
			if(!vis[i]) continue;
			for(int j=1;j<=n;j++) s[++m]={i+n,j,a[i][j]};
		}
		sort(s+1,s+1+m,cmp);
		kruskal();
		minn=min(minn,sum+add);
		m=tmp;
		return;
	}
	dfs(step+1,add);
	vis[step]=true;
	dfs(step+1,add+c[step]);
	vis[step]=false;
	return;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>s[i].u>>s[i].v>>s[i].w,pre[i]=s[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		maxn=max(maxn,c[i]);
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(maxn==0)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				s[++m]={n+i,j,a[i][j]};
			}
		}
		sort(s+1,s+1+m,cmp);
		kruskal();
		cout<<sum;
		return 0;
	}
	dfs(1,0);
	cout<<minn;
	return 0;
}
/*
5 5 1
1 2 1
2 3 2
2 4 1
3 4 4
4 5 1
0 10 0 10 0 10
*/
