#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int dp[505][50005][2];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygen.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n && n>503){
		int k=1;
		for(int i=1;i<=n;i++){
			k*=2;
			k=k%998244353;
		}
		k+=998244353;
		cout<<(k-(n+1)-(n*(n-1)/2))%998244353<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	dp[1][a[1]][1]=1;
	dp[1][0][0]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=sum;j++){
			dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%998244353;
			if(j>=a[i]){
				dp[i][j][1]=(dp[i-1][j-a[i]][0]+dp[i-1][j-a[i]][1])%998244353;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=25;j++){
//			cout<<dp[i][j][0]<<'/'<<dp[i][j][1]<<' ';
//		}
//		cout<<endl;
//	}
    int ans=0; 
    for(int i=1;i<=n;i++){
    	for(int j=a[i]*2+1;j<=sum;j++){
    		ans+=dp[i][j][1];
    		ans=ans%998244353;
		}
	}
	cout<<ans<<endl;
	return 0;
}
