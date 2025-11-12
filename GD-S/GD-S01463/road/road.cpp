#include<bits/stdc++.h>

namespace LHY
{

using namespace std;

#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mtp make_tuple
#define fi first
#define se second
#define debug cerr<<"now is:"<<__FUNCTION__<<" on line "<<__LINE__<<'\n'

using LL = long long;
using LD = long double;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;

const int N=2000010,M=40010;

const LL inf=0x3f3f3f3f3f3f3f3fll;

int n,m,k,l;

LL arr[20][M],val[20];

struct side
{
	int x,y;
	LL v;	
	int id;
	
	bool operator < (side oth) const
	{
		return v < oth.v;
	}
}e[N],f[N];

struct my_BCJ
{
	int fa[N];
	
	int bcj(int x)
	{
		if(x==fa[x]) return x;
		return fa[x]=bcj(fa[x]);
	}
	
	bool check(int x,int y)
	{
		return bcj(x)==bcj(y);
	}
	
	void merge(int x,int y)
	{
		fa[bcj(x)]=bcj(y);
	}
	
	void build(int n)
	{
		rep(i,1,n) fa[i]=i;
	}
}B;

namespace fast_read
{
	const int S=(1<<20);
	
	char buf[S],*p1,*p2;
	
	#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,S,stdin),p1==p2)?EOF:*p1++)
	
	LL read()
	{
		LL x=0,f=1,c=nc();
		while(c<48||c>57) 
		{
			if(c=='-')
			{
				f=-1;
			}
			c=nc();
		}
		while(c>=48&&c<=57)
		{
			x=(x<<3)+(x<<1)+c-48;
			c=nc();
		}
		return x*f;
	}
}using fast_read::read;

void solve()
{
//	cin>>n>>m>>k;
	n=read();
	m=read();
	k=read();
	rep(i,1,m)
	{
//		cin>>e[i].x>>e[i].y>>e[i].v;
		e[i].x=read();
		e[i].y=read();
		e[i].v=read();
	}
	rep(i,0,k-1)
	{
//		cin>>val[i];
		val[i]=read();
//		rep(j,1,n) cin>>arr[i][j];
		rep(j,1,n) arr[i][j]=read();
	}
	sort(e+1,e+m+1);
	B.build(n+k);
	l=0;
	rep(i,1,m)
	{
		if(!B.check(e[i].x,e[i].y))
		{
			B.merge(e[i].x,e[i].y);
//			cerr<<e[i].x<<' '<<e[i].y<<'\n';
			f[++l]=e[i];
			f[l].id=-1;
		}
	}
//	if(l!=n-1)
//	{
//		cerr<<"w-----\n";
//	}
	B.build(n+k);
	/*
	arr 的不可以剪枝 
	*/
	rep(i,0,k-1)
	{
		rep(j,1,n)
		{
			++l;
			f[l].x=n+i+1;
			f[l].y=j;
			f[l].v=arr[i][j];
			f[l].id=i;
		}
	}
	sort(f+1,f+l+1);
	/*
	rep(i,1,l)
	{
		cerr<<f[i].x<<' ';
		cerr<<f[i].y<<' ';
		cerr<<f[i].v<<' ';
		cerr<<f[i].id<<'\n';
	}
	*/
	LL ans=inf;
	
	rep(S,0,(1<<k)-1)
	{
		LL cnt=0;
		
		B.build(n+k);
		
		rep(i,1,l)
		{
			if(f[i].id==-1)
			{
				if(!B.check(f[i].x,f[i].y))
				{
					B.merge(f[i].x,f[i].y);
					cnt+=f[i].v;
				}
			}
			else if((1<<f[i].id)&S)
			{
				if(!B.check(f[i].x,f[i].y))
				{
					B.merge(f[i].x,f[i].y);
					cnt+=f[i].v;
				}
			}
		}
		rep(j,0,k-1)
		{
			if(S&(1<<j)) cnt+=val[j];
		}
		ans=min(ans,cnt);
	}
	
	cout<<ans<<'\n';
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
//	ios::sync_with_stdio(false),cin.tie(nullptr);
	
	solve();
	
	return 0;
}

}

int main()
{
	return LHY::main();
}
