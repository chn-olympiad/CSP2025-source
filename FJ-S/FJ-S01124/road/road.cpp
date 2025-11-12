#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5;
struct node{
	int u,v;
	ll w,net;
} q[M+10*N];
int n,m,k,head[N],tot=0,fa[N+15];
ll c[15][N];
void add(int u,int v,ll w)
{
	q[++tot].u=u;
	q[tot].v=v;
	q[tot].w=w;
	q[tot].net=head[u];
	head[u]=tot;
}
ll find(ll x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int operator<(node a,node b)
{
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
	}
	int flag=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			scanf("%lld",&c[i][j]);
		}
		if(c[i][0]) 
		{
			flag=1;
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0)
	{
		int cnt=0;
		ll ans=0;
		sort(q+1,q+tot+1);
		for(int i=1;i<=tot;i++)
		{
			ll u=find(q[i].u),v=find(q[i].v),w=q[i].w;
			if(u==v) continue;
			cnt++;
			fa[u]=v;
			ans+=w;
			if(cnt==n-1) break;
		}		
		cout << ans;
		return 0;
	}
	if(!flag)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				add(i+n,j,c[i][j]);
			}
		}
		for(int i=n+1;i<=n+k;i++) fa[i]=i;
		sort(q+1,q+tot+1);
		int cnt=0;
		ll ans=0;
		for(int i=1;i<=tot;i++)
		{
			ll u=find(q[i].u),v=find(q[i].v),w=q[i].w;
			if(u==v) continue;
			cnt++;
			fa[u]=v;
			ans+=w;
			if(cnt==n+k-1) break;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
