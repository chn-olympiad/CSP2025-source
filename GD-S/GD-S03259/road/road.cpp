#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
using ll=long long;
const int MAXN=10005,MAXM=1000005;
struct Edge{
	int u,v,w;
	bool operator<(const Edge&o)const{
		return w<o.w;
	}
}G[MAXM],edg[MAXN*20],tmp[MAXN*20];
int fa[MAXN+15],n,m,c,k,C[15],A[15][MAXN];
int ALL;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void init(){
	c=0;
	sort(G+1,G+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=find(G[i].u),v=find(G[i].v);
		if(u==v) continue;
		fa[u]=v;
		edg[++c]=G[i];
		if(c==n-1) break;
	}
}
ll kruskal(int n,int m){
	ll sum=0;
	int cnt=0;
	for(int i=1;i<=m;i++) tmp[i]=edg[i];
	sort(tmp+1,tmp+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=find(tmp[i].u),v=find(tmp[i].v);
		if(u==v) continue;
		fa[u]=v;
		cnt++,sum+=tmp[i].w;
		if(cnt==n-1) break;
	}return sum;
}
void solve1(){
	ll ans=1e18;
	for(int S=0;S<=ALL;S++){
		ll res=0;
		int posn=n,posm=c;
		for(int i=0;i<k;i++){
			if((S&(1<<i))==0) continue;
			res+=C[i];
			posn++;
			for(int j=1;j<=n;j++) edg[++posm]={posn,j,A[i][j]};
		}
		res+=kruskal(posn,posm);
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>G[i].u>>G[i].v>>G[i].w;
	for(int i=0;i<k;i++){
		cin>>C[i];
		for(int j=1;j<=n;j++) cin>>A[i][j];
	}
	init();
	ALL=(1<<k)-1;
	solve1();
	return 0;
} 
