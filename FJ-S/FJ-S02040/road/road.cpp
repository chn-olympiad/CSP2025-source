#include<bits/stdc++.h>
using namespace std;

int n,k;
long long m;
long long ans=0;
long long road[10005][10005];
long long country[15][10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	int u,v;

	for(long long i=1;i<=m;i++){
		int t;
		cin>>u>>v>>t;
		road[u][v]=t;
		road[v][u]=t;
	}
	for(int i=1;i<=k;i++){
		int v;
		cin>>v;
		for(int j=1;j<=n;j++){
			cin>>country[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int s=j+1;s<=n;s++){	
				if(road[j][s]==0)
					road[j][s]=v+country[i][j]+country[i][s];
				else if(v+country[i][j]+country[i][s]<road[j][s])
					road[j][s]=v+country[i][j]+country[i][s];
			}
		}
	}
	for(int i=1;i<n;i++){
		long long t=99999999;
		for(int j=1;j<=n;j++){
			if(road[i][j]!=0)
				t=min(t,road[i][j]);
		}
		ans+=t;
	}	
	cout<<ans;
	return 0;
}
