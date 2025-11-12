#include<bits/stdc++.h> 
using namespace std; 
int n,m,zi,u,v,w;
int f[1005][1005],a[10005],c,cnt;


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>zi;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		f[u][v]=w;	
		f[v][u]=w;	
	}
	for(int i=1;i<=n;i++)f[i][i]=1;
	cin>>c;
	for(int i=1;i<=zi;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j]>f[i][k]+f[j][k]){
					f[i][j]=f[i][k]+f[j][k];
				}
			}
		}
	}
	for(int j=1;j<=n;j++){
		cnt+=f[1][j];
	}
	cout<<cnt;
	return 0;
}

