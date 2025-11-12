#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,t,ans,a[N][4];
struct stu{
	ll val,num[4];
}dp[N][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++){
			dp[i][j].val=0;
			for(int k=1;k<=3;k++)
			dp[i][j].num[k]=0;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++){
			if(dp[i-1][1].num[j]<n/2){
				if(dp[i][j].val<dp[i-1][1].val+a[i][j]){
					dp[i][j].val=dp[i-1][1].val+a[i][j];
					for(int k=1;k<=3;k++)
					dp[i][j].num[k]=dp[i-1][1].num[k];
					dp[i][j].num[j]++;
				}
			}
			if(dp[i-1][2].num[j]<n/2){
				if(dp[i][j].val<dp[i-1][2].val+a[i][j]){
					dp[i][j].val=dp[i-1][2].val+a[i][j];
					for(int k=1;k<=3;k++)
					dp[i][j].num[k]=dp[i-1][2].num[k];
					dp[i][j].num[j]++;
				}
			}
			if(dp[i-1][3].num[j]<n/2){
				if(dp[i][j].val<dp[i-1][3].val+a[i][j]){
					dp[i][j].val=dp[i-1][3].val+a[i][j];
					for(int k=1;k<=3;k++)
					dp[i][j].num[k]=dp[i-1][3].num[k];
					dp[i][j].num[j]++;
				}
			}
		}
		cout<<max(dp[n][1].val,max(dp[n][2].val,dp[n][3].val))<<'\n';
	}
	return 0;
}
