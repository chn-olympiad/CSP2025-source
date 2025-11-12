#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
struct road{
	int u,v,w;
};
vector<road> g;
bool cmp(road p,road q){
	return p.w<q.w;
}
int fa[5005];
int getfa(int x){
	if(fa[x]!=x) fa[x]=getfa(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back((road){u,v,w});
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(g.begin(),g.end(),cmp);
	int cnt=0,ans=0;
	m=g.size();
	for(int i=0;i<m;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		int gu=getfa(u),gv=getfa(v);
		if(gu!=gv){
 			fa[gu]=gv;
			ans+=w;
			if(u<=n||v<=n) cnt++;
			if(cnt>=n-1) break;
		}
	}
	cout<<ans;
	return 0;
}
//Ï¸½ÚÈüÇ°¸´Ï°Kruskal 
