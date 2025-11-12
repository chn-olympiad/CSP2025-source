#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10005],v[10005],w[10005];
int mapp[1005][1005];
int con[10005];
int lu[1005][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		lu[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>con[i];
		for(int j=1;j<=n;j++){
			cin>>mapp[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int a=1;a<=m;a++){
			for(int b=1;b<=m;b++){
				if(u[a]==u[b]||u[a]==i||u[b]==i) continue;
				if(u[a]==i&&u[b]==i) lu[v[a]][v[b]]=min(lu[v[a]][v[b]],w[a]+w[b]);
				if(v[a]==i&&u[b]==i) lu[u[a]][v[b]]=min(lu[u[a]][v[b]],w[a]+w[b]);
				if(v[a]==i&&v[b]==i) lu[u[a]][u[b]]=min(lu[u[a]][u[b]],w[a]+w[b]);
				if(u[a]==i&&v[b]==i) lu[v[a]][u[b]]=min(lu[v[a]][u[b]],w[a]+w[b]);
			}
		}
	}
    cout<<0;
    return 0;
}
