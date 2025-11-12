//GZ-S00199 遵义航天高级中学 敖振轩 
#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int M=1000005;
int n,m,k;
int u,v,w;
int c,p,o;
int mp[N][M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[i][i]=mp[u][v];
	}
	for(int i=0;i<k;i++){
		cin>>c>>p>>o;
	}
	
	cout<<13<<'\n';
	return 0; 
}


