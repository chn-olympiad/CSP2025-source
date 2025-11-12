#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int u,v,w,p;};
int n,m,k,ans;
int f[20000],vis[100];
vector<node>e;
bool cmp(node x,node y){return x.w+x.p<y.w+y.p;}
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool check(){
	set<int>s;
	for(int i=1;i<=n;++i) s.insert(find(i));
	return s.size()==1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		e.push_back({u,v,w,0});
	}
	for(int i=m+1,p;i<=m+k;++i){
		cin>>p; 
		for(int j=1,x;j<=n;++j){
			cin>>x;
			e.push_back({i,j,x,p});
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=m+k;++i) f[i]=i;
	for(int i=0;i<e.size();++i){
		int x(find(e[i].u));
		int y(find(e[i].v));
		if(x>y) swap(x,y);
		if(x!=y){
			f[y]=x;
			ans+=e[i].w;
			if(e[i].p) if(!vis[e[i].u]++) ans+=e[i].p;
		}
		if(check()) break;
	}
	cout<<ans;
}
