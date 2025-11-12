#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int aa[100005];
int dp[2][205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		bool special_data=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			special_data&=bool(a[i][1]==0&&a[i][2]==0);
			aa[i]=a[i][0];
		}
		if(special_data){
			sort(aa+1,aa+1+n);
			int ans=0;
			for(int i=n;i>n/2;i--)ans+=aa[i];
			cout<<ans<<"\n";
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<=n/2&&k<=i;k++){
					if(j==0&&k==0)continue;
					for(int l=0;l<=n/2&&l<=i;l++){
						if(j==1&&l==0)continue;
						int p=i-k-l;
						if(p<0||p>n/2)continue;
						if(j==2&&p==0)continue;
						if(j==0)dp[i&1][k][l][p]=max(dp[i&1][k][l][p],dp[i&1^1][k-1][l][p]+a[i][j]);
						else if(j==1)dp[i&1][k][l][p]=max(dp[i&1][k][l][p],dp[i&1^1][k][l-1][p]+a[i][j]);
						else if(j==2)dp[i&1][k][l][p]=max(dp[i&1][k][l][p],dp[i&1^1][k][l][p-1]+a[i][j]);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				int k=n-i-j;
				if(k>n/2)continue;
				ans=max(ans,dp[n&1][i][j][k]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
