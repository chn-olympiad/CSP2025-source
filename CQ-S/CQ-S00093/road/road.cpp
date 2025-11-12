#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+7,maxm=1e6+7;
ll n,m,k,ans,p[maxn],c[17],a[17][maxn],maxt,cx;
struct edge
{
	ll u,v,t;
}e[2*maxm+10*maxn],e1[maxm];
int Find(ll x)
{
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}
bool cmp(edge a,edge b)
{
	return a.t<b.t;
}
int Kruskal(ll mm)
{
	for(int i=1;i<=n;i++) p[i]=i;
	ll sum=0;
	sort(e+1,e+mm+1,cmp);
	for(ll i=1;i<=mm;i++)
	{
		ll pu=Find(e[i].u),pv=Find(e[i].v);
		if(pu!=pv)
		{
			p[pu]=pv;
			sum+=e[i].t;
		}
	}
	return sum;
}
void dfs(int x,ll cnt) // 第 x 次改造 
{
	if(cx>=1e3) return;
	if(x>k) return;
	ll ks=Kruskal(m+cnt);
	if(ks>ans) return;
	ans=min(ans,ks);
	for(int i=1;i<=n;i++) // 对第 i 个城市改造 
	{
		if(c[x]>maxt) continue;
		cx++;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			cx++;
			e[m+cnt].u=i,e[m+cnt].v=j,e[m+cnt].t=a[x][j]+c[x];
		}
		dfs(x+1,cnt+n+1);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].t,maxt=max(maxt,e[i].t);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}	
	ans=Kruskal(m);	
	if(k==0)
	{
		cout<<ans;
		return 0;
	} 
	dfs(1,1);	
	cout<<ans; 
	return 0;
}
/*



*/
