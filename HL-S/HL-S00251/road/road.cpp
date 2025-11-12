#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,c,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		for(int j=1;j<=w;j++){
			cin>>u[i];
			for(int j=1;j<=u;j++){
				sum+=u[i];
			}
		}
		sum++;
	}
	cout<<sum;
	return 0;
}