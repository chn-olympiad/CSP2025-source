#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100005][4],ans=0,dp[2][10005][10005],b[100005];
priority_queue<pair<ll,int> >p,q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=0;
		if(n>10000){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--){
				ans+=b[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[0][i][j]=0,dp[1][i][j]=0;
		for(ll i=1;i<=n;i++){
			for(ll j=min(i,n/2);j>=0;j--){
				for(ll k=min(i-j,n/2);k>=0;k--){
					if(i-j-k>n/2) break;
					if(j>=1) dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j-1][k]+a[i][1]);
					if(k>=1) dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j][k-1]+a[i][2]);
					if(i-j-k>=1) dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][j][k]+a[i][3]);
					if(i==n) ans=max(ans,dp[i%2][j][k]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
