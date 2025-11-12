#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100,M=2e6+10;
int n,m,k,ls,fa[N],c[11],rout[11][N];ll ans=1ll<<60;
bool ch[11];
struct edge{
	int st,ed,val;
}s[M],rs[M];
bool cmp(edge aa,edge bb) {return aa.val<bb.val;}
int find(int x) {return fa[x]!=x?fa[x]=find(fa[x]):x;}
void kru()
{
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=s[i].st,v=s[i].ed;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		s[++ls]=s[i],fa[fv]=fu;
	}
}
ll solve()
{
	ll sum=0;
	ls=n-1;
	for(int i=1;i<=n-1;i++) rs[i]=s[i];
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		if(!ch[i]) continue;
		sum+=c[i];
		for(int j=1;j<=n;j++)
		  rs[++ls]=(edge){n+i,j,rout[i][j]};
	}
	sort(rs+1,rs+1+ls,cmp);
	for(int i=1;i<=ls;i++)
	{
		int u=rs[i].st,v=rs[i].ed,val=rs[i].val;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		fa[fv]=fu,sum+=val;
	}
	return sum;
}
void dfs(int x)
{
	if(x>k)
	{
		ans=min(ans,solve());
		return;
	}
	ch[x]=0;dfs(x+1);
	ch[x]=1;dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		s[i]=(edge){u,v,w};
	}
	kru();
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&rout[i][j]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}
