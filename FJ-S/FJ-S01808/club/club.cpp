#include<bits/stdc++.h>
using namespace std;
long long T;
long long n,ans,st,sj,sh,sk;
struct sd{
	long long p1,p2,p3;
}a[100005];
long long dp[105][105][105];
int cmp(sd A,sd B){
	return A.p1>B.p1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].p1,&a[i].p2,&a[i].p3);
		}
		if(n<=200){
			st=n/2;
			for(int i=0;i<=st;i++){
				for(int j=0;j<=st;j++){
					for(int k=0;k<=st;k++){
						dp[i][j][k]=0;
					}
				}
			}
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++){
				sj=min((long long)i,st);
				for(int j=sj;j>=0;j--){
					for(int h=sj;h>=0;h--){
						for(int k=sj;k>=0;k--){
							dp[j][h][k]=0;
							if(!(j==0&&h==0&&k==0)){
								if(j>=1) dp[j][h][k]=max(dp[j][h][k],dp[j-1][h][k]+a[i].p1);
								if(h>=1) dp[j][h][k]=max(dp[j][h][k],dp[j][h-1][k]+a[i].p2);
								if(k>=1) dp[j][h][k]=max(dp[j][h][k],dp[j][h][k-1]+a[i].p3);
							}
						}
					}
				}
			}
			for(int i=0;i<=st;i++){
				for(int j=0;j<=st;j++){
					for(int k=0;k<=st;k++){
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
			printf("%lld\n",ans);
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i].p2;
				a[i].p1-=a[i].p2;
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].p1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}