#include <bits/stdc++.h>
#define int long long
#define popcount __builtin_popcount
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e4+25,M=1e6+N*10,INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,a[12][N],c[12];
#define u(x) lin[x].u
#define v(x) lin[x].v
#define w(x) lin[x].w
struct L{
	int u,v,w;
	bool operator <(const L to)const{ return w<to.w; }
}lin[M];
int f[N];
int find(int x){
	return f[x]==x?x:(f[x]=find(f[x]));
}
void solve1(){
	int tot=m;
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) lin[++tot]={n+i,j,a[i][j]};
	sort(lin+1,lin+1+tot);
	
	int ans=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=tot;i++){
		int U=find(u(i)),V=find(v(i));
		if(U==V) continue;
		ans+=w(i),f[U]=V;
	}
	cout<<ans;
}
vector<pii> nil[N];
bool bjt[N],bjt_in[N];
int min_f[N];
void solve2(){
	for(int i=1;i<=m;i++) nil[u(i)].emplace_back(v(i),w(i)),nil[v(i)].emplace_back(u(i),w(i));
	
	int ans=INF;
	for(int st=0;st<1<<k;st++){
		int all=n+popcount(st);
		for(int i=1;i<=n+k;i++) bjt_in[i]=0;
		for(int i=1;i<=n;i++) bjt_in[i]=1;
		for(int i=1;i<=k;i++) if(st>>(i-1)&1) bjt_in[n+i]=1;
		
		int rans=0;
		for(int i=1;i<=k;i++) if(bjt_in[n+i]){
			rans+=c[i];
			for(int j=1;j<=n;j++) nil[n+i].emplace_back(j,a[i][j]),nil[j].emplace_back(n+i,a[i][j]);
		}
		
		for(int i=1;i<=n+k;i++) bjt[i]=0,min_f[i]=INF;
		min_f[1]=0;
		for(int i=1;i<=all;i++){
			int tmp=-1;
			for(int j=1;j<=n+k;j++) if(bjt_in[j]&&!bjt[j]&&(tmp==-1||min_f[j]<min_f[tmp])) tmp=j;
			
			rans+=min_f[tmp],bjt[tmp]=1;
			for(pii e:nil[tmp]) min_f[e.fi]=min(min_f[e.fi],e.se); 
		}
		ans=min(ans,rans);
		
		for(int i=n+1;i<=n+k;i++) nil[i].clear();
		for(int i=1;i<=n;i++) for(int j=1;j<=all-n;j++) nil[i].pop_back(); 
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u(i)>>v(i)>>w(i);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	
	bool special_A=1;
	for(int i=1;i<=k;i++){
		if(c[i]!=0) special_A=0;
		bool flag=0;
		for(int j=1;j<=n;j++) flag|=a[i][j]==0;
		special_A&=flag;
	}
	if(special_A) solve1();
	else solve2();
	return 0;
}