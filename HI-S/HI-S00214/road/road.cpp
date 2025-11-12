#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,m,k;
ll c[20];
vector<pair<int,ll> > edge[10005];
ll f[10005];
bool cmp(int pt1,int pt2){
	return false;
}
//priority_queue<int,vector<int>,cmp > q;
void Prim(){
	for(int i=1;i<=n;i++) f[i]=INF;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d %d %lld",&u,&v,&w);
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		ll ccst[10005];
		int rt=0;
		scanf("%lld",c+i);
		for(int j=1;j<=n;j++){
			scanf("%lld",ccst+j);
			if(ccst[j]==0) rt=j;
		}
		for(int j=1;j<=n;j++){
			if(j==rt) continue;
			edge[rt].push_back({j,ccst[j]});
			edge[j].push_back({rt,ccst[j]});
		}
	}
	Prim();
//	printf("%lld",ans);
	return 0;
}
