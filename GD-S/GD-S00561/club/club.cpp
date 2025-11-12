#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][15];
int ans[100005];
int ma1,ma2,ma3;
int maxx;
int a1,a2,a3;
int r,l;
int dp[100005][15];
int maxx1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans[0]=999999999;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			maxx=0;
			if((a[j][1]>a[j][2])&&(a[j][1]>a[j][3])&&(a1+1<=n/2)){
				ans[j]=a[j][1];
				dp[j][1]=1;
				a1++;
				if(ans[ma1]>ans[j]){
					ma1=j;
				}
			}else if((a[j][1]>a[j][2])&&(a[j][1]>a[j][3])&&(a1+1>n/2)){
				for(int k=1;k<=3;k++){
					for(int m=1;m<=3;m++){
						if(k!=m){
							if(maxx<a[ma1][k]+a[j][m]){
								maxx=a[ma1][k]+a[j][m];
								r=k;
								l=m;
							} 
						}
					}
				}
				ans[ma1]=a[ma1][r];
				dp[ma1][1]=0;
				dp[ma1][2]=0;
				dp[ma1][3]=0;
				dp[ma1][r]=1;
				ans[j]=a[j][l];
				dp[j][1]=0;
				dp[j][2]=0;
				dp[j][3]=0;
				dp[j][l]=1;
				ma1=0;
				for(int z=1;z<=n;z++){
					
					if(dp[z][1]==1){
						if(ans[z]<ans[ma1]){
							ma1=z;
						}
					}
				}
			}
			else if((a[j][2]>a[j][1])&&(a[j][2]>a[j][3])&&(a2+1<=n/2)){
				ans[j]=a[j][2];
				dp[j][2]=1;
				a2++;
				if(ans[ma2]>ans[j]){
					ma2=j;
				}
			}else if((a[j][2]>a[j][1])&&(a[j][2]>a[j][3])&&(a2+1>n/2)){
				for(int k=1;k<=3;k++){
					for(int m=1;m<=3;m++){
						if(k!=m){
							if(maxx<a[ma2][k]+a[j][m]){
								maxx=a[ma2][k]+a[j][m];
								r=k;
								l=m;
							} 
						}
					}
				}
				ans[ma2]=a[ma2][r];
				dp[ma2][1]=0;
				dp[ma2][2]=0;
				dp[ma2][3]=0;
				dp[ma2][r]=1;
				ans[j]=a[j][l];
				dp[j][1]=0;
				dp[j][2]=0;
				dp[j][3]=0;
				dp[j][l]=1;
				ma2=0;
				for(int z=1;z<=n;z++){
					if(dp[z][2]==1){
						
						if(ans[z]<ans[ma2]){
							ma2=z;
							//cout<<ma2<<endl;
						}
					}
				}
			}else if((a[j][3]>a[j][1])&&(a[j][3]>a[j][2])&&(a3+1<=n/2)){
				ans[j]=a[j][3];
				dp[j][3]=1;
				a3++;
				if(ans[ma3]>ans[j]){
					ma3=j;
				}
			}else if((a[j][3]>a[j][1])&&(a[j][3]>a[j][2])&&(a3+1>n/2)){
				for(int k=1;k<=3;k++){
					for(int m=1;m<=3;m++){
						if(k!=m){
							if(maxx<a[ma3][k]+a[j][m]){
								maxx=a[ma3][k]+a[j][m];
								r=k;
								l=m;
							} 
						}
					}
				}
				ans[ma3]=a[ma3][r];
				dp[ma3][1]=0;
				dp[ma3][2]=0;
				dp[ma3][3]=0;
				dp[ma3][r]=1;
				ans[j]=a[j][l];
				dp[j][1]=0;
				dp[j][2]=0;
				dp[j][3]=0;
				dp[j][l]=1;
				ma3=0;
				for(int z=1;z<=n;z++){
					if(dp[z][3]==1){
						
						if(ans[z]<ans[ma3]){
							ma3=z;
						}
					}
				}
			}
		}
		for(int d=1;d<=n;d++){
			maxx1+=ans[d];
			//cout<<ans[d]<<endl;
		}
		//cout<<dp[2][2]<<endl;
		cout<<maxx1<<endl;
		maxx=0;
		maxx1=0;
		ma1=0;
		ma2=0;
		ma3=0;
		a1=0;
		a2=0;
		a3=0;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
	}

	return 0;
} 
