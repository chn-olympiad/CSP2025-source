#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(int(ch)^48);
		ch=getchar();
	}
	return x*f;
}

inline void write(LL x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(char(x%10+48));
}

inline void print(LL x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	write(x);
	puts("");
}

const int N=1e4+20;
const int M=2e6+20;

int n,m,k,c[15],a[N][15];
int fa[N],cnt,ccnt;
bool vis[N];
LL ans;

struct Edge{
	int x,y,z;
	bool operator<(const Edge &A){
		return z<A.z;
	}
}e[M];

int get(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=get(fa[x]);
}

void kruskal()
{
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;++i)
	{
		int fx=get(e[i].x);
		int fy=get(e[i].y);
		if(fx!=fy)
		{
			if(!vis[e[i].x])
			{
				++ccnt;
				vis[e[i].x]=1;
			}
			if(!vis[e[i].y])
			{
				++ccnt;
				vis[e[i].y]=1;
			}
			fa[fx]=fy;
			ans+=e[i].z;
			++cnt;
		}
		if(ccnt==n)
		{
			break;
		}
		if(cnt==n-1)
		{
			break;
		}
	}
	print(ans);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool flag1=1;
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;++i)
	{
		e[i].x=read();
		e[i].y=read();
		e[i].z=read();
	}
	for(int j=1;j<=k;++j)
	{
		c[j]=read();
		if(c[j])
		{
			flag1=0;
		}
		for(int i=1;i<=n;++i)
		{
			a[i][j]=read();
		}
	}
	if(!k)
	{
		sort(e+1,e+m+1);
		kruskal();
		return 0;
	}
	if(flag1)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=k;++j)
			{
				++m;
				e[m].x=i;
				e[m].y=j+n;
				e[m].z=a[i][j];
			}
		}
		n=n+k;
		sort(e+1,e+m+1);
		kruskal();
		return 0;
	}
	sort(e+1,e+m+1);
	kruskal();
	return 0;
}