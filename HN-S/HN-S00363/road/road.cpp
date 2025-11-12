#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,k,b[10005][10005],c[20],fl[10005];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}		
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>b[i][j],b[j][i]=b[i][j];
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(a[i][k]==0||a[k][j]==0) continue;
				if(a[i][j]==0||a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
			}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}*/
	cout<<ans;
	return 0;
}

