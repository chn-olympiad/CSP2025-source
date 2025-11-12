#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,mf[15],c[15],w[15][10005],i,j,x,y,fa[10005],ans,cnt;
bool aaa=true;
struct edge{
	ll x,y,v;
}g[2000005];
bool cmp(edge a,edge b){return a.v<b.v;}
ll fid(ll id)
{
	if(fa[id]==id) return id;
	fa[id]=fid(fa[id]);
	return fa[id];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++) cin>>g[i].x>>g[i].y>>g[i].v;
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(j=1;j<=n;j++)
		{
			cin>>w[i][j];
			if(w[i][j]==0) mf[i]=j;
		}
		if(c[i]>0||mf[i]==0) aaa=false;
	}
	for(i=1;i<=n;i++) fa[i]=i;
	if(aaa) for(i=1;i<=k;i++) for(j=1;j<=n;j++) if(mf[i]!=j)
	{
		m++;
		g[m].x=mf[i];
		g[m].y=j;
		g[m].v=w[i][j];
	}
	sort(g+1,g+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		x=fid(g[i].x); y=fid(g[i].y);
		if(x==y) continue;
		fa[x]=y;
		cnt++;
		ans+=g[i].v;
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
