#include<iostream>
using namespace std;
int t,n,dp[10001][4][3],l[10001][4];
//dp 1:层数,2:部门,3:种类,(1:the value 2:the number) 
int main(){
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		dp[0][1][2]=dp[0][2][2]=dp[0][3][2]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=2;k++){
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cin>>l[i][1]>>l[i][2]>>l[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(dp[i-1][j][2]<=n/2) dp[i][j][1]=max(dp[i][j][1],dp[i-1][k][1]+l[i][j]),dp[i][j][2]=dp[i-1][j][2]+1;
					else dp[i][j][1]=dp[i-1][j][1],dp[i][j][2]=dp[i-1][j][2];
				}
				
			}

		}
		int maxn=0;
		for(int i=1;i<=3;i++){
			maxn=max(dp[n][i][1],maxn);
		}
		cout<<maxn<<endl;
	}
}
