#include<bits/stdc++.h>
using namespace std;
struct ins{
	long int x;
	long int w;
	long int z;
};
ins a[1000006];
long int dp[10014][10014];
long int n,m,k;
long int ks=0;
long int jie[10014];
long int mins=1e11;
void suan(){
	long int l=max(n,ks);
	for(long int i=0;i<l;i++){
		for(long int j=0;j<l;j++){
			for(long int k=1;k<=j;k++)
			dp[i][j]=max((long int)0,min(dp[i][j],dp[i][j-k]+dp[j-k][i]));
		}
	}
	for(long int i=0;i<l;i++){
		for(long int j=0;j<l;j++){
			jie[i]+=max((long int)0,dp[i][j]);
		}
		mins=max((long int)0,min(mins,jie[i]));
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long int i=0;i<n+11;i++){
		for(long int j=0;j<n+11;j++){
			dp[i][j]=1e9;
		}
		dp[i][i]=0;
	}
	for(long int i=0;i<m;i++){
		long int u,v,w;
		cin>>u>>v>>w;
		dp[u][v]=w;
		dp[v][u]=w;
		ks=max(ks,u);
		ks=max(ks,v);
	}
	for(long int i=0;i<k;i++){
		long int c;
		cin>>c;
		long int b[n+1];
		for(long int j=1;j<=n;j++){
			cin>>b[j];
			dp[ks][j]=b[j]+c;
			dp[j][ks]=b[j]+c;
			ks++;
		}
	}
	suan();
	cout<<mins;
	
	return 0;
}