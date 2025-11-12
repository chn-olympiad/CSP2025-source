#include<bits/stdc++.h>
using namespace std;
long long t,n,sum=0,a[100099][4],dp[100099][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		sum=0;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]);	
			}
		}
		cout<<dp[n][3];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
