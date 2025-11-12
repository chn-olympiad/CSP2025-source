#include<bits/stdc++.h>
using namespace std;
int A[210],B[210],C[210];
int tmp[int(1e5+10)];
long long dp[210][210][210];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		long long ans2=0;
		int n;
		cin>>n;
		if(n>200){
			for(int i=1;i<=n;i++){
				int x;
				cin>>tmp[i]>>x>>x;
			}
			sort(tmp+1,tmp+n+1,greater<int>());
			for(int i=1;i<=n/2;i--){
				ans2+=tmp[i];
			}
			cout<<ans2<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>A[i]>>B[i]>>C[i];
		}
		for(int i=1;i<=n;i++){
			for(int a=0;a<=min(i,n/2);a++){
				for(int b=0;b<=min(n/2,i-a);b++){
						dp[i][a][b]=-1;
						if(i-a-b<=n/2){
							if(a>0) dp[i][a][b]=max(dp[i-1][a-1][b]+A[i],dp[i][a][b]);
							if(b>0) dp[i][a][b]=max(dp[i-1][a][b-1]+B[i],dp[i][a][b]);
							if(i-a-b>0)dp[i][a][b]=max(dp[i-1][a][b]+C[i],dp[i][a][b]);	
						}
				}
			}
		}
		long long ans=0;
			for(int a=0;a<=n/2;a++){
				for(int b=0;b<=n/2;b++){
					if(n-a-b<=n/2)ans=max(ans,dp[n][a][b]);
			}
		}
		cout<<ans<<endl;
	}
}
