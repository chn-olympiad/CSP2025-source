#include<bits/stdc++.h>
using namespace std;
int n,n2,a[35][3],sum,dp[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		n2=n/2;
		//cout<<1<<' ';
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n2&&j<=i;j++){
				for(int k=0;k<=n2&&k<=i-j;k++){
					int z=i-j-k;
					if(z<0||z>n2)continue;
					if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]);
					if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
					if(z>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
					mx=max(dp[i][j][k],mx);
//					cout<<i<<' '<<j<<' '<<k<<' '<<z<<' '<<dp[i][j][k]<<endl;
				}
			}
		}
		cout<<mx<<endl;
		//cout<<<<' '<<num[0][0]<<' '<<num[0][1]<<' '<<num[0][2]<<endl;
	}
	return 0;
} 
