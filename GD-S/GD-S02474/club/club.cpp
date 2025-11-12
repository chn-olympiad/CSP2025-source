#include<bits/stdc++.h>
#define int long long
using namespace std;
int Q,n;
int a[500007],b[500007],c[500007];
int dp[207][207][207];//到i A放了j个 B放了k个 的最大值 
int pd[207][207];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Q;
	for(int q=1;q<=Q;++q){
		cin>>n;
		int cc=1,bb=1;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]>0) bb=0;
			if(c[i]>0) cc=0;
		}
		int ans=0; 
		if(bb==1){
			sort(a+1,a+1+n);
			for(int i=n/2+1;i<=n;++i) ans+=a[i];
			cout<<ans<<"\n";
		}else if(cc==1){
			memset(pd,-0x3f3f3f3f,sizeof(pd));
			pd[0][0]=0;
			for(int i=1;i<=n;++i){
				for(int j=min(i,n/2);j>=0;--j){
					if(i-j>n/2) continue;
					pd[i][j]=pd[i-1][j]+b[i];
					if(j>0) pd[i][j]=max(pd[i][j],pd[i-1][j-1]+a[i]);
				}
			}
//			cout<<"0 1 2 3\n-------\n";
//			for(int i=1;i<=n;++i){
//				for(int j=0;j<=n/2;++j){
//					cout<<pd[i][j]<<" ";
//				}
//				cout<<"\n";
//			}
			cout<<pd[n][n/2]<<"\n";
		}else{
			memset(dp,-0x3f3f3f3f,sizeof(dp));
			dp[0][0][0]=0;
			for(int i=1;i<=n;++i){
				for(int j=min(i,n/2);j>=0;--j){
					for(int k=min({i-j,n/2});k>=0;--k){
						if(i-j-k>n/2) continue;
						dp[i][j][k]=dp[i-1][j][k]+c[i];
						if(j>0){
							dp[i][j][k]=max(dp[i-1][j-1][k]+a[i],dp[i][j][k]);
						}
						if(k>0){
							dp[i][j][k]=max(dp[i-1][j][k-1]+b[i],dp[i][j][k]);
						}
					}
				}
			}
			int mx=0;
			for(int j=0;j<=n/2;++j){
				for(int k=0;k<=n/2;++k){
					int cc=n-j-k;
					if(cc>n/2||j>n/2||k>n/2) continue;
					mx=max(mx,dp[n][j][k]);
//					cout<<j<<" "<<k<<" "<<cc<<" "<<dp[n][j][k]<<"\n";
				}
			}
			cout<<mx<<"\n";
		}
	}
	return 0;
}
