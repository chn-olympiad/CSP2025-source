#include <bits/stdc++.h>
using namespace std;
const int N=10005;
#define ll long long

ll n,m,ans,k;
struct edge{
	ll u,v,w;
};
vector<edge> e;
ll nc[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll p[N];
ll fd(int x){
	if(p[x]==x) return x;
	return p[x]=fd(p[x]); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		ll c;
		cin>>c;
		ans+=c;
		for(int j=1;j<=n;j++){
			cin>>nc[j];
		}
		for(int o=1;o<=n;o++){
			for(int l=o+1;l<=n;l++){
				e.push_back({l,o,nc[l]+nc[o]});
			}
		}
	}
	sort(e.begin(),e.end(),cmp); 
	for(int i=0;i<e.size();i++){
		ll nx=e[i].u,ny=e[i].v,nw=e[i].w;
		if(fd(nx)==fd(ny)) continue;
		p[fd(nx)]=fd(ny);
		ans+=nw;
	}
	cout<<ans;
	
	return 0;
}
