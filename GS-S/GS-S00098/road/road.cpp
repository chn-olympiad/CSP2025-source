#include<bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,w;
	bool operator<(const Node &b)const{
		return w<b.w;
	}
};
vector<Node> g;
int fa[100005],n,m,k,cnt,ans;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
			g.push_back({n+i,j,t});
		}
	}
	sort(g.begin(),g.end());
	for(auto x:g){
		int u=x.u,v=x.v;
		int px=find(u),py=find(v);
		if(px!=py) fa[px]=py;
		cnt++;
		ans+=x.w;
		if(cnt==n+k-1) break;
	}
	cout<<ans;
}
