#include<bits/stdc++.h>
#define ll long long
#define M 1100000
#define N 11000
using namespace std;
int n,m,k,tot;
int u,v,w;
int fa[N];
ll anss=4e18,nd;
ll cst[20];
ll a[20][N];
struct node
{
	ll w;
	int u,v;
	bool operator<(const node &k)const
	{
		return w<k.w;
	}
}t[M],tmp[15][M];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]); 
}
ll kr()
{
	ll ans=0;
	for(int i=1;i<=n+20;i++)
		fa[i]=i;
	sort(t+1,t+tot+1);
	for(int i=1;i<=tot;i++)
		if(find(t[i].u)!=find(t[i].v))
		{
			fa[find(t[i].u)]=find(t[i].v);
			ans+=t[i].w;
		}
	return ans;
}
void dfs(int x)
{
	if(x==k+1)
	{
		anss=min(anss,kr()+nd);
		return;
	}
	for(int i=1;i<=tot;i++)
		tmp[x][i]=t[i];
	dfs(x+1);
	for(int i=1;i<=tot;i++)
		t[i]=tmp[x][i];
	for(int i=1;i<=n;i++)
		t[++tot]={a[x][i],x+n,i};
	nd+=cst[x];
	dfs(x+1);
	tot-=n;
	for(int i=1;i<=tot;i++)
		t[i]=tmp[x][i];
	nd-=cst[x];
}
int read()
{
	char t;
	int ans=0;
	while(!((t=getchar())>='0'&&t<='9'));
	ans=t-'0';
	while((t=getchar())>='0'&&t<='9')
		ans=ans*10+t-'0';
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		u=read();
		v=read();
		w=read();
		t[++tot]={w,u,v};
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		cst[i]=read();
		if(cst[i])
			flag=0;
		bool lflag=0;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
			if(!a[i][j])
				lflag=1;
		}
		flag&=lflag;
	}
	if(flag)
	{
		for(int i=1;i<=k;i++)
		{
			int id;
			for(int j=1;j<=n;j++)
				if(!a[i][j])
					id=j;
			for(int j=1;j<=n;j++)
				if(j!=id)
					t[++tot]={a[i][j],id,j};
		}
		cout<<kr();
		return 0;	
	}
	dfs(1);
	cout<<anss;
	return 0;
}
