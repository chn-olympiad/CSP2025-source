#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000007],v[1000007],w[1000007];
int l[17][100007];
int main(){
freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			scanf("%d",&l[i][j]);
		}
	}
	int ans=0;
	for(int i=m/2;i<=m;i++){
		ans+=w[i];
	}
	printf("%d",ans);
}
