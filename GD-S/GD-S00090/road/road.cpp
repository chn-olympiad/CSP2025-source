#include<bits/stdc++.h>
using namespace std;
//#define int long long <----------------------
int n,m,k;
int N;
struct node
{
	int u,v;
	long long w;
}p[2000001];
/*struct nodee
{
	int c,a[10001];
}xw[11];*/
int cnt;
int fa[10100];
long long ans;
int find(int x)
{
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
bool add(int x,int y)
{
	int xx=find(x);
	int yy=find(y);
	if(xx==yy) return 0;
	if(xx>yy) swap(xx,yy);
	fa[yy]=xx;
	return 1;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
/*bool cmpp(nodee x,nodee y)
{
	return x.c<y.c;
}*/
long long kur(int n)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	int c=n;
	//int c=N;
	sort(p+1,p+1+cnt,cmp);
	long long ret=0;
	for(int i=1;i<=cnt;i++)
	{
		int u=p[i].u;
		int v=p[i].v;
		long long w=p[i].w;
		if(add(u,v))
		{
			//if(find(u)<=N&&find(v)<=N) c--;
			c--;
			ret+=w;
			if(c==1) return ret;
		}
	}
	return ret;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	N=n;
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		p[++cnt]={u,v,w};
	}
	ans=kur(n);
	/*for(int i=1;i<=k;i++)
	{
		cin>>xw[i].c;
		for(int j=1;j<=m;j++)
		{
			cin>>xw[i].a[j];
		}
	}
	sort(xw+1,xw+1+k,cmpp);*/
	int q=n;
	for(int i=1;i<=k;i++)
	{
		//int c=xw[i].c;
		long long c; cin>>c;
		if(c>ans) return cout<<ans,0;
		q++;
		for(int j=1;j<=n;j++)
		{
			//int x=xw[i].a[j];
			int x; cin>>x;
			p[++cnt]={q,j,x};
		}
		ans=min(ans,kur(q)+c);
	}
	cout<<ans;
	return 0;
}
/*

shen shou bao you

*/
