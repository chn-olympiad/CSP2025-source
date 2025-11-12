#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

inline int read()
{
	int x=0,fu=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fu;
}
void write(int x)
{
	if(x<0){putchar('-'),x=-x;}
	if(x<10){putchar(x+'0');return;}
	write(x/10);putchar(x%10+'0');
}

const int N=1e4+50,inf=1e15;
int n,m,k;
int ans,res,tot;
int d[N];
bool vis[N],sg[N];
vector<pii>ed[N];
void prim()
{
	for(int i=1;i<=n+k;i++)	d[i]=inf,sg[i]=0;
	res=0;
	d[1]=0;
	for(int i=1;i<=n+k;i++)
	{
		int id=-1;
		for(int j=1;j<=n+k;j++)
		{
			if(!sg[j]&&!vis[j]&&(id==-1||d[j]<d[id]))	id=j;
		}
		if(id==-1)	break;
		res+=d[id];
		sg[id]=true;
		for(pii v:ed[id])
		{
			if(vis[v.fi]||sg[v.fi])	continue;
			d[v.fi]=min(d[v.fi],v.se);
		}
	}
}
namespace case1
{
	static int val[12];
	void solve()
	{
		prim();
		ans=res;
		for(int i=1;i<=k;i++)
		{
			val[i]=read();
			for(int j=1;j<=n;j++)
			{
				int x=read();
				ed[n+i].push_back({j,x}),ed[j].push_back({n+i,x});
			}
		}
		for(int s=1;s<(1<<k);s++)
		{
			int qwq=0;
			for(int i=1;i<=k;i++)
			{
				if((s>>i-1)&1)
				{
					qwq+=val[i];
					vis[n+i]=false;
				}
				else	vis[n+i]=true;
			}
			prim();
			if(ans>res+qwq)	ans=res+qwq;
		}
	}
}
namespace case2
{
	static int a[N];
	void solve()
	{
		prim();
		ans=res;
		int lst=0;
		for(int i=1;i<=k;i++)
		{
			int val=read();
			vis[n+i]=false;
			tot++;
			for(int j=1;j<=n;j++)	a[j]=read(),ed[n+i].push_back({j,a[j]}),ed[j].push_back({n+i,a[j]});
			prim();
	//		cout<<"qwq\n";
			if(ans>res+lst+val)	ans=res+lst+val,lst+=val;
			else	tot--,vis[n+i]=true;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),e=read();
		ed[u].push_back({v,e}),ed[v].push_back({u,e});
	}
	for(int i=1;i<=k;i++)	vis[n+i]=true;
	if((1<<k)*n*n<2e8)	case1::solve();
	else	case2::solve();
	write(ans);
	return 0;
}