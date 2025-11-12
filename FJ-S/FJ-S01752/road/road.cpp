#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+1,M=2e6+1,MOD=0,inf=0x3f3f3f3f;
struct u{int a,b,c;}g[M],G[M];int r[20],w[20][N],fa[N];
bool cmp(u a,u b) {return a.c<b.c;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int kru(int n,int m)
{
	sort(g+1,g+1+m,cmp);int e=0,l=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a=g[i].a,b=g[i].b,c=g[i].c;
		if(find(a)!=find(b)) fa[fa[a]]=fa[b],e+=c,l++;
		if(l==n-1) break;
	}
	return e;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,rr=1;cin>>n>>m>>k;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&g[i].a,&g[i].b,&g[i].c);
	for(int i=1;i<=k;i++)
	{
		cin>>r[i];int pp=0;
		if(r[i]) rr=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&w[i][j]);
			if(!w[i][j]) pp=1;
		}
		if(!pp) rr=0;
	}
	if(rr)
	{
		for(int i=1;i<=k;i++)
		{
			int p=0;
			for(int j=1;j<=n;j++)
				if(!w[i][j]) p=j;
			for(int k=1;k<=n;k++)
				if(k!=p) g[++m]=u({p,k,w[i][k]});
		}
		cout<<kru(n,m)<<endl;return 0;
	}
	int e=inf;
	for(int S=0;S<(1<<k);S++)
	{
		int f=n,q=m,tt=0;
		for(int i=1;i<=m;i++) G[i]=g[i];
		for(int i=1;i<=k;i++)
		{
			if(S&(1<<(i-1)))
			{
				f++;tt+=r[i];
				for(int j=1;j<=n;j++) g[++q]=u({f,j,w[i][j]});
			}
		}
		e=min(e,tt+kru(f,q));
		for(int i=1;i<=m;i++) g[i]=G[i];
	}
	cout<<e<<endl;
	return 0;
}
