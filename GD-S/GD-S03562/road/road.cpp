#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edg
{
	int u,v,w;
};
const int MR=1000001,NR=10001,KR=11;
long long ans=9e18;
bool vis[KR];
int n,m,k,c[NR],f[NR],d[KR][NR];
edg e[MR+NR*KR];
bool cmp(edg x,edg y)
{
	return x.w<y.w;
}
int fnd(int x)
{
	if(x==f[x]) return x;
	return f[x]=fnd(f[x]);
}
void updat()
{
	int i,j,cnte=m,cntn=0;
	long long ret=0;
	for(i=1;i<=k;i++)
		if(vis[i])
		{
			ret+=c[i];
			for(j=1;j<=n;j++) e[++cnte]={n+i,j,d[i][j]};
		}
	if(ret>=ans) return;
	for(i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+cnte+1,cmp);
	for(i=1;cntn<n+(cnte-m)/n && i<=cnte;i++)
		if(fnd(e[i].u)!=fnd(e[i].v))
		{
			f[fnd(e[i].v)]=fnd(e[i].u);
			ret+=e[i].w;
			cntn++;
		}
	ans=min(ans,ret);
	return;
}
void dfs(int c)
{
	if(c==k+1)
	{
		updat();
		return;
	}
	dfs(c+1);
	vis[c]=true;
	dfs(c+1);
	vis[c]=false;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,cnt=0;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	bool f=true;
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) f=false;
		for(j=1;j<=n;j++)
		{
			cin>>d[i][j];
			if(d[i][j]!=0) f=false;
		}
	}
	if(f)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
