#include<bits/stdc++.h>
using namespace std;
struct p{
	long long int a1,a2,a3;
}v[100005];
int t,n;
int dp[105][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>v[j].a1>>v[j].a2>>v[j].a3;
			dp[i][j] = max(max(v[j].a1,v[j].a2),max(v[j].a2,v[j].a3));
			for(int k=1;k<=n/2;k++){
				dp[j][k] = max(dp[j-1][k],dp[j-1][k-1]+dp[j][k]);
				cout<<dp[j][k]<<endl;
			}
		}
		cout<<dp[n][n/2]<<"\n";
	}
	
	return 0;
}
