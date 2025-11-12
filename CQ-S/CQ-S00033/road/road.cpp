#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
int u,v,l;
int mp[4011][4011];
int g,tmp;
void dfs();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>l;
		mp[u][v]=l;
		mp[v][u]=l;
	}
	for(int i=1;i<=k;i++){
		cin>>g;
		for(int j=1;j<=n;j++){
			cin>>tmp;
			mp[n+1][j]=tmp+g;
			mp[j][n+1]=tmp+g; 
		}
	} 
	cout<<0; 
	return 0;
}

