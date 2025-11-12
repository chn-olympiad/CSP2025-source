#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e4+10,M=2e6+10,K=15,Mod=998244353,inf=1e9+10;
int n,m,k,g[K],f[N][K],u[N],p[N],c[N],ans,mn[N],idx;
vector<int> q;
struct ed
{
	int u,v,w;
}e[M];
bool cmp(ed a,ed b)
{
	return a.w<b.w;
}
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res*=x,res%=Mod;
		x*=x,x%=Mod,y>>=1;
	}
	return res;
}
void kru()
{
	sort(e+1,e+idx+1,cmp);
	for(int i=1;i<=idx;i++) if(find(e[i].u)!=find(e[i].v)) ans+=e[i].w,p[find(e[i].u)]=find(e[i].v),q.push_back(i);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(mn,0x3f,sizeof mn);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++) 
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[++idx]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>g[i];
		for(int j=1;j<=n;j++)
		{
			cin>>f[i][j];
			if(!g[i]) e[++idx]={n+i,j,f[i][j]};
			else mn[i]=min(mn[i],f[i][j]);
		}
	}
	kru();
//	cout<<ans<<'\n';
	for(int i=1;i<=k;i++) if(g[i]) 
	{
		int t=g[i],cnt=0;
		for(int x:q) if(e[x].w>min(f[i][e[x].u],f[i][e[x].v])) t-=e[x].w-min(f[i][e[x].u],f[i][e[x].v]),cnt++;
		if(cnt==1) t+=mn[i];
		if(t<0)
		{
			ans+=t;	
			for(int x:q) if(e[x].w>min(f[i][e[x].u],f[i][e[x].v])) e[x].w=min(f[i][e[x].u],f[i][e[x].v]),cnt++;
		}
	}
	cout<<ans;
	return 0;
}