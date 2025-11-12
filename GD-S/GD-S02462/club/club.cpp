#include<bits/stdc++.h>
using namespace std;
const int N=205;
int t,n;
int a[N][5];
int dp[N][N/2][N/2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
			}
		}
		int maxl=INT_MIN;
		for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					maxl=max(maxl,dp[n][j][k]);	
					//cout<<dp[n][j][k]<<" ";
				}
				//cout<<endl;
			}
		cout<<maxl<<"\n";;
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


1
2
10 9 8
4 0 0
*/
