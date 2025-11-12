#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;int ch=gc();
	for(;!isdigit(ch);)ch=gc();
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
}

//
const int N=1e4+12+12,M=1.5e6+12,K=12,inf=1e18;
int n,m,k,c[K],a[K][N],st,ans,eans=inf,f[N],sz[N],fl;
struct node{
	int u,v,w;
	bool operator<(const node&oth)const
	{
		return w>oth.w;
	} 
}e[M];
priority_queue<node>fir,q;
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]); 
}
void U(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return;
	f[x]=y;
	sz[y]+=sz[x];
}
int calc(int s)
{
//	cout<<"!";
	int res=0,cnt;
	rep(i,1,n+k)f[i]=i,sz[i]=1;
	q=fir;
	rep(i,1,k)if(s&(1<<i-1))
	{
		cnt++;
		res+=c[i];
		if(res>eans)return inf;
		rep(j,1,n)
			q.push((node){i+n,j,a[i][j]});
	}
	while(!q.empty())
	{
		int u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		if(find(u)!=find(v))
		{
			res+=w;
			U(u,v);
		}
		if(sz[find(u)]==n+cnt)break;
		if(res>eans)return inf;
	}
	return res;
}
void solve()
{
	st=(1<<k)-1;
	if(fl==0)eans=min(eans,calc(st));
	else
	{
		rep(s,0,st)eans=min(eans,calc(s));
	}
	cout<<eans;
	exit(0);
}
signed main()
{
//	cin.tie(0)->sync_with_stdio(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	rep(i,1,m)
	{
		read(e[i].u),read(e[i].v),read(e[i].w);
		fir.push(e[i]); 
	}
	rep(i,1,k)
	{
		read(c[i]);fl|=c[i];
		rep(j,1,n)read(a[i][j]),fl|=a[i][j];
	}
	solve();
	return 0;
}