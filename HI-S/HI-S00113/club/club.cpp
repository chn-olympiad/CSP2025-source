#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005],b[100005],c[100005],d[100005],cnt;
int dp[35][35][35][35];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int flag1=0,flag2=0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) flag1=1;
			if(c[i]!=0) flag2=1;
		}
		if(!flag1){
			int ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			  ans+=a[i];
			cout<<ans<<'\n';
			continue;
		}
		else {
			for(int i=1;i<=n;i++){
				for(int j=0;j<n/2;j++){
				    for(int k=0;k<n/2;k++){
				    	for(int p=0;p<n/2;p++){
				    		dp[i][j][k][p]=max(dp[i][j][k][p],dp[i-1][j][k][p]);
				    		for(int l=1;l<=3;l++){
				    			int w;
				    			if(l==1) w=a[i],dp[i][j+1][k][p]+=w;
				    			if(l==2) w=b[i],dp[i][j][k+1][p]+=w;
				    			if(l==3) w=c[i],dp[i][j][k][p+1]+=w;
							}
						}
					}
				}
			}
			int cnt=0;
			for(int i=1;i<=n/2;i++)
			for(int j=1;j<=n/2;j++)
			for(int k=1;k<=n/2;k++){
				if(i+j+k==n){
					cnt=max(cnt,dp[n][i][j][k]);
				}
			}
			cout<<cnt<<'\n';
		}
	    
	}
	return 0;
} 
