#include<bits/stdc++.h>
using namespace std;
const int M=1e6+100,K=13,N=1e4+100;
struct edge{
	int u,v,w;
};
vector<edge> g_y,g[K],gn;
int n,m,k,c[K],x[N],top,fa[M+N*K],si[M+N*K];
long long ans=LLONG_MAX;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g_y.push_back({u,v,w});
	}
	top=n;
	for(int i=1;i<=k;i++){
		cin>>c[k];
		++top;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			g[i].push_back({top,j,x[j]});
		}
	}
	for(int i=0;i<(1<<(k+1));i++){
		long long val=0,cnt=n;
		for(int j=1;j<=top;j++){
			fa[j]=j;
			si[j]=1;
		}
		gn=g_y;
		for(int j=1;j<=k;j++){
			if((i>>j)&1){
				val+=x[j];
				cnt++;
				for(auto y:g[j]){
					gn.push_back(y);
				}
			}
		}
		sort(gn.begin(),gn.end(),cmp);
		for(auto e:gn){
			int uu=find(e.u),vv=find(e.v);
			if(uu==vv) continue;
			fa[vv]=uu;
			si[uu]+=si[vv];
			val+=e.w;
		}
		ans=min(ans,val);
	}
	cout<<ans<<endl;
	return 0;
}
