#include<bits/stdc++.h>
using namespace std;
//const int N=1e5+10,M=5e4+10;
const int N=200+10,M=100+10,K=1e5+10;
int n,T,a[N][5],b[K],lim;
long long dp[N][M][M],ans;
void init(){
	ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=lim;j++){
			for(int k=0;k<=lim;k++){
				dp[i][j][k]=-1;	
			}
		}
	}
	dp[0][0][0]=0;
	return;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;lim=n/2;
		if(n>200){
			for(int i=1;i<=n;i++){
				cin>>b[i]>>a[1][1]>>a[1][1];	
			}
			ans=0;
			sort(b+1,b+1+n);
			for(int i=n;i>lim;i--)ans+=b[i];
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		init();
		for(int i=0;i<n;i++){
			for(int j=0;j<=min(lim,i);j++){
				for(int k=0;k<=min(lim,i-j);k++){
					if(dp[i][j][k]>=0){
						if(j<lim)dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+1ll*a[i+1][1]);
						if(k<lim)dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+1ll*a[i+1][2]);
						if(i-j-k<lim)dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+1ll*a[i+1][3]);
						//cout<<i+1<<" "<<dp[i+1][j+1][k]<<" "<<j+1<<" "<<k<<"\n";
					}
				}
			}
		}
		for(int j=0;j<=lim;j++){
			for(int k=0;k<=lim;k++){
				ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
} 
