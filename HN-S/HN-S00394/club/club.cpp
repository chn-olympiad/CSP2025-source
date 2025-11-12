#include<bits/stdc++.h>
using namespace std;
long long int a[4][100005];
long long int dp[4][100005];
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		int da1=1,da2=1,da3=1;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			a[0][i]=a[1][i]+a[2][i]+a[3][i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[0][i]>a[0][j]){
					swap(a[0][i],a[0][j]);
					swap(a[1][i],a[1][j]);
					swap(a[2][i],a[2][j]);
					swap(a[3][i],a[3][j]);
				}
			}
		}
		dp[0][1]=max(a[1][1],max(a[2][1],a[3][1]));
		dp[1][1]=a[1][1];
		dp[2][1]=a[2][1];
		dp[3][1]=a[3][1];
		if(n==2){
			for(int i=1;i<=n;i++){
				dp[1][i]=max(dp[2][i-1],dp[3][i-1])+a[1][i];
				dp[2][i]=max(dp[1][i-1],dp[3][i-1])+a[2][i];
				dp[3][i]=max(dp[2][i-1],dp[1][i-1])+a[3][i];
			}
			cout<<max(max(dp[1][n],dp[2][n]),dp[3][n])<<endl;
		}
		else{
			for(int i=2;i<=n;i++){
				if(da1<n/2){
					dp[1][i]=dp[0][i-1]+a[1][i];
				}
				if(da2<n/2){
					dp[2][i]=dp[0][i-1]+a[2][i];
				}
				if(da3<n/2){
					dp[3][i]=dp[0][i-1]+a[3][i];
				}
				if(max(max(dp[1][i],dp[2][i]),dp[3][i])==dp[1][i]){
					dp[0][i]=dp[1][i];
					da1++;
				}
				else if(max(max(dp[1][i],dp[2][i]),dp[3][i])==dp[2][i]){
					dp[0][i]=dp[2][i];
					da2++;
				}
				else if(max(max(dp[1][i],dp[2][i]),dp[3][i])==dp[3][i]){
					dp[0][i]=dp[3][i];
					da3++;
				}
			}
			cout<<dp[0][n]<<endl;	
		}
	}
	return 0;
}
