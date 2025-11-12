#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+15,M=2e6+15;
int n,m,k;
int f[N],c[20],t[20][N];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
struct node{
	int u,v;
	int s;
}g[N*2],wo[M];
int cntn,cntm;
ll ans=0;
bool cmp(node x,node y)
{
	return x.s<y.s;
}
void kru1()
{
	sort(wo+1,wo+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=find(wo[i].u),y=find(wo[i].v);
		if(x!=y)
		{
			f[x]=y;
			ans+=wo[i].s;
			g[++cntm]=wo[i];
		}
	}
}
bool p[13];
void kru()
{
	sort(g+1,g+1+cntm,cmp);
	for(int i=1;i<=cntm;i++)
	{
		int x=find(g[i].u),y=find(g[i].v);
		if(x!=y)
		{
			f[x]=y;
			ans+=g[i].s;
		}
	}
}
void get()
{
	for(int i=1;i<=n+k*2;i++) f[i]=i;
	for(int i=1;i<=cntm;i++) g[i]=wo[i];
	ll res=ans;
	ans=0;
	int s1=0;
	for(int i=1;i<=k;i++)
	{
		if(p[i])
		{
			s1++;
			cntn+=2;
			g[++cntm].u=cntn;
			g[cntm].v=cntn-1;
			g[cntm].s=c[i];
			for(int j=1;j<=n;j++)
			{
				g[++cntm].s=t[i][j];
				g[cntm].u=j;
				g[cntm].v=cntn;
			}
		}
	}
	kru();
	ans=min(ans,res);
	cntm-=(n+1)*s1;
	cntn-=2*s1;
}
void dfs(int x)
{
	if(x==k+1)
	{
		get();
		return;
	}
	p[x]=1;
	dfs(x+1);
	p[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	cntn=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&wo[i].u,&wo[i].v,&wo[i].s);
	}
	for(int j=1;j<=n+k*2;j++) f[j]=j;
	kru1();
	for(int i=1;i<=cntm;i++) wo[i]=g[i];
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&t[i][j]);
		}
	}	
	dfs(1);
	printf("%lld\n",ans);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/