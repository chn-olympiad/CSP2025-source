#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int n,dp[205][105][105][105];
bool cmp1(node x,node y){
	return x.x>y.x;
}
bool cmp2(node x,node y){
	return x.x-x.y>y.x-y.y;
}
void solve(){
	cin>>n;
	int cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(n/2,i);j++)
			for(int k=0;k<=min(i-j,n/2);k++)
				for(int l=0;l<=min(i-j-k,n/2);l++)
					dp[i][j][k][l]=0;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z,cnt2+=(a[i].y==0),cnt3+=(a[i].z==0);
	if(cnt2==n&&cnt3==n){
		sort(a+1,a+n+1,cmp1);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[i].x;
		cout<<ans<<"\n";
		return;
	}
	else if(cnt3==n){
		sort(a+1,a+n+1,cmp2);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[i].x;
		for(int i=n/2+1;i<=n;i++)ans+=a[i].y;
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(n/2,i);j++)
			for(int k=0;k<=min(i-j,n/2);k++)
				for(int l=0;l<=min(i-j-k,n/2);l++){
					if(j>0)dp[i][j][k][l]=max(dp[i-1][j-1][k][l]+a[i].x,dp[i][j][k][l]);
					if(k>0)dp[i][j][k][l]=max(dp[i-1][j][k-1][l]+a[i].y,dp[i][j][k][l]);
					if(l>0)dp[i][j][k][l]=max(dp[i-1][j][k][l-1]+a[i].z,dp[i][j][k][l]);
				}
	int ans=0;
	for(int j=0;j<=n/2;j++)
		for(int k=0;k<=min(n-j,n/2);k++)
			for(int l=0;l<=min(n-j-k,n/2);l++){
				ans=max(ans,dp[n][j][k][l]);
			}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}