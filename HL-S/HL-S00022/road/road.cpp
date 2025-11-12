#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> fathers;
int find(int son){
	if(fathers[son]==-1){
		return son;
	}
	else{
		return fathers[son]=find(fathers[son]);
	}
}
void _union(int son1,int son2){
	fathers[find(son2)]=find(son1);
}
bool isSameSet(int son1,int son2){
	if(find(son1)==find(son2)){
		return 1;
	}
	else{
		return 0;
	}
}
struct Edge{
	int start,end,dis;
	bool operator<(const Edge& tmp) const{
		return dis<tmp.dis;
	}
};
vector<Edge> edges;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n,m,k,u,v,w,c,a,ans=0;
    cin>>n>>m>>k;
    fathers.resize(n+k+1,-1);
    for(int i=0;i<m;i++){
    	cin>>u>>v>>w;
    	edges.push_back({u,v,w});
	}
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
			edges.push_back({j,n+i+1,a});
		}
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<edges.size();i++){
		if(!isSameSet(edges[i].start,edges[i].end)){
			ans+=edges[i].dis;
			_union(edges[i].start,edges[i].end);
		}
	}
	cout<<ans;
    return 0;
}
