#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline int read()
{
	int x=0,r=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') r=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*r;
}

int n,m,k;

int f[20005];

int go(int t)
{
	if(f[t]==t) return t;
	return f[t]=go(f[t]);
}

struct ro
{
	signed u,v,l;
} a[1000005],b[100005];

int c[15][10005];

int merge(int x,int y)
{
	x=go(x),y=go(y);
	if(x==y) return 0;
	f[x]=y;
	return 1;
}

int nw;

bool cmp(ro a,ro b)
{
	return a.l<b.l;
}

ll check(int d)
{
	for(int i=1;i<=n;i++) f[i]=i;
	nw=0;
	int all=n;
	ll cnt=0;
	for(int i=1;i<=k;i++)
	{
		if((d>>(i-1))&1)
		{
			all++;
			f[n+i]=n+i;
			cnt+=c[i][0];
			for(int j=1;j<=n;j++)
			{
				b[++nw].u=n+i;
				b[nw].v=j;
				b[nw].l=c[i][j];
			}
		}
	}
	sort(b+1,b+nw+1,cmp);
	int l1=1,l2=1;
	while(all!=1)
	{
		if(l1>m)
		{
			if(merge(b[l2].v,b[l2].u))
			{
				all--;
				cnt+=b[l2].l;
			}
			l2++;
		}
		else if(l2>nw)
		{
			if(merge(a[l1].u,a[l1].v))
			{
				all--;
				cnt+=a[l1].l;
			}
			l1++;
		}
		else
		{
			if(a[l1].l<=b[l2].l)
			{
				if(merge(a[l1].u,a[l1].v))
				{
					all--;
					cnt+=a[l1].l;
				}
				l1++;
			}
			else
			{
				if(merge(b[l2].v,b[l2].u))
				{
					all--;
					cnt+=b[l2].l;
				}
				l2++;
			}
		}
	}
	return cnt;
}

void work()
{
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		a[i].u=read();
		a[i].v=read();
		a[i].l=read();
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			c[i][j]=read();
		}
	}
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<(1<<k);i++)
	{
		ans=min(ans,check(i));
	}
	printf("%lld\n",ans);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	//T=read();
	while(T--) work();
	return 0;
}
