#include<bits/stdc++.h>
using namespace std;
#define int long long 
int T;
const int MAXN=1e3+1;
int n;
int ans=0;
//struct node{
//	int a1,a2,a3;
//}x[MAXN];
int a[MAXN][5];
int dp[MAXN][4][MAXN/2];


signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		n=0;
		ans=0;
		for(int i=0;i<=n+1;i++){
			for(int j=1;j<=4;j++){
				a[i][j]=0;
				for(int k=1;k<=n/2;k++){
					dp[i][j][k]=0;
				}
			}
		}
//		for(int i=0;i<=1e6+5;i++){
//			x[i].a1=0;
//			x[i].a2=0;
//			x[i].a3=0;
//		}

		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				int res=-INT_MAX;
				for(int j=1;j<=3&&j!=i;j++){
					res=max(res,a[2][j]+a[1][i]);
				}
				ans=max(ans,res);
			}
			cout<<ans<<"\n";
			continue;
		}
		int cnt1=0,cnt2=0,cnt3=0;
		dp[1][1][1]=a[1][1];
		dp[1][2][1]=a[1][2];
		dp[1][3][1]=a[1][3];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=n/2;k++){
					if(j==1){
						dp[i][j][k]+=dp[i-1][1][k-1]+dp[i-1][2][k]+dp[i-1][3][k];
					} 
					else if(j==2) dp[i][j][k]+=dp[i-1][2][k-1]+dp[i-1][2][k]+dp[i-1][3][k];
					else dp[i][j][k]+=dp[i-1][3][k-1]+dp[i-1][2][k]+dp[i-1][1][k];
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n/2;j++){
				ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
 
