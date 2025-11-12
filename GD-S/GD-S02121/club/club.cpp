#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=205;
struct club{
	int x,y,z;
}a[N];
int dp[N][N][N];
//when student is i,has j-number to choose a,else k-number choose b  
void sol(){
	memset(dp,0,sizeof dp);
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	dp[1][0][0]=a[1].z;
	dp[1][1][0]=a[1].x;
	dp[1][0][1]=a[1].y;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(j!=0 and dp[i-1][j-1][k]!=0) dp[i][j][k]=max(dp[i-1][j-1][k]+a[i].x,dp[i][j][k]);
				if(k!=0 and dp[i-1][j][k-1]!=0) dp[i][j][k]=max(dp[i-1][j][k-1]+a[i].y,dp[i][j][k]);
				if(dp[i-1][j][k]!=0) dp[i][j][k]=max(dp[i-1][j][k]+a[i].z,dp[i][j][k]);
			}
		}
	}
	for(int j=0;j<=n/2;j++){
		for(int k=(n/2)-j;k<=n/2;k++){
			ans=max(ans,dp[n][j][k]);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int quest;
	ios::sync_with_stdio(0);
	cin>>quest;
	while(quest--) sol();
	return 0;
}
//orz sto %%% Juruo want to be in luogu. 
//afo,love mois forever
