#include<iostream>
#include<cstring>
using namespace std;	
int quan[10005][10005];	
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(quan,0,sizeof(quan));
	for(int i=1;i<=n;i++){
		int u,v,q;
		cin>>u>>v>>q;
		quan[u][v]=q;
		quan[v][u]=q;
	}
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		for(int j=0;j<n;j++){
			int b;
			cin>>b;
			quan[n+i][j]=a+b;
			quan[j][n+1]=a+b;
		}
	}

	for(int i=1;i<=n+k;i++){
		for(int j=i+1;j<n+k;j++){
			ans+=quan[i][j];
		}
	}
	cout<<ans;
	return 0;
} 
