#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct EDGE
{
	int l,r;
	int w;
	friend bool operator<(EDGE xx,EDGE yy)
	{
		return xx.w<yy.w;
	}
}tree[N*20];
int vis[N*20];
int c[N*2];
int num=0;
int n,m,k;
int fa[N*2];
int du[N*2];
queue<EDGE> q;
int find(int x)
{
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int l,r,w;
		scanf("%d%d%d",&l,&r,&w);
		tree[++num]={l,r,w};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			tree[++num]={i+n,j,x};
		}
	}
	sort(tree+1,tree+1+num);
	for(int i=1;i<=n+m;i++) fa[i]=i;
	long long cnt=0;
	for(int i=1;i<=num;i++)
	{
		int f1=find(tree[i].l),f2=find(tree[i].r);
		if(f1!=f2)
		{
			fa[f1]=f2;
			du[tree[i].l]++;
			du[tree[i].r]++;
			q.push(tree[i]);
			cnt+=tree[i].w;
		}
	}
	while(!q.empty())
	{
		EDGE tmp=q.front();
		q.pop();
		if(tmp.l>n && du[tmp.l]==1) cnt-=tmp.w;
		else cnt+=c[tmp.l-n];
	}
	printf("%lld",cnt);
	return 0; 
}