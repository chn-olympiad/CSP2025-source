#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct edge{
	int u,v,w;
	operator<(const edge a)const{return w<a.w;}
};
int village[12][10007],sub[12];
vector<edge> graph;

int fa[10007];

int findroot(int p){
	if(p==fa[p])return p;
	else return fa[p]=findroot(fa[p]);
}
bool merge(int p,int q){
	if(findroot(p)==findroot(q))return false;
	else{
		fa[findroot(q)]=findroot(p);
		findroot(q);
	}
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,k,c,u,v,w;cin>>n>>m>>k;
	long long result=0;
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		graph.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>village[i][j];
			if(village[i][j]==0)sub[i]=j;
		}
		for(int j=1;j<=n;j++){
			if(j!=sub[i]){
				graph.push_back({sub[i],j,village[i][j]});
			}
		}
	}
	sort(graph.begin(),graph.end());
	for(edge i:graph){
		if(merge(i.u,i.v))result+=i.w;
	}
	cout<<result;
	return 0;
}
