#include<bits/stdc++.h>
using namespace std;
int i,n,t,k1,k2,k3,a[4][201],a1[100001],a2[100001],a3[100001],j,dp[210][210][2],m,ans;
const int q=201;
void f(){
	int dp1[50001];
	for(i=1;i<=n;i++)cin>>a[1][i]>>a[2][i]>>a[3][i];
	for(i=1;i<=n;i++){
		for(k1=i;k1>=0;k1--){
			k2=i-k1;
			if(k1<=n/2&&k2<=n/2){
				dp1[k1]=max(dp1[k1]+a[2][i],dp1[k1-1]+a[1][i]);
			}
		}
	}
	cout<<dp1[n/2]<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		if(n>200){
			f();
			continue;
		}
		for(i=1;i<=n;i++)cin>>a[1][i]>>a[2][i]>>a[3][i];
		for(i=0;i<=n/2;i++){
			for(j=0;j<=n/2;j++){
				dp[i][j][0]=dp[i][j][1]=0;
			}
		}
		for(i=1;i<=n;i++){
			for(k1=i;k1>=0;k1--){
				for(k2=i-k1;k2>=0;k2--){
					k3=i-k1-k2;
					if(k3>n/2||k1>n/2||k2>n/2)continue;
					if(k1>0)dp[k1][k2][1]=max(a[1][i]+dp[k1-1][k2][0],dp[k1][k2][1]);
					if(k2>0)dp[k1][k2][1]=max(a[2][i]+dp[k1][k2-1][0],dp[k1][k2][1]);
					if(k3>0)dp[k1][k2][1]=max(a[3][i]+dp[k1][k2][0],dp[k1][k2][1]);
				}
			}
			for(k1=i;k1>=0;k1--){
				for(k2=i-k1;k2>=0;k2--){
					k3=i-k1-k2;
					if(k3<0||k3>n/2||k1>n/2||k2>n/2)continue;
					dp[k1][k2][0]=dp[k1][k2][1];
					dp[k1][k2][1]=0;
				}
			}
		}
		ans=0;
		for(k1=0;k1<=n/2;k1++){
			for(k2=0;k2<=n/2;k2++){
				k3=n-k1-k2;
				if(k3>n/2||k3<0)continue;
				ans=max(ans,dp[k1][k2][0]);
			}
		}
		cout<<ans<<endl;
	}
}
