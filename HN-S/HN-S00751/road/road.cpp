#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,w,k,a[15][10005],c[10005],f[1005][1005],d[1005][1005],f1[1005][1005],f2[1005][1005];
vector<int>ve[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ve[u].push_back(v);
		ve[v].push_back(u);
		f[u][v]=w;
		f[v][u]=w;
		f1[u][v]=f1[v][u]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		sum+=c[i];
		for(int j=1;j<=n;j++){
			if(!f2[i][j]){
				if((!f1[i][j])||((f1[i][j])&&(f[i][j]>=d[i][j]))){
					f2[i][j]=1;
					sum+=d[i][j];
				}
				else if((f1[i][j])&&(f[i][j]<d[i][j])){
					f2[i][j]=1;
					sum+=f[i][j];
				}	
			}
		}
	}
	cout<<sum;
	return 0;
}
