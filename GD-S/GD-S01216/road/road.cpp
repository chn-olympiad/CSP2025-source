#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m,k,fa[maxn],v[maxn];
long long ans;
struct R{
	int u,v,w;
	bool operator < (const R &RR) const{return w>RR.w;}
};
priority_queue<R> P;
int dofind(int u){
	if(fa[u]==u) return u;
	fa[u]=dofind(fa[u]);
	return fa[u];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		P.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		for(int i=0;i<=n;i++){
			scanf("%d",&v[i]);
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(j==l) continue;
				P.push({j,l,v[j]+v[l]});
			}
		}
	}
	while(!P.empty()){
		int u=P.top().u,v=P.top().v,w=P.top().w;
		P.pop();
		if(fa[u]==fa[v]) continue;
		fa[fa[v]]=fa[u];
		dofind(v);
		ans+=w;
	}
	cout<<ans;
	return 0;
}

