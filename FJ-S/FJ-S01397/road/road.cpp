#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int c[1000005][1000005];
int dp[1000005][1000005]
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum1=0,sum2=0,sum3=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum1+=w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
		}
		sum2+=c[i][1];
	}
	cout<<sum1;
	return 0;
}
