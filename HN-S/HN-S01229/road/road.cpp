#include<bits/stdc++.h>
#define int long long
#define filein(x) freopen(x".in","r",stdin)
#define fileout(x) freopen(x".out","w",stdout)
using namespace std;
const int N=1e4+13,M=1e6+9;
int fa[N];
int find(int x)
{
	if(fa[x]==x)
	return x;
	return fa[x]=find(fa[x]);
}
struct edge
{
	int l,r,w;
	friend bool operator<(edge i,edge j)
	{
		return i.w<j.w;
	}
}b[M],bb[M],d[13][N],lf[1<<5][N],rf[1<<5][N];
int ltp[1<<5],rtp[1<<5];
int top;
int c[13];
int n,m,k,lm,ans;
void solve(int S,int T)
{
	for(int i=1;i<=n+k;i++)
	fa[i]=i;
	int sum=0,l=1,r=1;
	for(int i=1;i<=lm;i++)
	{
		if((S>>(i-1))&1)
		sum+=c[i];
	}
	for(int i=lm+1;i<=k;i++)
	if((T>>(i-lm-1))&1)
	sum+=c[i];
	// cout<<S<<' '<<T<<'\n';
	// for(int i=1;i<=ltp[S];i++)
	// cout<<lf[S][i].l<<' '<<lf[S][i].r<<' '<<lf[S][i].w<<'\n';
	// for(int i=1;i<=rtp[S];i++)
	// cout<<rf[T][i].l<<' '<<rf[T][i].r<<' '<<rf[T][i].w<<'\n';
	// cout<<'\n';
	while(l<=ltp[S]||r<=rtp[T])
	{
		if(l>ltp[S])
		{
			int x=rf[T][r].l,y=rf[T][r].r;
			r++;
			if(find(x)==find(y))
			continue;
			fa[find(x)]=find(y);
			sum+=rf[T][r-1].w;
			// cout<<x<<' '<<y<<' '<<rf[T][r].w<<'\n';
			continue;
		}
		if(r>rtp[T])
		{
			int x=lf[S][l].l,y=lf[S][l].r;
			l++;
			if(find(x)==find(y))
			continue;
			fa[find(x)]=find(y);
			sum+=lf[S][l-1].w;
			// cout<<x<<' '<<y<<' '<<lf[S][l].w<<'\n';
			continue;
		}
		if(lf[S][l].w<rf[T][r].w)
		{
			int x=lf[S][l].l,y=lf[S][l].r;
			l++;
			if(find(x)==find(y))
			continue;
			fa[find(x)]=find(y);
			sum+=lf[S][l-1].w;
			// cout<<x<<' '<<y<<' '<<lf[S][l].w<<'\n';
			continue;
		}
		else
		{
			int x=rf[T][r].l,y=rf[T][r].r;
			r++;
			if(find(x)==find(y))
			continue;
			fa[find(x)]=find(y);
			sum+=rf[T][r-1].w;
			// cout<<x<<' '<<y<<' '<<rf[T][r].w<<'\n';
			continue;
		}
	}
	// cout<<find(4)<<' '<<find(3)<<'\n';
	// cout<<sum<<'\n';
	ans=min(ans,sum);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	filein("road");
	fileout("road");
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].l>>b[i].r>>b[i].w;
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	int now=0;
	for(int i=1;i<=m;i++)
	{
		int l=b[i].l,r=b[i].r;
		if(find(l)==find(r))
		continue;
		fa[find(l)]=find(r);
		now+=b[i].w;
		bb[++top]=b[i];
	}
	ans=now;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j].w;
			d[i][j].l=i+n;
			d[i][j].r=j;
		}
	}
	lm=k/2;
	for(int S=0;S<(1<<lm);S++)
	{
		int now=0;
		int sum=0;
		for(int i=1;i<=lm;i++)
		{
			if((S>>(i-1))&1)
			{
				sum+=c[i];
				for(int j=1;j<=n;j++)
				b[++now]=d[i][j];
			}
		}
		for(int i=1;i<=top;i++)
		b[++now]=bb[i];
		sort(b+1,b+now+1);
		for(int i=1;i<=n+k;i++)
		fa[i]=i;
		for(int i=1;i<=now;i++)
		{
			int l=b[i].l,r=b[i].r;
			if(find(l)==find(r))
			continue;
			fa[find(l)]=find(r);
			lf[S][++ltp[S]]=b[i];
			sum+=b[i].w;
		}
		ans=min(ans,sum);
	}
	for(int S=0;S<(1<<(k-lm));S++)
	{
		int now=0,sum=0;
		for(int i=lm+1;i<=k;i++)
		{
			if((S>>(i-lm-1))&1)
			{
				sum+=c[i];
				for(int j=1;j<=n;j++)
				b[++now]=d[i][j];
			}
		}
		for(int i=1;i<=top;i++)
		b[++now]=bb[i];
		sort(b+1,b+now+1);
		for(int i=1;i<=n+k;i++)
		fa[i]=i;
		for(int i=1;i<=now;i++)
		{
			int l=b[i].l,r=b[i].r;
			if(find(l)==find(r))
			continue;
			fa[find(l)]=find(r);
			sum+=b[i].w;
			rf[S][++rtp[S]]=b[i];
		}
		ans=min(ans,sum);
	}
	for(int S=0;S<(1<<lm);S++)
	{
		for(int T=0;T<(1<<(k-lm));T++)
		{
			solve(S,T);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
路多了导致的
*/