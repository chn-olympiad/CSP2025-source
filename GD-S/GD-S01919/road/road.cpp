#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=10;
int n,m,k;
struct node
{
	int u,v,w;
	bool operator <(const node &ot)const{return w<ot.w;}
}e[M],e2[K+1][N];
int fa[N],siz[N];
int getfa(int u)
{
	if(fa[u]==u)return u;
	return fa[u]=getfa(fa[u]);
}
int merge(int u,int v)
{
	u=getfa(u);
	v=getfa(v);
	if(u==v)return false;
	if(siz[u]<siz[v])swap(u,v);
	fa[v]=u;
	siz[u]+=siz[v];
	return true;
}
int cnt[1<<K];
node ans[1<<K][N];
long long answ[1<<K];
int lowbit(int x){return x&-x;}
int c[N],a[K+1][N];
int l2[1<<K];
long long minans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for(int i=0;i<=9;i++)l2[1<<i]=i;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++)
		if(merge(e[i].u,e[i].v))ans[0][++cnt[0]]=e[i],answ[0]+=e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++)e2[i][j]={i+n,j,a[i][j]};
		sort(e2[i]+1,e2[i]+1+n);
	}
	minans=answ[0];
	int U=(1<<k)-1;
	for(int S=1;S<=U;S++)
	{
		int x=l2[lowbit(S)]+1;
		int T=(S^lowbit(S));
		int now1=1,now2=1;
		m=0;
		while(now1<=cnt[T]&&now2<=n)
		{
			if(ans[T][now1].w<e2[x][now2].w)e[++m]=ans[T][now1++];
			else e[++m]=e2[x][now2++];
		}
		while(now1<=cnt[T])e[++m]=ans[T][now1++];
		while(now2<=n)e[++m]=e2[x][now2++];
		for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=1;
		for(int i=1;i<=m;i++)
			if(merge(e[i].u,e[i].v))answ[S]+=e[i].w,ans[S][++cnt[S]]=e[i];
		for(int i=1;i<=k;i++)
			if(S&(1<<(i-1)))answ[S]+=c[i];
		minans=min(minans,answ[S]);
	}
	cout<<minans<<'\n';
	return 0;
}
