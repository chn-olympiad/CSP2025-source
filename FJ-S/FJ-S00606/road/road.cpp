#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct edge{
	int u;int v;int w;
}edges[1100010];
vector<int> townedges[11];
int towns[11];
bool cmp(edge a,edge b){
	return a.w<b.w;
}

int par[10050];
void initpar(int num){
	for(int i=0;i<num;i++){
		par[i]=i;
	}
}
int findpar(int i){
	return par[i]==i?i:par[i]=findpar(par[i]);
}
void connect(int u,int v){
	par[findpar(u)]=findpar(v);
}
//int readint(){
//	int v=0;bool bef=false;
//	while(true){
//		char c=getc(stdin);
//		if(c>='0'&&c<='9'){
//			v*=10;
//			v+=c-'0';
//			bef=true;
//		}else if(bef){
//			return v;
//		}
//	}
//}

int main(){
	int n,m,k,em;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.sync_with_stdio(false);
//	n=readint();
//	m=readint();
//	k=readint();
	cin>>n>>m>>k;
	em=m;
	for(int i=0;i<m;i++){
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
//		edges[i].u=readint();
//		edges[i].v=readint();
//		edges[i].w=readint();
	}
	for(int i=1;i<=k;i++){
		cin>>towns[i];
//		towns[i]=readint();
		for(int j=1;j<=n;j++){
//			int v=readint();
			int v;
			cin>>v;
			edges[em].u=n+i;
			edges[em].v=j;
			edges[em++].w=v+towns[i];
		}
	}
	sort(edges,edges+em,cmp);
	initpar(n+k);
	int ans=0;
	for(int i=0;i<em;i++){
		if(findpar(edges[i].u)!=findpar(edges[i].v)){
			connect(edges[i].u,edges[i].v);
			ans+=edges[i].w;
			if(edges[i].u>n){
				townedges[edges[i].u-n].push_back(edges[i].w);
				if(townedges[edges[i].u-n].size()!=1)ans-=towns[edges[i].u-n];
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(townedges[i].size()==1){
			ans-=townedges[i][0];
		}
	}
	cout<<ans;
	return 0;
}
