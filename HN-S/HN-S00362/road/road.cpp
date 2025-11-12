#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5;
const int M=1e6+5;
int n,m,k,fa[N],op[15][N],cost[15],tot,minn=1e18,now,siz[N];
long long sum;
struct node
{
	int u,v,w;
}a[M],b[N],c[M];
bool cmp(node a,node b){return a.w<b.w;}
int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
void kruskal(bool flag)
{
	for(int i=1;i<=tot;i++)c[i]=a[i];
	sort(c+1,c+tot+1,cmp);
	sum=0;
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=n+1;i<=n+k;i++)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=tot;i++)
	{
		int fx=find(c[i].u),fy=find(c[i].v);
		if(fx==fy)continue;
		cnt++;
		if(flag)b[cnt]=c[i];
		sum+=c[i].w;
		fa[fx]=fy;
		siz[fy]+=siz[fx];
		if(siz[fy]==n)break; 
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	tot=m;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	kruskal(true);
	minn=sum;
	for(int i=1;i<n;i++)a[i]=b[i];
	for(int i=1;i<=k;i++)
	{
		cin>>cost[i];
		for(int j=1;j<=n;j++)cin>>op[i][j];
	}
	for(int i=0;i<(1<<k);i++)
	{
		tot=n-1;
		now=0;
		int ans=0;
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				for(int k=1;k<=n;k++)a[++tot]={j+1+n,k,op[j+1][k]};
				now++; 
				ans+=cost[j+1];
			}
		}
		kruskal(false);
		minn=min(minn,sum+ans);
	}
	cout<<minn;
	return 0;
}

