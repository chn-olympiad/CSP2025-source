#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+1e5+5,N=2e4+5;
int n,m,k;
vector<pair<int,int> > a[N];
priority_queue<int> q;
struct node
{
	int u,v,w;
}e[M];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int c[15][N];
int fa[N];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
int ans=1e9;
void conn(int x)
{
	for(int i=1;i<=2*n;i++) fa[i]=i;
	int la=m,num=n;
	int cnt=0,tmp=0;
	for(int i=1;i<=k;i++)
	{
		if(1<<(i-1)&x)
		{
			num++;
			tmp+=c[i][1];
			for(int j=1;j<=n;j++) 
			{
				e[++la]={i+n,j,c[i][j+1]};
			}
		}
	}
	sort(e+1,e+1+la,cmp);
	for(int i=1;i<=la;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			merge(e[i].u,e[i].v);
			cnt++;
			tmp+=e[i].w;
			if(cnt>=num-1) break;
		}
	}
	ans=min(tmp,ans);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u].push_back({w,v});
		a[v].push_back({w,u});
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		conn(i);
	}
	cout<<ans;
	return 0;
}
