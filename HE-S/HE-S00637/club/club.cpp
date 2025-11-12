#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int dp[100001][4];
int cnt[100001][4];
void Main(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	dp[1][1]=a[1];
	dp[1][2]=b[1];
	dp[1][3]=c[1];
	cnt[1][1]=1;
	cnt[1][2]=1;
	cnt[1][3]=1;
	for(int i=2;i<=n;i++){
		if(cnt[i-1][1]<n/2){
			dp[i][1]=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3])+a[i];
			cnt[i][1]=cnt[i-1][1]+1;
		}else{
			dp[i][1]=max(dp[i-1][2],dp[i-1][3])+dp[i-1][1]-a[i-1]+a[i];
		}
		if(cnt[i-1][2]<n/2){
			dp[i][2]=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3])+b[i];
			cnt[i][2]=cnt[i-1][2]+1;
		}else{
			dp[i][2]=max(dp[i-1][1],dp[i-1][3])+dp[i-1][2]-b[i-1]+b[i];
		}
		if(cnt[i-1][3]<n/2){
			dp[i][3]=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3])+c[i];
			cnt[i][3]=cnt[i-1][3]+1;
		}else{
			dp[i][3]=max(dp[i-1][1],dp[i-1][2])+dp[i-1][3]-c[i-1]+c[i];
		}
	}
	cout<<dp[n][1]<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		Main();
	}
	return 0;
}
