#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5;
int n,m,k;
struct node{int id,v,w;};
bool operator <(node a,node b){return a.w>b.w;}
vector<node>e[N+10],g[N+10];
priority_queue<node>q;
int vis[N+10],js[M+10];
int u[M],v[M],w[M];
ll minT(int root){
	ll res=0,jz=0;
	q.push({0,root,0});
	while(!q.empty()){
		node d=q.top();q.pop();
		if(vis[d.v])continue;
		res+=(ll)d.w;
		js[d.id]=1,vis[d.v]=1;
		for(auto j:e[d.v]){q.push(j);}
	}
	return res;
}
int c[15],a[15][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		e[u[i]].push_back({i,v[i],w[i]});
		e[v[i]].push_back({i,u[i],w[i]});
	}
	minT(1);
	for(int i=1; i<=m; i++){
		if(js[i]){
			g[u[i]].push_back({i,v[i],w[i]});
			g[v[i]].push_back({i,u[i],w[i]});
		}
	}
	for(int i=1; i<=k; i++){
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	}
	ll mi=1e18;
	for(int i=0; i<(1<<k); i++){
		ll ans=0;
		memset(vis,0,sizeof vis);
		for(int j=1; j<=n; j++)e[j]=g[j];
		for(int j=0; j<k; j++){
			if((i>>j)&1){
				ans+=(ll)c[j+1];
				for(int d=1; d<=n; d++){
					e[n+j+1].push_back({0,d,a[j+1][d]});
					e[d].push_back({0,n+j+1,a[j+1][d]});
				}
			}
		}
		ans+=minT(1);
		mi=min(mi,ans);
	}
	cout<<mi;
	return 0;
}
/*
5 7 2
1 4 6
2 3 7
4 2 5
4 3 4
1 2 5
2 5 1
3 5 2

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
