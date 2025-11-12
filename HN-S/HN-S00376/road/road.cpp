/*
15:20 1~4
15:35 go to others
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IN "road.in"
#define OUT "road.out"
//#define DEBUG
const int maxn=1e4+5;
const int maxm=1e6+5;

#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

ll read()
{
	ll ans=0,flag=1;
	char c=gc();
	while(c<'0'||c>'9')
	{
		if(c=='-')flag=-1;
		c=gc();
	}
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-'0';
		c=gc();
	}
	return ans*flag;
}

struct edge
{
	int u;
	int v;
	ll val;
	
	friend bool operator <(edge a,edge b)
	{
		return a.val<b.val;
	}
};
edge e[maxm];
int cnt=0;

void adde(int u,int v,ll val)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
}

ll arr[maxn][maxn];

int fa[maxn];
int sz[maxn];
int crr[maxn];

inline void init(int len)
{
	for(int i=1;i<=len;i++)
	{
		fa[i]=i;
		sz[i]=1;
	}
}

int find(int x)
{
	if(fa[x]==x)return fa[x];
	else return fa[x]=find(fa[x]);
}

bool merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return false;
	if(sz[x]>sz[y])swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
	return true;
}

int main()
{
	#ifndef DEBUG
	freopen(IN,"r",stdin);
	freopen(OUT,"w",stdout);
	freopen("roaderr.txt","w",stderr);
	#endif
	int n=read(),m=read(),k=read(),flag=0,flaga=1;
	ll res=0;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		adde(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		crr[i]=read();
		if(crr[i])flaga=0;
		for(int j=1;j<=n;j++)arr[i][j]=read();
	}
	init(n);
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(merge(e[i].u,e[i].v)==true)
		{
			n--;
			res+=e[i].val;
			if(n==1)
			{
				flag=1;
				cout<<res;
				break;
			}
		}
	}
	if(!flag)
	{
		cout<<"orz";
	}
	return 0;
}
