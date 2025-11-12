#include<bits/stdc++.h>
#include<queue>
using namespace std;
const long long MAXN=1e5+5,MAXM=2e2+5;
long long n,a[MAXN],b[MAXN],c[MAXN],dp[MAXM][MAXM][MAXM],t;
bool cmp(long long a,long long b){return a>b;}
void unit(){
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=n/2;j++){
			for(long long z=0;z<=n/2;z++) dp[i][j][z]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag=true;
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i],flag&=(b[i]==0 && c[i]==0);
		if(flag){
			sort(a+1,a+n+1,cmp);
			long long ans=0;
			for(long long i=1;i<=n/2;i++) ans+=a[i];
			cout<<ans<<endl;
		}
		else if(n<=200){
			unit();
			dp[0][0][0]=0;
			long long maxn=-1;
			for(long long i=1;i<=n;i++){
				dp[i][0][0]=0;
				for(long long j=0;j<=n/2;j++){
					for(long long z=0;z<=n/2;z++){
						long long k=n-j-z;
						if(j!=0) dp[i][j][z]=max(dp[i][j][z],dp[i-1][j-1][z]+a[i]);
						if(z!=0) dp[i][j][z]=max(dp[i][j][z],dp[i-1][j][z-1]+b[i]);
						if(k!=0) dp[i][j][z]=max(dp[i][j][z],dp[i-1][j][z]+c[i]);
//						dp[i][j][z]=max(dp[i-1][j][z-1]+b[i],max(dp[i-1][j-1][z]+a[i],dp[i-1][j][z]+c[i]));
					}
				}
			}
			for(long long i=0;i<=n/2;i++){
				for(long long j=0;j<=n/2;j++) maxn=max(maxn,dp[n][i][j]);
			}
			cout<<maxn<<endl;
		}
	}
	return 0;
}
