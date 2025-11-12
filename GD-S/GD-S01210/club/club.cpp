#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int T,n,a[maxn][5],A,B;
ll dp[205][205][205],ans;
ll dpb[5005][5005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >>T;
	while(T--){
		ans=0; B=1; A=1;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0&&a[i][2]!=0) A=0;
			if(a[i][3]!=0) B=0;
		}
		if(A){
			int b[maxn];
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			ll ans=0;
			for(int i=n;i>=n/2;i--) ans+=b[i];
			cout <<ans;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		for(int j=0;j<=min(i,n/2);j++)
		for(int k=0;k<=min(i-j,n/2);k++){
			int l=i-j-k;
			if(l>n/2) continue;
			if(l!=0) dp[i][j][k]=max(dp[i][j][k],
				dp[i-1][j][k]+a[i][3]);
			if(j!=0) dp[i][j][k]=max(dp[i][j][k],
				dp[i-1][j-1][k]+a[i][1]);
			if(k!=0) dp[i][j][k]=max(dp[i][j][k],
				dp[i-1][j][k-1]+a[i][2]);
		}
		for(int j=0;j<=n/2;j++)
		for(int k=0;k<=n/2;k++){
			int l=n-j-k;
			if(l>n/2) continue;
			ans=max(ans,dp[n][j][k]);
		}
		cout <<ans<<endl;
	}
	return 0;
}
