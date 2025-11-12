#include<bits/stdc++.h>
#define ll long long
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int N=1e4+20;
const int M=1e6+10;
const int K=15;
int head[N],fa[N];
int n,m,k;
ll ans;
ll a[K][N];
struct Edge{
	int from,nxt,to;
	ll val;
};
Edge g[M<<1];
int cnt,cntfb;
void add(int u,int v,ll w){
	g[++cnt].to=v;
	g[cnt].from=u;
	g[cnt].nxt=head[u];
	g[cnt].val=w;
	head[u]=cnt;
}
bool cmp(Edge x,Edge y){
	return x.val<y.val;
}
int findf(int x){
	if(x==fa[x]) return x;
	return fa[x]=findf(fa[x]);
}
void merge(int x,int y){
	x=findf(x);
	y=findf(y);
	fa[x]=y;
}
ll zxs(int S){
	for(int i=1;i<=n+15;i++){
		fa[i]=i;
	}
	ll ans=0;
	int i=1;
	cnt=cntfb;
	while(S){
		if(S&1){
			ans+=a[i][0];
			for(int j=1;j<=n;j++){
				add(n+i,j,a[i][j]);
				add(j,n+i,a[i][j]);
			}
		}
		S>>=1;
		i++;
	}
	sort(g+1,g+1+cnt,cmp);
	for(i=1;i<=cnt;i++){
		int u=g[i].from,v=g[i].to;
		ll w=g[i].val;
		if(findf(u)!=findf(v)){
			ans+=w;
			merge(u,v);
		}
	}
	return ans;
}
int main(){
	FILE("road");
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		ans+=w;
	}
	cntfb=cnt;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int maxS=1<<k;
	for(int S=0;S<maxS;S++){
		ans=min(ans,zxs(S));
	}
	cout<<ans;
	return 0;
}
