#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+107;
const int M = 1e6+107; 
const int K = 17;
bitset <K> flag;
int n,m,k;
int ans,cnt;
int fa[N];
int c[K],a[K][N];
int deg[K],sum[K];
struct edge{
	int x,y,v,k;
	inline bool operator >(edge Other) const {
		return v>Other.v;
	}
}Edge[M<<2];
unordered_map <int,bool> Mp;
priority_queue < edge,vector<edge>,greater<edge> > Q;
int ff(int x){
	if(fa[x]==x) return x;
	else return fa[x]=ff(fa[x]);
}
void Kruskal(){
	flag[0]=true;
	for(int i=1;i<=n+k+1;i++) fa[i]=i;
	for(int i=1;i<=k;i++) flag[i]=false;
	for(int i=1;i<=cnt;i++) Q.push(Edge[i]);
	while(Q.empty()!=true){
		edge dq=Q.top(); Q.pop();
		int fx=ff(dq.x),fy=ff(dq.y);
		if(fx==fy) continue;
		fa[fx]=fy; deg[dq.k]++; 
		ans+=dq.v; sum[dq.k]+=dq.v;
		if(!flag[dq.k]){
			flag[dq.k]=true;
			for(int j=1;j<=n;j++) Q.push({dq.k+n,j,a[dq.k][j],dq.k});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,v;
		cin>>x>>y>>v;
		Edge[++cnt]={x,y,v,0};
	}
	for(int i=1;i<=k;i++){
		int lk=1; cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][lk]>a[i][j]) lk=j;
		}Edge[++cnt]={i+n,lk,a[i][lk]+c[i],i};
	}Kruskal();
	for(int i=1;i<=k;i++) if(deg[i]==1) ans-=sum[i];
	cout<<ans;
	return 0;
}
/*

freopen("road.in","r",stdin);
freopen("road.out","w",stdout);

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
