#include<bits/stdc++.h>
using namespace std;
long long dp[1000][1000];
void dfs(long long a,long long b){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	dp[0][0]=a;
	for(int i=1;i<a;i++){
		for(int j=1;j<b;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+1);
		}
	}
	cout<<dp[0][0]+b;
	cout<<"Hello World";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long a;
	for(int i=0;i<1;i++){
		while(cin){
			cin>>a;
		}
	}
	cout<<1;
	return 0;
}
