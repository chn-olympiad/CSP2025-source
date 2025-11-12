#include<bits/stdc++.h>
using namespace std;
const int SZ=1e5+7;
int t,n,g[SZ][3],dp[SZ][3];
void dfs(int x,int a,int b,int c){
	if(x==n+1&&a<=n/2&&b<=n/2&&c<=n/2)return;
	if(a<n/2){
		dp[x][0]=max({dp[x-1][0],dp[x-1][1],dp[x-1][2]})+g[x][0];
		dfs(x+1,a++,b,c);
	}
	if(b<n/2){
		dp[x][1]=max({dp[x-1][0],dp[x-1][1],dp[x-1][2]})+g[x][1];
		dfs(x+1,a,b++,c);
	}
	if(c<n/2){
		dp[x][2]=max({dp[x-1][0],dp[x-1][1],dp[x-1][2]})+g[x][2];
		dfs(x+1,a,b,c++);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>g[i][0]>>g[i][1]>>g[i][2];
			for(int j=0;j<=2;j++){
				dp[i][j]=0;
			}
		}
		dfs(1,0,0,0);
		cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<'\n';
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/