#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int K=15;
int n,m,k;
struct Edge{
	int u,v,w;
	bool operator<(const Edge&oth)const{
		return w<oth.w;
	}
}en[M],e[N];
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
long long ans=1e18+5,cost;
int cnt,ecnt;
void merge(int u,int v,int w,int&cnt){
	u=find(u),v=find(v);
	if(u!=v){
		fa[v]=u;
		e[cnt++]={u,v,w};
		cost+=w;
	}
}
int val[K],dist[K][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>en[i].u>>en[i].v>>en[i].w;
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++) cin>>dist[i][j];
	}
	sort(en+1,en+m+1);
	for(int i=1,j=1;i<=m&&j<n;i++) merge(en[i].u,en[i].v,en[i].w,j);
	for(int i=1;i<=n-1;i++) en[i]=e[i];
	for(int mash=0;mash<(1<<k);mash++){
		cost=cnt=ecnt=0;
		for(int i=1,p=1;i<=k&&mash>=p;i++,p<<=1)
		if(mash&p){
			cnt++;
			cost+=val[i];
			for(int j=1;j<=n;j++) en[n+ecnt]={n+cnt,j,dist[i][j]},ecnt++;
		}
		for(int i=1;i<=n+cnt;i++) fa[i]=i;
		sort(en+1,en+n+ecnt);
		for(int i=1,j=1;i<=n+ecnt-1&&j<n+cnt;i++) merge(en[i].u,en[i].v,en[i].w,j);
		ans=min(ans,cost);
	}
	cout<<ans;
	return 0;
}
