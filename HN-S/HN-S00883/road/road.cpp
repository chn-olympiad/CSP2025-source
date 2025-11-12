#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,cnt,fa[N],ans;
struct node{
	int u,v,w;
};
vector<node> g;
bool cmp(node A,node B){
	return A.w<B.w; 
}
int fin(int x){
	if(fa[x]==x) return x;
	else fa[x]=fin(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	} 
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(g.begin(),g.end(),cmp);
	for(int i=0;i<g.size();i++){
		int x=fin(g[i].u),y=fin(g[i].v);
		if(x==y) continue;
		cnt++;
		fa[y]=x;
		ans+=g[i].w;
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
