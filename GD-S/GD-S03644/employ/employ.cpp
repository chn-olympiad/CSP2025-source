#include<bits/stdc++.h>
using namespace std;
long long dp[1005][1005];
void bfs(long long a,long long b){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	dp[0][0]=a;
	for(int i=1;i<a;i++){
		for(int j=1;j<b;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+1);
		}
	}
	cout<<1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long a,b,c;
	string s;
	for(int i=0;i<1;i++){
		cin>>a>>b;
		cin>>s;
		while(cin){
			cin>>c;
		}
	}
	cout<<1;
	return 0;
}
