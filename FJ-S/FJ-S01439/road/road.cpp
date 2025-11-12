#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e5+10;
int n,m,k;
int u[N];
int v[N];
int w[N];
int c[N];
int a[100][100];
int cnt[100];
bool mark[N];
struct node{
	int w;
	int u,v;
}e[N];
bool cmp(const node &x,const node &y)
{
	return x.w<y.w;
}
int fa[N];
int find(int x)
{
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
int ans=INT_MAX;
void dfs(int o)
{
	if(o>k)
	{
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			e[i].u=u[i];
			e[i].v=v[i];
			e[i].w=w[i];
		}
		for(int i=1;i<=m;i++)
		{
			e[i+m].u=v[i];
			e[i+m].v=u[i];
			e[i+m].w=w[i];
		}
		int len=m+m;
		for(int i=n+1;i<=k+n;i++)if(cnt[i-n])
		{
			for(int j=1;j<=n;j++)
			{
				e[++len].u=i;
				e[len].v=j;
				e[len].w=a[i-n][j];
			}
		}
		for(int i=n+1+n;i<=k+n+n;i++)if(cnt[i-n-n])
		{
			for(int j=1;j<=n;j++)
			{
				e[++len].v=i-n;
				e[len].u=j;
				e[len].w=a[i-n-n][j];
			}
		}
		sort(e+1,e+len+1,cmp);
		int ret=0;
		for(int i=1;i<=len;i++)
		{
			int tx=find(e[i].u);
			int ty=find(e[i].v);
			if(e[i].u>n)
			{
				mark[e[i].u]=true;
			}
			if(e[i].v>n)
			{
				mark[e[i].v]=true;
			}
//			cout<<tx<<" "<<ty<<endl;
			if(tx==ty)
			{
				continue;
			}
			else
			{
				fa[tx]=ty;
//				cout<<e[i].w<<" ";
				ret+=e[i].w;
			}
		}
		for(int i=n+1;i<=n+k;i++)
		{
			if(mark[i])
			{
				ret+=c[i-n];
			}
		}
		ans=min(ans,ret);
		memset(e,0,sizeof(e));
		memset(fa,0,sizeof(fa));
//		cout<<ret<<endl;
		memset(mark,0,sizeof(mark));
		return ;
	}
	cnt[o]=0;
	dfs(o+1);
	cnt[o]=1;
	dfs(o+1);
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
		u[i]=read();
		v[i]=read();
		w[i]=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	dfs(1);
	cout<<ans;
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
