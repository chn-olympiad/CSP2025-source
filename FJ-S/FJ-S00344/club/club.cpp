#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e5+5;
long long t,n,zd,ans1,ans,dp1[MAXN][4][4],dp[MAXN],a[MAXN][4],f;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		n=0,zd=0,ans=0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		scanf("%lld",&n);
		zd=n/2;
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) {
				f=1;
			}
			dp[i]=a[i][1];
			ans+=max(a[i][1],a[i][2]);
		}
		if(f==0) {
			sort(dp+1,dp+n+1);
			for(int i=n;i>=n-zd+1;i--){
				ans1+=dp[i];
			}
			printf("%lld",ans1);
			return 0;
		} else if(n==2) {
			long long cnt[7],maxx=-1;
			cnt[1]=a[1][1]+a[2][2];
			cnt[2]=a[1][1]+a[2][3];
			cnt[3]=a[1][2]+a[2][1];
			cnt[4]=a[1][2]+a[2][3];
			cnt[5]=a[1][3]+a[2][1];
			cnt[6]=a[1][3]+a[2][2];
			for(int i=1; i<=6; i++) {
				maxx=max(maxx,cnt[i]);
			}
			printf("%lld",maxx);
			return 0;
		}
//		cout<<dp[n].a1+dp[n].b2+dp[n].c3<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
