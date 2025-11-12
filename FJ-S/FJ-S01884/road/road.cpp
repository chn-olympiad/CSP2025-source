#include<bits/stdc++.h>
using namespace std;
const int M=1e4+5;
int n,m,k,dis=0;
int d[M];
bool f[M];
struct Node{
	int to;
	int w;
};
vector<Node> v[M];
void dfs(int p){
	for(int i=0;i<v[p].size();i++){
		int to=v[p][i].to,w=v[p][i].w;
		if(f[to]==0&&(w+d[p])==d[to]){
			f[p]=1;
			dis+=w;
			dfs(to);
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,uu,w;
		cin>>u>>uu>>w;
		v[u].push_back({uu,w});
		v[uu].push_back({u,w});
	}
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	for(int i=1;i<=n;i++){
		int mi=-1;
		for(int j=1;j<=n;j++){
			if(!f[j]&&(mi==-1||d[mi]>d[j]))
			mi=j;
		}
		for(int j=0;j<v[mi].size();j++){
			int to=v[mi][j].to,w=v[mi][j].w;
			if(w+d[mi]<d[to]){
				
				d[to]=w+d[mi];
			}
		}
		f[mi]=1;
	}
	memset(f,0,sizeof(f));
	f[1]=1;
	dfs(1);
	cout<<dis;
}
