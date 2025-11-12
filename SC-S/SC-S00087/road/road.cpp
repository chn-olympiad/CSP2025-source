#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
int Time=clock();
bool mst;
const int N=1e4+15;
const int M=1e6+5;
const ll INF=1e18;
struct Edge{
	int u,v,w;
	bool operator <(Edge oth){
		return w<oth.w;
	}
};
Edge d[M],td[M];
vector<Edge> E[1025];
int n,m,K,v[15],ok[15],fa[N],A[15][N];
ll ans=INF;
int Find(int a){
	if(fa[a]==0)  return a;
	return fa[a]=Find(fa[a]);
}
void dfs(int a,int b,int sta,int res,int first,int cnt){
	if(a==K+1){
		int len=0;
		ll tans=0;
		for(int i=1;i<=K;i++)
			if(sta&(1<<i-1))  tans+=v[i];
		for(int i=1;i<=n+K;i++)
			fa[i]=0;
		if(cnt==n){
			for(int i=1;i<=m;i++)
				d[++len]={td[i].u,td[i].v,td[i].w};
		}
		else{
			for(Edge i:E[res])
				d[++len]=i;
			for(int i=1;i<=n;i++)
				d[++len]={i,first+n,A[first][i]};
		}
		for(int i=1;i<=n+K;i++)
			fa[i]=0;
		sort(d+1,d+1+len);
		for(int i=1,j=cnt;i<=len;i++){
			if(j==1)  break;
			int u=d[i].u,v=d[i].v,w=d[i].w;
			if(Find(u)!=Find(v))  j--,fa[Find(u)]=Find(v),tans+=w,E[sta].pb(d[i]);
			if(j==1)  break;
		}
		ans=min(ans,tans);
		return ;
	}
	if(K-a>=b)  dfs(a+1,b,sta,res,first,cnt);
	if(b){
		sta|=(1<<a-1);
		if(first==0)  first=a;
		else  res|=(1<<a-1);
		dfs(a+1,b-1,sta,res,first,cnt);
	}
}
bool med;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		td[i]={u,v,w};
	}
	sort(d+1,d+1+m);
	for(int i=1;i<=K;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++)
			cin>>A[i][j];
	}
	for(int i=0;i<=K;i++)
		dfs(1,i,0,0,0,i+n);
	cout<<ans;
	// cerr<<"Time:"<<1.0*(clock()-Time)/CLOCKS_PER_SEC<<"s\n";
	// cerr<<"Memory:"<<1.0*(&med-&mst)/1024.0/1024.0<<"MB\n";
	return 0;
}