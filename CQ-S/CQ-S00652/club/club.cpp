//club
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
namespace _746969_{
	int n,dp[105][105][105],a[205],b[205],c[205],maxp,ans;
	signed main(){
		int T;
		cin>>T;
		while(T--){
			cin>>n;
			maxp=n>>1;
			memset(dp,ans=0,sizeof(dp));
			for(int i=1;i<=n;i++)
				cin>>a[i]>>b[i]>>c[i];
			for(int ii=1;ii<=n;ii++)
				for(int i=0;i<=min(ii,maxp);i++)
					for(int j=0;j<=min(ii-i,maxp);j++){
						if(ii-maxp>i+j)
							continue;
						if(i)
							dp[i][j][ii-i-j]=max(dp[i-1][j][ii-i-j]+a[ii],dp[i][j][ii-i-j]);
						if(j)
							dp[i][j][ii-i-j]=max(dp[i][j-1][ii-i-j]+b[ii],dp[i][j][ii-i-j]);
						if(ii-i-j)
							dp[i][j][ii-i-j]=max(dp[i][j][ii-i-j-1]+c[ii],dp[i][j][ii-i-j]);
						ans=max(ans,dp[i][j][ii-i-j]);
					}
			cout<<ans<<"\n";
		}
		return 0;
	}
};
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return _746969_::main();
}