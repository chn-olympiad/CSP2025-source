#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long a[10015][10015]={};
	int v,w,u;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	int b,c[15];
	int minn=11111111111111111111111111;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		minn=min(c[j],minn);
		for(int i=1;i<=n;i++){
			cin>>b;
			a[j+n][i]=b;
			a[i][j+n]=b;
		}
	}
	int sum=0;
	int d[10015][10015]={};
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(d[i][j]!=1){
				sum+=a[i][j];
				d[i][j]=1;
				d[j][i]=1;
			}
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
