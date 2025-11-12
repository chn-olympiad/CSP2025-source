#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
	int u,v,w;
	bool operator < (const edge d)const{
		return w<d.w;
	}
};
vector<edge> g;
vector<edge> nwg;
const int N=1e4+25;
int fa[N];
void init(int cnt){
	for(int i=1;i<=cnt;i++){
		fa[i]=i;
	}
}
int Find(int x){
	if(fa[x]==x){
		return fa[x];
	}
	fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int x,int y){
	if(Find(x)==Find(y)) return;
	fa[Find(y)]=Find(x);
}
ll MST(int n,bool change){
	init(n);
	ll tans=0;
	for(edge e:g){
		if(Find(e.u)==Find(e.v)){
			continue;
		}
		tans+=1ll*e.w;
		Union(e.u,e.v);
		
		if(change) nwg.push_back(e);
		
	}
	return tans;
}
const int K=12;
int c[K];
int a[K][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	sort(g.begin(),g.end());
	ll ans=MST(n,true);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int s=1;s<(1<<k);s++){
		g.clear();
		int cnt=n;
		for(edge i:nwg){
			g.push_back(i);
		}
		ll tans=0;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				cnt++;
				tans+=c[i];
				for(int j=1;j<=n;j++){
					g.push_back({cnt,j,a[i][j]});
				}
			}
		}
		sort(g.begin(),g.end());
		tans+=MST(cnt,false);
		ans=min(ans,tans);
	}
	cout<<ans<<"\n";
}
