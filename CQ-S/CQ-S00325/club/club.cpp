#include<bits/stdc++.h>
using namespace std;
int dp[105][105][105],t,n,ans,f;
int a[100005][5],e[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		memset(dp,0,sizeof dp); 
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0&&a[i][3]==0) f=1;
		}
		if(!f){
			for(int i=1;i<=n;i++) e[i]=a[i][1];
			sort(e+1,e+1+n,cmp);int ans=0;
			for(int i=1;i<=n/2;i++)ans+=e[i];
			cout<<ans<<endl;
			continue;
		}
		for(int w=1;w<=n;w++){
			for(int i=min(w,n/2);i>=0;i--){
				for(int j=min(w-i,n/2);j>=0;j--){
					for(int k=min(w-i-j,n/2);k>=0;k--){
						if(i) dp[i][j][k]=max(dp[i-1][j][k]+a[w][1],dp[i][j][k]);
						if(j) dp[i][j][k]=max(dp[i][j-1][k]+a[w][2],dp[i][j][k]);
						if(k) dp[i][j][k]=max(dp[i][j][k-1]+a[w][3],dp[i][j][k]);
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
60pts
*/

