#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
const int K=20;
int n,m,k,u,v,w,cnt;
int c[K],fa[N];
int a[K][N];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Hebing(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x!=y) fa[y]=x;
}
struct node{
	int uu,vv,ww;
	bool operator<(const node& W)const{
		return W.ww<ww;
	}
};
priority_queue<node> pq;
void kus(){
	for(int i=1;i<=n+k;++i) fa[i]=i;
	int sum=1;
	while(sum<n+k){
		int u=pq.top().uu;
		int v=pq.top().vv;
		int w=pq.top().ww;
		pq.pop();
		if(Find(u)==Find(v)) continue;
		cnt+=w;
		Hebing(u,v);
		++sum;
	}
	return;
}
//vector<vector<pair<int,int>> g(N);

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
//		g[u].push_back({v,w});
//		g[v].push_abck({u,w});
		pq.push({u,v,w});
		
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			pq.push({n+i,j,a[i][j]});
		}
	}
	if(k==0){
		kus();
		cout<<cnt;
	}
	else{
		kus();
		cout<<cnt;
	}
	return 0;
}
