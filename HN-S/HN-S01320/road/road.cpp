#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e4+5;
int n,m,k;
int c[15],a[15][N];
struct edge{
	int x,y,z;
	bool operator<(const edge &e0){
		return z<e0.z;
	}
};
vector<edge> e;
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int Kruskal(){
	sort(e.begin(),e.end());
	for(int i=1;i<=n+k;i++)fa[i]=i;
	long long cnt=0;
	for(int i=0;i<e.size();i++){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;
			cnt+=z;
		}
	}
	return cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});	
	}
	for(int i=1;i<=k;i++){
		cin>>c[k];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e.push_back({n+i,j,a[i][j]});
		}
	}
	cout<<Kruskal();
	return 0;
}
