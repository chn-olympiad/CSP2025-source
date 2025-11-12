//GZ-S00001 遵义市汇川区第十小学 丁家亿 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[10000000][3];
ll f[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{	
		f[0]=0;
		f[1]=0;
		f[2]=0;
		int n;
		cin>>n;
		int m=n/2;
		int len=0;
		ll a[n][3];
		for(int i=0;i<n;i++)
		{	
			for(int j=0;j<3;j++){							
				cin>>a[i][j];
				dp[i][j]=0;
			}		
		}
		dp[0][0]=a[0][0];
		dp[0][1]=a[0][1];
		dp[0][2]=a[0][2];
		if(dp[0][0]>dp[0][1]&&dp[0][0]>dp[0][2])
		{
			f[0]++;
		}
		if(dp[0][1]>dp[0][0]&&dp[0][1]>dp[0][2])
		{
			f[1]++;
		}	
		if(dp[0][2]>dp[0][0]&&dp[0][2]>dp[0][1])
		{
			f[2]++;
		}
		for(int i=1;i<n;i++)
		{	
			for(int j=0;j<3;j++)
			{	
				if(f[0]==m){
					if(f[1]==m){
						dp[i][j]=dp[i-1][2]+a[i][j];
					}else{
						if(dp[i-1][1]>dp[i-1][2]){
							dp[i][j]=dp[i-1][1]+a[i][j];
						}else {
							dp[i][j]=dp[i-1][2]+a[i][j];
						}
					}
				}
				else if(f[1]==m){
					if(f[0]==m){
						dp[i][j]=dp[i-1][2]+a[i][j];
					}else{
						if(dp[i-1][0]>dp[i-1][2]){
							dp[i][j]=dp[i-1][0]+a[i][j];
						}else {
							dp[i][j]=dp[i-1][2]+a[i][j];
						}
					}
				}else if(f[2]==m){
					if(f[0]==m){
						dp[i][j]=dp[i-1][1]+a[i][j];
					}else{
						if(dp[i-1][0]>dp[i-1][1]){
							dp[i][j]=dp[i-1][0]+a[i][j];
						}else {
							dp[i][j]=dp[i-1][1]+a[i][j];
						}
					}
				}else if(dp[i-1][0]>dp[i-1][1]&&dp[i-1][0]>dp[i-1][2]){
					dp[i][j]=dp[i-1][0]+a[i][j];
				}else if(dp[i-1][1]>dp[i-1][0]&&dp[i-1][1]>dp[i-1][2]){
					dp[i][j]=dp[i-1][1]+a[i][j];
				}else if(dp[i-1][2]>dp[i-1][0]&&dp[i-1][2]>dp[i-1][1]){
					dp[i][j]=dp[i-1][2]+a[i][j];
				}
				if(dp[i][0]>dp[i][1]&&dp[i][0]>dp[i][2]){
					f[0]++;
				}else if(dp[i][1]>dp[i][0]&&dp[i][1]>dp[i][2]){
					f[1]++;
				}else if(dp[i][2]>dp[i][0]&&dp[i][2]>dp[i][1]){
					f[2]++;
				}	
			}
		}
		ll num=max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
		cout<<num<<endl;
	}
	return 0; 
}
