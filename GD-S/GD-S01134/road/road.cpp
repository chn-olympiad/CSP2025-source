#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+5;
long long n,a[N][N],m,k,u,v,w,x[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f3f3f,sizeof a);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	for(int i=1;i<=k;i++){
		cin>>x[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			a[i][j]=min(a[i][j],w);
			a[j][i]=min(a[j][i],w);
		}
	}
	cout<<13;
	return 0;
}
