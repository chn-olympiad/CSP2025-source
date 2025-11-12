#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,kk,ans,cnt,js;
bool f,b[1000006];
int fa[10004];
struct node{
	int u,v,id;
	ll w;
};
node a[3000006];
int head[10004];
void add(int u,int v,ll w,int id){
	a[++cnt].u=head[u];
	a[cnt].v=v;
	a[cnt].w=w;
	a[cnt].id=id;
	head[u]=cnt;
}
ll c[11],k0[11];
ll k[11][10004];
void ss(int u){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	for(int i=head[u];i;i=a[i].u)
	{
		if(a[i].v==u)continue;
		ll w=a[i].w,id=a[i].id;
		q.push(make_pair(w,id));
	}
	if(q.size()){
		ll id=q.top().second;
		if(b[id]==0){
			b[id]=1;
			ans+=q.top().first;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&kk);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		++js;
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w,js);
		add(v,u,w,js);
	}
	for(int i=1;i<=kk;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i])f=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&k[i][j]);
			if(k[i][j]==0)k0[i]=j;
		}
	}
	if(f==0){
		for(int i=1;i<=kk;i++)
		{
			for(int j=1;j<=n;j++)
			{
				++js;
				add(j,k0[i],k[i][j],cnt+1);
				add(k0[i],j,k[i][j],cnt);
			}
		}
	}
	for(int i=1;i<=n;i++)ss(i);
	printf("%lld",ans);
	return 0;
}
