#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 205
struct node{
	int x,y,z;
}a[N];
int t,n,ans,dp[N][N][N],cnt1,cnt2;
bool cmp(node a,node b){
	return a.x>b.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0) cnt1=1;//是否为特殊性质A 1:不是 2:是
			if(a[i].z!=0) cnt1=1,cnt2=1;//是否为特殊性质B 1:不是 2:是
		} 
		if(cnt1==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
//		if(n<=200){
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++) dp[i][j][k]=0;
			}
		}
		for(int xx=1;xx<=n;xx++){
//			cout<<"Round"<<xx<<endl;
			for(int i=n/2;i>=0;i--){
				for(int j=min(xx-i,n/2);j>=0;j--){
					if(xx-i-j>0) dp[i][j][xx-i-j]=max(dp[i][j][xx-i-j],dp[i][j][xx-i-j-1]+a[xx].z);//,cout<<"dp["<<i<<"]["<<j<<"]=max(dp["<<i<<"]["<<j<<"]+a["<<xx<<"].z,dp["<<i<<"]["<<j<<"])="<<dp[i][j][xx-i-j]<<endl;
					if(i>0) dp[i][j][xx-i-j]=max(dp[i-1][j][xx-i-j]+a[xx].x,dp[i][j][xx-i-j]);//,cout<<"dp["<<i<<"]["<<j<<"]=max(dp["<<i-1<<"]["<<j<<"]+a["<<xx<<"].x,dp["<<i<<"]["<<j<<"])="<<dp[i][j][xx-i-j]<<endl;
					if(j>0) dp[i][j][xx-i-j]=max(dp[i][j-1][xx-i-j]+a[xx].y,dp[i][j][xx-i-j]);//,cout<<"dp["<<i<<"]["<<j<<"]=max(dp["<<i<<"]["<<j-1<<"]+a["<<xx<<"].y,dp["<<i<<"]["<<j<<"])="<<dp[i][j][xx-i-j]<<endl;

				}
			}	
		}
		ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j<=n/2)ans=max(ans,dp[i][j][n-i-j]);
			}
		}
		cout<<ans<<'\n';
	}
//	}
	return 0;
}
