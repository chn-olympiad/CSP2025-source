#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
int T,n,dp[N][N],ans=0;
struct ccf{
	int x,y,z;
}a[N];
void init(){
	ans=0;
	memset(dp,0,sizeof dp);
}
bool cmp(ccf a,ccf b){
	if(a.x-a.y==b.x-b.y) return a.z>b.z;
	return a.x-a.y>b.x-b.y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		init();
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i,j<=n/2;j++){
				if(i<n/2) dp[i][j]=dp[i-1][j]+a[i].x;
				else if(i>n/2) dp[i][j]=dp[i-1][j]+a[i].y;
				else if(i==n/2&&a[i].x+a[i+1].y<a[i+1].x+a[i].y) dp[i][j]=dp[i-1][j]+a[i].y;
				else if(i==n/2&&a[i].x+a[i+1].y>=a[i+1].x+a[i].y) dp[i][j]=dp[i-1][j]+a[i].x;
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i].z);
				if(i==n) ans=max(ans,dp[i][j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

