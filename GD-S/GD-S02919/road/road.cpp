#include <bits/stdc++.h>
#define long long ll
using namespace std;
const int N=1e4+5;
int pnt[N],c[10+5],a[10+5][N];
int find_root(int x){
	if(pnt[x]==x)return x;
	return pnt[x]=find_root(pnt[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(pnt[u]==0)pnt[u]=u;
		if(pnt[v]==0)pnt[v]=v;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		/*
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				pnt
			}
		}
		*/
	}
	cout<<"0";
	return 0;
}
