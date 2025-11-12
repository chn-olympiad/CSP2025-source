#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][5],dp[N][5],sum[N][5][5],b[N],c[N];
struct node{
	int sum,num;
}d[N]
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]!=0||a[i][3]!=0){
				flag1=1;
			}if(a[i][3!=0]){
				flag2=1;
			}
		}int ans=0;
		if(!flag1){
			for(int i=1;i<=n;i++){
				b[i]=a[i][2];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		dp[1][1]=a[1][1];
		dp[1][2]=a[1][2];
		dp[1][3]=a[1][3];
		sum[1][1][1]=1;
		sum[1][2][2]=1;
		sum[1][3][3]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int o=1;o<=3;o++){
					if(sum[i-1][j][o]<n/2){
						if(dp[i][o]<dp[i-1][j]+a[i][o]){
							dp[i][o]=dp[i-1][j]+a[i][o];
							sum[i][o][1]=0;
							sum[i][o][2]=0;
							sum[i][o][3]=0;
							sum[i][o][o]=1;
							sum[i][o][1]+=sum[i-1][j][1];
							sum[i][o][2]+=sum[i-1][j][2];
							sum[i][o][3]+=sum[i-1][j][3];
						}
						ans=max(ans,dp[i][o]);
					}else if(n>2){
						if(a[i][o]+a[i-1][j]>dp[i][o]){
							dp[i][o]=a[i][o]+a[i-1][j];
							sum[i][o][1]=0;
							sum[i][o][2]=0;
							sum[i][o][3]=0;
							sum[i][o][o]=1;
							sum[i][o][j]=1;
						}
						ans=max(ans,dp[i][o]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

