#include<bits/stdc++.h>
using namespace std;
struct road{
	int to,w;
};
vector<road> rd[10005];
int xc[15][10005];
int gz[15];
int zdl[10005],ljcd[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		rd[u].push_back({v,w});
		rd[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>gz[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<rd[i].size();j++){
			zdl[i]=min(zdl[i],zdl[rd[i][j].to]+rd[i][j].w);
			if(zdl[i]==zdl[rd[i][j].to]+rd[i][j].w){
				ljcd[i]=rd[i][j].w;
			}
		}
		for(int j=0;j<rd[i].size();j++){
			if(ljcd[rd[i][j].to]>rd[i][j].w){
				zdl[i]=zdl[i]-ljcd[rd[i][j].to]+rd[i][j].w;
				ljcd[rd[i][j].to]=rd[i][j].w;
			}
		}
	}
	cout<<zdl[n];
	return 0;
} 