#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e4+10;
struct jtr{
	int u,v,w;
}e[inf*100];
bool operator<(jtr a,jtr b){return a.w>b.w;}
priority_queue<jtr> pq;
int n,m,k;
bool ext[11];
int c[11],a[11][inf];
int fa[inf*100];
vector<jtr> kkk;
vector<int> ke[11];
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int sol(int tmp){
	// cerr<<"sdfg\n";
	int cck=0;
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=k;i++){
		if(!ext[i]) continue;
		cck++;
		for(int j=1;j<=n;j++){
			pq.push((jtr){n+i,j,a[i][j]});
		}
	}
	if(tmp==0) for(int i=1;i<=m;i++) pq.push(e[i]);
	else for(auto op:kkk) pq.push(op);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=k;i++) ke[i].clear();
	int cnt=0,fu=0,fv=0,res=0,u=0,v=0;
	
	// while(!pq.empty()){
	// 	cout<<pq.top().u<<' '<<pq.top().v<<' '<<pq.top().w<<'\n';
	// 	pq.pop();
	// }
	
	while(cnt<n+cck-1){
		jtr o=pq.top();
		u=o.u,v=o.v;
		pq.pop();
		fu=find(u),fv=find(v);
		if(fu==fv) continue;
		if(tmp==0) kkk.emplace_back(o);
		cnt++;
		fa[fu]=fv;
		if(u>n){
			ke[u-n].emplace_back(o.w);
		}
		if(v>n){
			ke[v-n].emplace_back(o.w);
		}
		res+=o.w;
		// cerr<<++kkk<<'\n';
	}
	for(int i=1;i<=k;i++){
		if(!ext[i]) continue;
		if(ke[i].size()==1) res-=ke[i].back();
		else res+=c[i];
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int fac=1;
	for(int i=1;i<=k;i++) fac*=2;
	int ans=1e18+10;
	for(int tmp=0;tmp<fac;tmp++){
		for(int i=1;i<=k;i++){
			ext[i]=(tmp>>(i-1))&1;
		}
		// for(int i=1;i<=k;i++) cout<<ext[i]<<' ';
		// cout<<'\n';
		ans=min(ans,sol(tmp));
	}
	cout<<ans<<'\n';
}