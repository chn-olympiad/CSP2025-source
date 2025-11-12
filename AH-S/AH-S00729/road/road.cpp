#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int x=0;
	bool neg=false;
	char c=getchar_unlocked();
	while(c<'0')
	{
		if(c=='-') neg=true;
		c=getchar_unlocked();
	}
	while(c>='0')
	{
		x=x*10+c-'0';
		c=getchar_unlocked();
	}
	if(neg) return -x;
	return x;
}
void write(int x)
{
	if(x<0)
	{
		putchar_unlocked('-');
		write(-x);
		return;
	}
	if(x<=9)
	{
		putchar_unlocked(x+'0');
		return;
	}
	write(x/10);
	putchar_unlocked(x%10+'0');
}
struct R
{
	int ld[10012],sz[10012];
	void init(int n)
	{
		for(int i=1;i<=n;i++)
		{
			ld[i]=i;
			sz[i]=1;
		}
	}
	int want(int x)
	{
		if(ld[x]==x) return x;
		int c=want(ld[x]);
		ld[x]=c;
		return c;
	}
	bool add(int x,int y)
	{
		x=want(x);
		y=want(y);
		if(x==y) return false;
		if(sz[y]>sz[x]) swap(x,y);
		ld[y]=x;
		sz[x]+=sz[y];
		sz[y]=0;
		return true;
	}
};
struct M
{
	int x;
	int y;
	int z;
};
R r;
M e[1000012];
bool cmp(M x,M y)
{
	return x.z<y.z;
}
int c[12];
bool dis[10012];
int get(int n1,int n2)
{
	r.init(n1);
	int lf=n2-1,ans=0,i=1;
	while(lf)
	{
		if(!dis[e[i].x]&&!dis[e[i].y]&&r.add(e[i].x,e[i].y))
		{
			lf--;
			ans+=e[i].z;
		}
		i++;
	}
	return ans;
}
int search(int u,int v,int w,int n)
{
	if(u>v) return get(n+v,n+w);
	dis[u+n]=false;
	int ans=c[u]+search(u+1,v,w+1,n);
	dis[u+n]=true;
	ans=min(ans,search(u+1,v,w,n));
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	while(T--)
	{
		int n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
			e[i]=(M){read(),read(),read()};
		sort(e+1,e+m+1,cmp);
		r.init(n);
		for(int i=1;i<=m;i++)
			if(!r.add(e[i].x,e[i].y)) e[i].z=1e18;
		sort(e+1,e+m+1,cmp);
		while(e[m].z>1e17)
		{
			e[m]=(M){0,0,0};
			m--;
		}
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				m++;
				e[m]=(M){n+i,j,read()};
			}
		}
		sort(e+1,e+m+1,cmp);
		write(search(1,k,0,n));
		putchar_unlocked('\n');
	}
	return 0;
}
// 14:45 - 15:25, samples passed (663 ms), extra hack passed (719 ms), 100 / 100 points
