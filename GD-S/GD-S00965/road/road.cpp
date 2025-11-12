#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

int read()
{
	int x=0,f=1;
	char ch=' ';
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

void prt(ll x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0) putchar('-'),x=-x;
	int stac[20],top=0;
	while (x)
	{
		stac[++top]=x%10;
		x/=10; 
	}
	while (top)
	{
		putchar(stac[top--]^48);
	}
	return;
}

const int maxn=1e4+10,maxm=1e6+10,maxk=10+2;

struct Kru_Edge
{
	int x,y,v,vill;
	bool operator<(Kru_Edge b)const
	{
		return v<b.v;
	}
}edge[maxm*10];

int n,m,k,x,y,z,tot;
ll ans=1e18;
int c[maxk],a[maxk][maxn];
int fa[maxn+maxk],siz[maxn+maxk];

int get(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}

bool SubA=true;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read();m=read();k=read();
	if (k==0)
	{
		for (int i=1;i<=m;i++)
		{
			edge[i]=(Kru_Edge){read(),read(),read(),0};
		}
		for (int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		sort(edge+1,edge+m+1);
		ans=0;
		for (int i=1;i<=m;i++)
		{
			int x=get(edge[i].x),y=get(edge[i].y);
			if (x==y) continue;
			ans+=edge[i].v;
			if (siz[x]>siz[y]) swap(x,y);
			if (siz[x]==siz[y]) siz[y]++;
			fa[x]=y;
		}
		prt(ans);putchar('\n');
		return 0;
	}
	
	for (int i=1;i<=m;i++)
	{
		x=read();y=read();z=read();
		edge[i]=(Kru_Edge){x,y,z,-1};
	}
	tot=m;
	SubA=true;
	for (int j=1;j<=k;j++)
	{
		c[j]=read();
		if (c[j]) SubA=false;
		for (int i=1;i<=n;i++)
		{
			a[j][i]=read();
			edge[++tot]={n+j,i,a[j][i],j};
		}
	}
	sort(edge+1,edge+tot+1);
	
	if (SubA)
	{
		ans=0;
		for (int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		for (int i=1;i<=tot;i++)
		{
			int x=get(edge[i].x),y=get(edge[i].y),vill=edge[i].vill;
			if (x==y) continue;
			ans+=edge[i].v;
			if (siz[x]>siz[y]) swap(x,y);
			if (siz[x]==siz[y]) siz[y]++;
			fa[x]=y;
		}
		prt(ans);putchar('\n');
		return 0;
	}
	
	for (int S=0;S<(1<<k);S++)
	{
		ll tmp=0;
		for (int j=1;j<=k;j++)
		{
			if (S&(1<<(j-1)))
			{
				tmp+=c[j];
			}
		}
		for (int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		for (int i=1;i<=tot;i++)
		{
			int x=get(edge[i].x),y=get(edge[i].y),vill=edge[i].vill;
			if (x==y) continue;
			if (vill==-1||S&(1<<(vill-1)))
			{
				tmp+=edge[i].v;
				if (siz[x]>siz[y]) swap(x,y);
				if (siz[x]==siz[y]) siz[y]++;
				fa[x]=y;
			}
		}
		ans=min(ans,tmp);
	}
	prt(ans);putchar('\n');
	
	return 0;
}
