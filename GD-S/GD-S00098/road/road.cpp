#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
template<class...Arg>
void println(Arg...arg){
	int _[]={(cout<<arg<<' ',0)...};
	cout<<'\n';
}
struct P{
	int a,b,w;
	bool operator<(const P& p)const{
		return w<p.w;
	}
};
vector<P> edge;
int fa[10050];
int finfa(int x){
	return fa[x]==x?x:fa[x]=finfa(fa[x]);
}
int n,m,k;
int main(){
	//freopen("../../csps/road/road3.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int tmp;
		cin>>tmp;
		for(int j=1;j<=n;j++){
			cin>>w;
			edge.push_back({n+i,j,w});
		}
	}
	sort(edge.begin(),edge.end());
	int ans=0;
	for(int i=0;i<edge.size();i++){
		//println(edge[i].w);
		int uf=finfa(1);
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(finfa(j)!=uf) flag=false;
		}
		if(flag){
			cout<<ans;
			return 0;
		}
		ans+=edge[i].w;
		auto&e=edge[i];
		fa[e.a]=finfa(e.b);
	}
	cout<<ans;
	return 0;
}
