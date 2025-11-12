#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Maxn=1e6+5;
const int N=1e4+5;
int n,m,k,f[Maxn];
int c[15],a[15][N];
struct node
{
	int u,v,w;
	bool operator<(const node& o) const
	{
		return w<o.w;
	}
}e[Maxn+N*10];
int find(int k)
{
	if(f[k]==k) return k;
	return f[k]=find(f[k]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) 
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0)
	{
		sort(e+1,e+m+1);
		int ans=0,cnt=0;
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v;
			int x=find(u),y=find(v);
			if(x==y) continue;
			ans+=e[i].w;
			cnt++;
			f[x]=y;
			if(cnt==n-1) break;
		}
		cout<<ans<<'\n';
		return 0;
	}
	else 
	{
		int ans=1e18;
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++) cin>>a[i][j];
		}
		for(int i=0;i<=(1<<k);i++)
		{
			int re=0;
			for(int j=k;j>=0;j--)
			{
				if((i>>j)&1)
				{
					re+=c[j];
					for(int p=1;p<=n;p++)
					{
						e[++m].u=i;
						e[m].v=j;
						e[m].w=a[j][p]+a[p][p];
					}
				}
			}
			sort(e+1,e+m+1);
			int cnt=0;
			for(int j=1;j<=m;j++)
			{
				int u=e[j].u,v=e[j].v;
				int x=find(u),y=find(v);
				if(x==y) continue;
				re+=e[j].w;
				cnt++;
				f[x]=y;
				if(cnt==n-1) break;
			}
			ans=min(ans,re);
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}