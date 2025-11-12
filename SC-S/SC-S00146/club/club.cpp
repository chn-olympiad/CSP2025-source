#include<iostream>
#include<cstdio>
using namespace std;
int a[200000][3],dp[300][300][300];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int n;
		cin>>n;	
		for(int i=0;i<300;i++)for(int j=0;j<300;j++)for(int k=0;k<300;k++)dp[i][j][k]=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		dp[0][0][0]=0;
		for(int p=1;p<=n;p++){
			for(int i=n/2;i>=0;i--){
				for(int j=n/2;j>=0;j--){
					for(int k=n/2;k>=0;k--){
						//cout<<i<<j<<k<<" ";
						int x=0,y=0,z=0;
						if(i>0)x=dp[i-1][j][k]+a[p][0];
						if(j>0)y=dp[i][j-1][k]+a[p][1];
						if(k>0)z=dp[i][j][k-1]+a[p][2];
						dp[i][j][k]=max(x,max(y,z));
						//cout<<dp[i-1][j][k]+a[p][0]<<dp[i][j-1][k]+a[p][1]<<dp[i][j][k-1]+a[p][2];
					}
				}
			}
		}
		if(t)cout<<"\n";
		cout<<dp[n/2][n/2][n/2];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}