#include<bits/stdc++.h>
using namespace std;
//~ #define int long long

int t,n,a[100005],b[100005],c[100005],dp[305][305][305];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		bool A=1,B=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]||c[i]){
				A=0;
				if(c[i])B=0;
			}
		}
		if(A){
			sort(a+1,a+n+1,greater<int>());
			int ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof dp);
		for(int i1=1;i1<=n;i1++){
			for(int i2=1;i2<=i1&&i2<=n/2;i2++){
				for(int i3=1;i3<=n/2;i3++){
					if(i1-i2-i3<=n/2){
						if(i2>0&&i3<=i1-1&&i1-i2-i3<=i1-1)dp[i1][i2][i3]=max(dp[i1][i2][i3],dp[i1-1][i2-1][i3]+a[i1]);
						if(i3>0&&i2<=i1-1&&i1-i2-i3<=i1-1)dp[i1][i2][i3]=max(dp[i1][i2][i3],dp[i1-1][i2][i3-1]+b[i1]);
						if(i2<=i1-1&&i3<=i1-1)dp[i1][i2][i3]=max(dp[i1][i2][i3],dp[i1-1][i2][i3]+c[i1]);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ans=max(ans,dp[n][i][j]);
		cout<<ans<<endl;
	}
	return 0;
}
