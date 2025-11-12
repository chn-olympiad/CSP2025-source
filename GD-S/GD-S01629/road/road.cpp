#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1000000+10;
int fat[10000+10];
int size[10000+10];
int x[10000+10];

int find(int x){
	if(fat[x]=x) return x;
	int r=find(fat[x]);
	return fat[x]=r;
}

void merge(int x,int y){
	int xr=find(x),yr=find(y);
	if(size[xr]>=size[yr]) {
		fat[yr]=xr;
		size[xr]+=size[yr];
	}
	else {
		fat[xr]=yr;
		size[yr]+=size[xr];
	}
}

struct edge{
	int u,v;
	int w;
};
vector<edge> vc;

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fat[i]=i,size[i]=1;
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		vc.push_back(edge{u,v,w});
	}
	
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			vc.push_back(edge{i,n+1,c});
			for(int q=1;q<=n;q++)
				if(i!=q)vc.push_back(edge{q,n+1,x});
		}
	}
	sort(vc.begin(),vc.end(),cmp);
	int sum=0;
	for(int i=0;i<vc.size();i++){
		int u=vc[i].u,v=vc[i].v;
		if(find(u)!=find(v)){
			sum+=vc[i].w;
			merge(u,v);
		}
	}
	cout<<sum<<endl;
	return 0;
}
