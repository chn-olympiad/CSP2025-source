#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e4+100,MAXM=2e6+100;
const ll INF=1e18;
int n,m,k;
struct edg{
	int u,v;
	ll w;
	int lab;
	bool operator<(const edg b)const{
		return w<b.w;
	}
}e[MAXM],now[MAXM];
ll a[15][MAXN],pos[15];
ll sum,ans;
int tot,tx,ty,all;
bool vis[15];
int fa[MAXN];
int cnt;
int fin(int x)
{
	return x==fa[x]?x:fa[x]=fin(fa[x]);
}
void toge(int x,int y)
{
	fa[fin(x)]=fin(y);
}
void solve(int x)
{
	cnt=0;sum=0;
	for(int i=1;i<=n+k;++i)fa[i]=i;
	vis[0]=1;
	for(int i=1;i<=k;++i)
	{
		if((x>>(i-1))&1)vis[i]=1,++cnt,sum+=pos[i];
		else vis[i]=0;
	}
	all=n+cnt-1;
	for(int i=1;i<=tot;++i)
	{
		if(!vis[now[i].lab])continue;
		tx=fin(now[i].u);
		ty=fin(now[i].v);
		if(tx==ty)continue;
//		if(x==3)cout<<sta[i].u<<' '<<sta[i].v<<' '<<sta[i].w<<endl;
		sum+=now[i].w;
		toge(tx,ty);
		--all;
		if(!all)break;
	}
//	cout<<x<<' '<<sum<<endl;
	ans=min(ans,sum);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(e+1,e+1+m);
	for(int i=1;i<=m;++i)
	{
		tx=fin(e[i].u),ty=fin(e[i].v);
		if(tx==ty)continue;
		now[++tot]=e[i];
		now[tot].lab=0;
		toge(tx,ty);
		if(tot==n-1)break;
	}
	for(int i=1;i<=k;++i)
	{
		cin>>pos[i];
		for(int j=1;j<=n;++j)
		{
			cin>>a[i][j];
			now[++tot]={n+i,j,a[i][j]};
			now[tot].lab=i;
		}
	}
	ans=INF;
	sort(now+1,now+1+tot);
	for(int i=0;i<(1<<k);++i)solve(i);
	cout<<ans;
	return 0;
}