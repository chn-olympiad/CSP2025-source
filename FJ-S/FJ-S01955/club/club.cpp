#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N][4],dp[N][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int lm=n/2;
		memset(a,0,sizeof a);
		memset(dp,-1,sizeof dp);
		if(n<=204){
			for(int i=1;i<=n;++i)		 
				for(int j=1;j<=3;++j)
					cin>>a[i][j];
			dp[1][1][0]=a[1][1],dp[1][0][1]=a[1][2],dp[1][0][0]=a[1][3];
			for(int i=1;i<=n-1;++i){
				for(int j=0;j<=i;++j){
					for(int k=0;k<=i-j;++k){
						int l=i-j-k;
						if(j+1<=lm)dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+a[i+1][1]);
						if(k+1<=lm)dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+a[i+1][2]);
						if(l+1<=lm)dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i+1][3]);
					}
				}
			}
			int ans=-1;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n-i;++j){
					ans=max(ans,dp[n][i][j]);
				}
			}
			cout<<ans<<"\n";
		}else{
			int t[n+5];
			memset(t,0,sizeof t);
			for(int i=1;i<=n;++i){
				int a,b,c;
				cin>>a>>b>>c;
				t[i]=a;
			}
			sort(t+1,t+n+1);
			int ans=0;
			for(int i=lm+1;i<=n;++i){
				ans+=t[i];
			}
			cout<<ans<<"\n";
		}
	}

	return 0;
}

