//GZ-S00113 黎平县第二中学 唐启谦 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
	int u,v,w;
};
int n,m,k,a[10],f[10011],nw[10][10000],cost=0;
bool use[10];
vector<Edge>e;
int father(int x){
	return f[x]==x?x:father(f[x]);
}
void merge(int x,int y){
	f[x]=father(f[y]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u-1,v-1,w});
	}for(int i=0;i<k;i++){
		cin>>a[i];
		for(int j=0;j<n;j++){
			int w;
			cin>>w;
		}
	}sort(e.begin(),e.end(),[](Edge a,Edge b){return a.w<b.w;});
	for(int i=0;i<n;i++)f[i]=i;
	for(int i=0;i<m;i++){
		if(father(e[i].v)!=father(e[i].u)){
			merge(e[i].u,e[i].v);
			cost+=e[i].w;
		}
	}cout<<cost;
	return 0;
}
//o o
// ^
