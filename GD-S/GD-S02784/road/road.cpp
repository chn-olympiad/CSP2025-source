#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 3000010
#define M 200010

using namespace std;

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

void write(ll x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}

ll fa[N];
ll n,m,k;
ll num=1;
ll ans;
bool flag[N];
ll be,en;
ll minn=1e18;
ll hc;

inline ll getfa(ll x)
{
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}

inline void merge(ll x,ll y)
{
	fa[getfa(x)]=getfa(y);
}

struct pp
{
	ll from,to,val;
}a[N],b[N];

ll c[12][M];

inline bool rule(pp x,pp y)
{
	return x.val<y.val;
}

inline void init()
{
	n=read();
	m=read();
	k=read();
	for(ll i=1;i<=m;i++)
	{
		a[i].from=read();
		a[i].to=read();
		a[i].val=read();
	}
}

inline void work1()
{
	for(ll i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	sort(a+1,a+m+1,rule);
	for(ll i=1;i<=m;i++)
	{
		if(getfa(a[i].from)!=getfa(a[i].to))
		{
			merge(a[i].from,a[i].to);
			ans+=a[i].val;
			num++;
			if(num==n+k)break;
		}
	}
}

inline void init2()
{
	for(ll i=1;i<=k;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			c[i][j]=read();
		}
	}
}

inline bool check()
{
	ll nflag=1;
	for(ll i=1;i<=k;i++)
	{
		if(c[i][0])nflag=0;
	}
	return nflag;
}

inline void work2()
{
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			a[++m].from=i+n;
			a[m].to=j;
			a[m].val=c[i][j];
		}
	}
	
}

inline void dfs(ll st)
{
	if(st>k)
	{
		ll ans2=check();
		if(ans2<ans||ans==0)ans=ans2;
		return;
	}
	dfs(st+1);
	flag[st]=1;
	dfs(st+1);
}

inline ll getans()
{
	ll va=0,js=0;
	ll nnum=1;
	for(ll i=1;i<=k;i++)
	{
		if(flag[i])
		{
			va+=c[i][0];
			js++;
		}
	}
	hc=m;
	ll t=0;
	for(ll i=1;i<=k;i++)
	{
		if(flag[i])
		{
			t++;
			for(ll j=1;j<=n;j++)
			{
				a[++hc].from=t+n;
				a[hc].to=j;
				a[hc].val=c[i][j];
			}
		}	
	}
	for(ll i=1;i<=hc;i++)
	{
		b[i].from=a[i].from;
		b[i].to=a[i].to;
		b[i].val=a[i].val;
	}
	for(ll i=1;i<=2*n;i++)
	{
		fa[i]=i;
	}
	sort(b+1,b+hc+1,rule);
	for(ll i=1;i<=hc;i++)
	{
		if(getfa(b[i].from)!=getfa(b[i].to))
		{
			merge(b[i].from,b[i].to);
			va+=b[i].val;
			nnum++;
			if(nnum==n+js)break;
		}
	}
	return va;
}

inline void SA()
{
	be=getans();
	for(db tem=1e5;tem>=1e-5;tem*=0.001)
	{
		ll v=rand()%k+1;
		if(flag[v]==1)flag[v]=0;
		else flag[v]=1;
		en=getans();
		ll dt=en-be;
		if((exp(-dt/tem))*1.0>rand()*1.0/32767)be=en;
		minn=min(be,minn);
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	srand(20210501);
	init();
	if(!k)
	{
		work1();
		write(ans);
		return 0;
	}
	else 
	{
		init2();
		if(check())
		{
			work2();
			work1();
			write(ans);
			return 0;
		}
		else 
		{
			while(clock()*1.0/CLOCKS_PER_SEC<0.5)SA();
			write(minn);
			return 0;
		}
	}
	return 0;
}
