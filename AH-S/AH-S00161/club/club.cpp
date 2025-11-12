#include<bits/stdc++.h>
#define ll long long
ll a[100005][5],dp[100005][5],n,ans,t;
struct node{
	ll f,s,t;
}sum[100005][5];
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>a[i][j];
		if (n==2){
		cout<<max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))))<<'\n';
		continue;
		}
		for (int i=2;i<=n;i++){
			for (int j=1;j<=3;j++){
				if (j==1){
					if (sum[i-1][1].f+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][1]);
						sum[i][j].f=sum[i-1][1].f+1;
						sum[i][j].s=sum[i-1][1].s;
						sum[i][j].t=sum[i-1][1].t;
						}
					if (sum[i-1][2].f+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][2]);
						sum[i][j].f=sum[i-1][2].f+1;
						sum[i][j].s=sum[i-1][2].s;
						sum[i][j].t=sum[i-1][2].t;
						}
					if (sum[i-1][3].f+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][3]);
						sum[i][j].f=sum[i-1][3].f+1;
						sum[i][j].s=sum[i-1][3].s;
						sum[i][j].t=sum[i-1][3].t;
						}
						}
				if (j==2){
					if (sum[i-1][1].s+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][1]);
						sum[i][j].f=sum[i-1][1].f;
						sum[i][j].s=sum[i-1][1].s+1;
						sum[i][j].t=sum[i-1][1].t;}
					if (sum[i-1][2].s+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][2]); 
						sum[i][j].f=sum[i-1][2].f;
						sum[i][j].s=sum[i-1][2].s+1;
						sum[i][j].t=sum[i-1][2].t;}
					if (sum[i-1][3].s+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][3]);
						sum[i][j].f=sum[i-1][2].f;
						sum[i][j].s=sum[i-1][2].s+1;
						sum[i][j].t=sum[i-1][2].t;
						}
						}
				if (j==3){
					if (sum[i-1][1].t+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][1]);
						sum[i][j].f=sum[i-1][1].f;
						sum[i][j].s=sum[i-1][1].s;
						sum[i][j].t=sum[i-1][1].t+1;
						}
					if (sum[i-1][2].t+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][2]);
						sum[i][j].f=sum[i-1][2].f;
						sum[i][j].s=sum[i-1][2].s;
						sum[i][j].t=sum[i-1][2].t+1;
						}
					if (sum[i-1][3].t+1<=n/2){
						dp[i][j]=max(dp[i][j],a[i][j]+dp[i-1][3]);
						sum[i][j].f=sum[i-1][3].f;
						sum[i][j].s=sum[i-1][3].s;
						sum[i][j].t=sum[i-1][3].t+1;
						}
						}
				}
			}
			for (int i=1;i<=3;i++)
				ans=max(ans,dp[n][i]);
		cout<<ans<<'\n';
	}
	return 0;
}
