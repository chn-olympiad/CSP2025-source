#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int F,ans,sum;
int a[100005][4];
int dp[205][205][205];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sum=ans=0;
		F=1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(j==3&&a[i][j]!=0) F=0;
			}
			sum+=a[i][1];
		}
		if(F){
			vector<int> v;
			for(int i=1;i<=n;i++){
				v.push_back(a[i][1]-a[i][2]);
			}
			sort(v.begin(),v.end());
			for(int i=0;i<n/2;i++){
				sum-=v[i];
			}
			cout<<sum<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int l=n/2;l>=0;l--){
						if(j+k+l>i) continue;
						if(j-1>=0) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][1]);
						if(k-1>=0) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i][2]);
						if(l-1>=0) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][3]);
						if(i==n) ans=max(ans,dp[j][k][l]);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
