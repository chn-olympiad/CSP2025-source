#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,pair<int,int> >
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k;
ll ans,res;
int cw[15][N],p[N];
priority_queue<pii,vector<pii>,greater<pii> > g,edge;
void build(){
	for(int i=0;i<(1<<k);i++){
		while(edge.size()) edge.pop();
		for(int i=1;i<=m;i++) 
	}
}
int find(int x){
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout)
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		g.push({w,{u,v}});
	}
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) scanf("%d",&cw[i][j]);
	build();
	return 0;
}
