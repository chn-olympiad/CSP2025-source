#include <bits/stdc++.h>
using namespace std;
struct st{
	int u,v,w;
}c[1005];
int n,m,k,f[10],a[10][1005],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) cin>>c[i].u>>c[i].v>>c[i].w;
	for(int i=1; i<=k; i++){
		cin>>f[i];
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	int m=0;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			if(c[j].w>=f[i]+a[i][c[i].u]+a[i][c[i].v]&&m==0){
				ans+=f[i]+a[i][c[i].u]+a[i][c[i].v];
				m++;
			}
			else if(c[j].w>=f[i]+a[i][c[i].u]+a[i][c[i].v]&&m!=0){
				ans+=a[i][c[i].u]+a[i][c[i].v];
			}
			else ans+=c[j].w;
		}
	}
	cout<<ans;
}
