#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,dp[201][201][201],dp2[2001][2001],g;
lo a[100001],b[100001],c[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&g);
	while(g--){
		scanf("%lld",&n);
		//lo n1,n2,n3;
		ss=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		}
		if(n*n*n<10000000){
			for(i=0;i<=1;i++){
				for(j=0;j<=n/2;j++){
					for(k=0;k<=n/2;k++) dp[i][j][k]=0;
				}
			}
			for(i=1;i<=n;i++){
				//cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<"\n";
				for(j=0;j<=min(i,n/2);j++){
					for(k=0;k<=min(i-j,n/2);k++){
						if(i-j-k>n/2)continue;
						if(j>=1&&k>=1)dp[i][j][k]=max(dp[i-1][j-1][k]+a[i],max(dp[i-1][j][k-1]+b[i],dp[i-1][j][k]+c[i]));
						else if(j>=1)dp[i][j][k]=max(dp[i-1][j-1][k]+a[i],dp[i-1][j][k]+c[i]);
						else if(k>=1)dp[i][j][k]=max(dp[i-1][j][k-1]+b[i],dp[i-1][j][k]+c[i]);
						else dp[i][j][k]=dp[i-1][j][k]+c[i];
						//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<"\n";
					}
				}
			}
			for(i=0;i<=n/2;i++){
				for(j=0;j<=n/2;j++){
					ss=max(ss,dp[n][i][j]);
				}
			}
		}
		else if(n<=2000){
			for(i=1;i<=n;i++){
				for(j=0;j<=min(i,n/2);j++){
					if(!j)dp2[i][j]=dp2[i-1][j]+b[i];
					else dp2[i][j]=max(dp2[i-1][j]+b[i],dp2[i-1][j-1]+a[i]);
				}
			}
			for(i=0;i<=n/2;i++){
				ss=max(ss,dp2[n][i]);
			}
		}
		else{
			sort(a+1,a+n+1);
			for(i=n;i>n/2;i--){
				ss+=a[i];
			}
		}
		printf("%lld\n",ss);
	}
	return 0;
}
