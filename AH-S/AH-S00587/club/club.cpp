#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],c[100100];
struct node{
	int zhi;
	int a,b,c;
}dp[100100][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<3;j++){
			dp[i][j].a=n/2;
			dp[i][j].b=n/2;
			dp[i][j].c=n/2;
			}
		}
		for(int i=1;i<=n;i++){//枚举每个数
			for(int j=0;j<3;j++){//选哪个社团
				if(dp[i-1][j].a>0){
					if(dp[i][0].zhi<dp[i-1][j].zhi+a[i]){
						dp[i][0].zhi=dp[i-1][j].zhi+a[i];
						dp[i][0].a=dp[i-1][j].a-1;
						dp[i][0].b=dp[i-1][j].b;
						dp[i][0].c=dp[i-1][j].c;
					}
				}
				else{
					if(dp[i][0].zhi<dp[i-1][j].zhi){
						dp[i][0].zhi=dp[i-1][j].zhi;
						dp[i][0].a=dp[i-1][j].a;
						dp[i][0].b=dp[i-1][j].b;
						dp[i][0].c=dp[i-1][j].c;
					}
				}
					
				if(dp[i-1][j].b>0){
					if(dp[i][1].zhi<dp[i-1][j].zhi+b[i]){
						dp[i][1].zhi=dp[i-1][j].zhi+b[i];
						dp[i][1].a=dp[i-1][j].a;
						dp[i][1].b=dp[i-1][j].b-1;
						dp[i][1].c=dp[i-1][j].c;
					}
				}
				else{
					if(dp[i][1].zhi<dp[i-1][j].zhi){
						dp[i][1].zhi=dp[i-1][j].zhi;
						dp[i][1].a=dp[i-1][j].a;
						dp[i][1].b=dp[i-1][j].b;
						dp[i][1].c=dp[i-1][j].c;
					}
				}
				
				if(dp[i-1][j].c>0){
					if(dp[i][2].zhi<dp[i-1][j].zhi+c[i]){
						dp[i][2].zhi=dp[i-1][j].zhi+c[i];
						dp[i][2].a=dp[i-1][j].a;
						dp[i][2].b=dp[i-1][j].b;
						dp[i][2].c=dp[i-1][j].c-1;
					}
				}
				else{
					if(dp[i][2].zhi<dp[i-1][j].zhi){
						dp[i][2].zhi=dp[i-1][j].zhi;
						dp[i][2].a=dp[i-1][j].a;
						dp[i][2].b=dp[i-1][j].b;
						dp[i][2].c=dp[i-1][j].c;
					}
				}
			}
			//cout<<dp[i][0].zhi<<" "<<dp[i][1].zhi<<" "<<dp[i][2].zhi<<endl;
		}
		cout<<max(dp[n][0].zhi,max(dp[n][1].zhi,dp[n][2].zhi));
	}
	
	return 0;
}
