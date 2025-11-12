#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e4+5;
const int M=1e6+5;
int n,m,k,ans,f[M];
int c[MAXN],a[15][MAXN],len[M];
ll sum,minn=1e18;
struct road{ 
	int u,v,w;
} r1[M],r2[M];
int cmp(road x,road y) 
{ 
	return x.w<y.w;
} 
void Add(int x) 
{ 
	sum+=c[x];
	for(int i=1;i<=n;++i) 
	{ 
		++ans;
		r2[ans].u=n+x;
		r2[ans].v=i;
		r2[ans].w=a[x][i];
	} 
} 
int find(int x) 
{ 
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
} 
void solve() 
{ 
	r2[ans+1].w=1e9+5;
	for(int i=1;i<=n+k;++i) f[i]=i;
	for(int i=1;i<=n;++i) len[i]=1;
	for(int i=n+1;i<=n+k;++i) len[i]=0;
	int cnt1=1,cnt2=1;
	int u,v,w;
	while(cnt1<=m||cnt2<=ans) 
	{ 
		if(r1[cnt1].w<r2[cnt2].w) u=r1[cnt1].u,v=r1[cnt1].v,w=r1[cnt1].w,++cnt1;
		else u=r2[cnt2].u,v=r2[cnt2].v,w=r2[cnt2].w,++cnt2;
		if(find(u)==find(v)) continue;
		f[find(u)]=find(v);
		len[find(v)]+=len[find(u)];
		sum+=w;
		if(len[find(v)]==n||sum>=minn) break;
	} 
	minn=min(minn,sum);
} 
int main() 
{ 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) 
		cin>>r1[i].u>>r1[i].v>>r1[i].w;
	sort(r1+1,r1+1+m,cmp);
	r1[m+1].w=1e9+5;
	for(int i=1;i<=k;++i) 
	{ 
		cin>>c[i];
		for(int j=1;j<=n;++j) 
			cin>>a[i][j];
	} 
	for(int i=0;i<(1<<k);++i) 
	{ 
		sum=ans=0;
		for(int j=1;j<=k;++j) 
			if(i&(1<<(j-1))) Add(j);
		if(ans) sort(r2+1,r2+1+ans,cmp);
		solve();
		minn=min(minn,sum);
	} 
	cout<<minn;

	return 0;
} 
