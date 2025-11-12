#include<bits/stdc++.h>
using namespace std;

int T;
int n;
int a[100005][4];

int dp[100005][4][5];//But dp[i][j][4] means the max of the ith students choose the jth club

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		
		cin>>n;
		dp[0][1][4]=dp[0][2][4]=dp[0][3][4]=0;
		dp[0][1][1]=dp[0][2][1]=dp[0][3][1]=0;
		dp[0][1][2]=dp[0][2][2]=dp[0][3][2]=0;
		dp[0][1][3]=dp[0][2][3]=dp[0][3][3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			
		}
		int m=0,ans=0;
		for(int i=1;i<=n;i++){
			ans=0;
			for(int j=1;j<=3;j++){//calc dp[i][j]
				m=0;
				int mini=0;
				for(int k=1;k<=3;k++){//choose the last students' kth
					
					if(dp[i-1][k][j]<=n/2-1){
						if(a[i][j]+dp[i-1][k][4]>m){
							mini=k;
							m=a[i][j]+dp[i-1][k][4];
							//cout<<"*"<<i<<j<<k<<','<<dp[i-1][k][1]<<dp[i-1][k][2]<<dp[i-1][k][3]<<endl;
						}
					}
				}
				dp[i][j][4]=m;
				dp[i][j][1]=dp[i-1][mini][1];
				dp[i][j][2]=dp[i-1][mini][2];
				dp[i][j][3]=dp[i-1][mini][3];
				dp[i][j][j]++;
				ans=max(ans,m);
				//cout<<i<<','<<j<<','<<m<<','<<mini<<'#'<<dp[i][j][1]<<dp[i][j][2]<<dp[i][j][3]<<endl;
			}
		}
		cout<<ans<<endl;
		
		/*
		 * dp[i][j]=i students j MingE max satisfy
		 * dp[i][j]=max(a[i][1]+dp[i-1][j],a[i][2]+dp[i-1][j],a[i][3]+dp[i-1][j])
		 * 
		 * 
		 * if(dp[i-1][1].one<=n/2-1){
		 *     m=max(m,a[i][1]+dp[i-1][1].val);
		 * }
		 * if(dp[i-1][2].one<=n/2-1){
		 *     m=max(m,a[i][1]+dp[i-1][1].val);
		 * }
		 * ......
		 * 8 7 6
		 * 8 7 6
		 * 4 4 0
		 * 9 4 4
		 * 
		 * 
		 * 10 9 8
		 * 4 0 0
		 * 
		 * 
		 *   0 1 
		 * 1   10 
		 * 2   
		 * 
		 *    1 2 3
		 * 1 10 9 8
		 * 2 13 10 10
		 
		 * */
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
