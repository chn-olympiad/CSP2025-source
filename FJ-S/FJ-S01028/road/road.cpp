#include<bits/stdc++.h>
#define MAXN 10015
#define MAXM 1000005
#define fir first
#define sec second
#define ll long long
#define pb push_back
using namespace std;
const ll inf=1e16;
int read()
{
	int ret=0,sgn=0,ch=getchar();
	while(!isdigit(ch)) sgn|=ch=='-',ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn ? -ret:ret;
}
int n,N[15],m,k,c[15];
vector<pair<int,int> > a[15];
bool ok[MAXN];
int fa[MAXN];
//mutiset<int> s[15];
ll g[15];
struct edge
{
	int u,v,w;
	friend bool operator<(const edge &x,const edge &y)
	{
		return x.w<y.w;
	}
}e[MAXM];
int fd(int x)
{
	return x==fa[x] ? x:fa[x]=fd(fa[x]);
}
//void doit()
//{
//	for (int i=1;i<=k;i++)
//	{
//		for (int j=1;j<=n;j++)
//		  if (a[i][j]==0)
//		  {
//		  	for (int d=1;d<=n;d++) if (d!=j) e[++m]={j,d,a[i][d],i};
//		  }
////		cout<<endl;
//	}
//}
ll doit(int s)
{
	ll res=0;int cnt=0;
	for (int i=1;i<=n+k;i++) fa[i]=i;
	for (int i=1;i<=k;i++)
	{
		N[i]=1;
		if ((s>>(i-1))&1)
	    {
//	    	cout<<i<<" ";
	  		int u=a[i][0].sec,v=n+i;
	  		u=fd(u),v=fd(v);
	  		fa[v]=u;
	  		res+=c[i]+a[i][0].fir;
	    }
	}
//	cout<<res<<endl;
	int I=1;
	while(cnt<n-1)
	{
		ll f=e[I].w,id=0;int u=e[I].u,v=e[I].v;
//		cout<<I<<" "<<u<<" "<<v<<endl;
		for (int i=1;i<=k;i++)
		  if (((s>>(i-1))&1)&&N[i]<n&&(f>a[i][N[i]].fir))
		  {
		  	f=a[i][N[i]].fir,u=n+i,v=a[i][N[i]].sec,id=i;
		  }
//		cout<<I<<" "<<u<<" "<<v<<endl;
		u=fd(u),v=fd(v);
		if (id) N[id]++;else I++;
		if (u==v) continue;
		cnt++,res+=f;
		fa[v]=u;
	}
	return res;
}
void solve()
{
	n=read(),m=read(),k=read();
//	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	for (int i=1;i<=k;i++)
	{
		c[i]=read();a[i].clear();
		for (int j=1;j<=n;j++)
		{
			int x=read();
			a[i].pb({x,j}),g[i]+=x;
		}
		sort(a[i].begin(),a[i].end());
//		for (int j=0;j<a[i].size();j++) cout<<a[i][j].fir<<" "<<a[i][j].sec<<endl;
//		cout<<endl;
	}
	sort(e+1,e+m+1);
	
	ll ans=inf;int Max=(1<<k)-1;
//	cout<<Max<<endl;
	for (int i=0;i<=Max;i++)
	{
//		cout<<"i="<<i<<endl;
		ans=min(ans,doit(i));
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	for (int i=1;i<=T;i++) solve();
	return 0;
}
