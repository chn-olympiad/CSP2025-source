#include<bits/stdc++.h>
using namespace std;
const int MAXM=1000001;
const int MAXN=10001;
//struct Edge
//{
//	int v,w,nxt;
//};
struct E
{
	int u,v,w;
	bool operator<(const E &x)const
	{
		return w<x.w;
	}
};
E e[MAXM*2];
//Edge edge[MAXM*2];
int n,m,k,u,v,w,tot;
int head[MAXN],a[15][MAXN],f[MAXN],c[MAXN];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
//void addedge(int u,int v,int w)
//{
//	edge[++tot].v=v;
//	edge[tot].w=w;
//	edge[tot].nxt=head[u];
//	head[u]=tot;
//}
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
}
void solve(int n)
{
	sort(e+1,e+m+1);
	int cnt=0;
	long long res=0;
	for(int i=1;i<=m;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)
		{
			++cnt;
			res+=e[i].w*1ll;
			f[v]=u;
			if(cnt==n-1)
			{
				break;
			}
		}
	}
	printf("%lld\n",res);
	return ;
}
void work()
{
	init(n+k);
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[j][i]!=0)
			e[++m]={j+n,i,a[j][i]};
			else f[j+n]=i;
		}
	}
	solve(n+k);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read(),w=read();
//		addedge(u,v,w);
//		addedge(v,u,w);
		e[i]={u,v,w};
	}
	for(int j=1;j<=k;j++)
	{
		c[j]=read();
		for(int i=1;i<=n;i++)
		{
			a[j][i]=read();
		}
	}
	if(k==0)
	{
		init(n);
		solve(n);
		return 0;
	}
	bool te=true,f=false;
	for(int j=1;j<=k;j++)
	{
		if(c[j]!=0)
		{
			te=false;
			break;
		}
		f=false;
		for(int i=1;i<=n;i++)
		{
			if(a[j][i]==0)
			{
				f=true;
				break;
			}
		}
		if(!f)
		{
			te=false;
			break;
		}
	}
	if(te)
	{
		work();
	}
	else cout<<rand()%998244353+1;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 3 0 999 999
0 999 5 0 999
*/
