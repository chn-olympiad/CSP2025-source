#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 300030

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

struct pp
{
	ll num;
	bool st[4];
}
d[N];

ll T,n;
ll a[N],b[N],c[N];
ll sum;
ll na,nb,nc;
ll h[N];
bool flag[N][4];

inline void clear()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	sum=0;
	na=nb=nc=0;
}

inline void init()
{
	n=read();
	for(ll i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=read();
		c[i]=read();
		h[1]=a[i];
		h[2]=b[i];
		h[3]=c[i];
		sort(h+1,h+3+1);
		d[i].num=h[3]-h[2];
		if(d[i].num==a[i]-b[i]||d[i].num==a[i]-c[i])d[i].st[1]=1;
		if(d[i].num==b[i]-a[i]||d[i].num==b[i]-c[i])d[i].st[2]=1;
		if(d[i].num==c[i]-b[i]||d[i].num==c[i]-a[i])d[i].st[3]=1;
	}
}

inline void gm()
{
	for(ll i=1;i<=n;i++)
	{
		if(a[i]>=b[i]&&a[i]>=c[i])
		{
			sum+=a[i];
			na++;
		}
		else if(b[i]>=a[i]&&b[i]>=c[i])
		{
			sum+=b[i];
			nb++;
		}
		else
		{
			sum+=c[i];
			nc++;
		}
	}
}

bool rule(pp x,pp y)
{
	return x.num<y.num;
}

inline void tj()
{
	ll bd=max(max(na,nb),nc)-n/2;
	sort(d+1,d+n+1,rule);
//	cout<<d[1].num;
	for(ll i=1;i<=bd;i++)
	{
		if(na>n/2)
		{
			if(d[i].st[1])sum-=d[i].num;
			else 
			{
				bd++;
				continue;
			}
		}
		else if(nb>n/2)
		{
			if(d[i].st[2])sum-=d[i].num;
			else 
			{
				bd++;
				continue;
			}
		}
		else if(nc>n/2)
		{
			if(d[i].st[3])sum-=d[i].num;
			else 
			{
				bd++;
				continue;
			}
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		clear();
		init();
		gm();
		if(na>n/2||nb>n/2||nc>n/2)tj();
		write(sum);
		putchar('\n');
	}
	return 0;
}
