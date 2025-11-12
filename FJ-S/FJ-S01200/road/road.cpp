#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long to;
	long long e;
};
struct edge
{
	long long x;
	long long y;
	long long z;
}p[2000001];
long long n,m,k,f[100001],c[101][100001],gg[3001][3001],e,anss=1e18,vis[11],ggg[3001][3001];
bool cmp (edge zx,edge xy)
{
	return zx.z<xy.z;
}
long long fi (long long q)
{
	if (f[q]==q) return q;
	return f[q]=fi(f[q]);
}
long long tgc ()
{
	long long ansss=0;
	for (int i=1;i<=k;i++)
	{
		if (!vis[i]) continue;
		ansss+=c[i][0];
		for (int j=1;j<=n;j++) for (int l=j+1;l<=n;l++) gg[j][l]=min(gg[j][l],c[i][j]+c[i][l]);
	}
	e=0;
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) 
	{
		e++;
		p[e].x=i,p[e].y=j,p[e].z=gg[i][j];
	}
	long long cnt=0;
	sort(p+1,p+e+1,cmp);
	for (int i=1;i<=m;i++)
	{
		if (fi(p[i].x)==fi(p[i].y)) continue;
		ansss+=p[i].z;
		cnt++;
		f[fi(p[i].x)]=fi(p[i].y);
		if (cnt==n-1)
		{
			for (int i=1;i<=n;i++) f[i]=i;
			for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) gg[i][j]=ggg[i][j];
		 	return ansss;
		}
	}
}
void dfs (int ss)
{
	if (ss==k+1)
	{
		long long xxx=tgc();
		anss=min(anss,xxx);
		return;
	}
	vis[ss]=1;
	dfs(ss+1);
	vis[ss]=0;
	dfs(ss+1);
}
void zxy ()
{
	long long ans=0,cnt=0;
	sort(p+1,p+m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		if (fi(p[i].x)==fi(p[i].y)) continue;
		ans+=p[i].z;
		cnt++;
		f[fi(p[i].x)]=fi(p[i].y);
		if (cnt==n-1)
		{
			cout<<ans;
			exit(0);
		}
	}
}
void zxy1 ()
{
	long long ans=0,cnt=0;
	sort(p+1,p+e+1,cmp);
	for (int i=1;i<=e;i++)
	{
		if (fi(p[i].x)==fi(p[i].y)) continue;
		ans+=p[i].z;
		cnt++;
		f[fi(p[i].x)]=fi(p[i].y);
		if (cnt==n-1)
		{
			for (int i=1;i<=n;i++) f[i]=fi(i);
			cout<<ans;
			exit(0);
		}
	}
}
void sby ()
{
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n;j++) for (int l=j+1;l<=n;l++) gg[j][l]=min(gg[j][l],c[i][j]+c[i][l]);
	}
	e=0;
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) 
	{
		e++;
		p[e].x=i,p[e].y=j,p[e].z=gg[i][j];
	}
	zxy1();
}
void zx ()
{
	dfs(1);
	cout<<anss;
}
int main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) gg[i][j]=ggg[i][j]=2147483647;
	for (int i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		gg[u][v]=w;
		gg[v][u]=w;
		ggg[u][v]=w;
		ggg[v][u]=w;
	}
	if (k==0) zxy();
	for (int i=1;i<=k;i++) for (int j=0;j<=n;j++) cin>>c[i][j];
	int pdd=1;
	for (int i=1;i<=k;i++) if (c[i][0]) pdd=0;
	if (pdd&&n<=1000) sby();
	else zx();
	return 0;
}
