#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long dp[100010][3],a[100010][3];
long long sh,ans;
int f;
int x,y,z;
int jilu[100010][3][3];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
while(t--){
jilu[0][0][0]=1;
jilu[0][1][1]=1;
jilu[0][2][2]=1;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	 dp[0][0]=a[0][0],dp[0][1]=a[0][1],dp[0][2]=a[0][2];
	 for(int i=1;i<n;i++){
		 for(int j=0;j<3;j++){
			 if(a[i][j]+dp[i-1][0]>dp[i][0]&&jilu[i-1][j][0]<n/2){
				 dp[i][0]=a[i][j]+dp[i-1][0];
				 x=j;
			 }
			 if(a[i][j]+dp[i-1][1]>dp[i][1]&&jilu[i-1][j][1]<n/2){
				 dp[i][1]=a[i][j]+dp[i-1][1];
				 y=j;
			 }
			 if(a[i][j]+dp[i-1][2]>dp[i][2]&&jilu[i-1][j][2]<n/2){
				 dp[i][2]=a[i][j]+dp[i-1][2];
				 z=j;
			 }
		 }
		 jilu[i][0][0]=jilu[i-1][x][0],jilu[i][0][1]=jilu[i-1][x][1],jilu[i][0][2]=jilu[i-1][x][2],jilu[i][0][0]++;
		 jilu[i][1][0]=jilu[i-1][y][0],jilu[i][1][1]=jilu[i-1][y][1],jilu[i][1][2]=jilu[i-1][y][2],jilu[i][1][1]++;
		 jilu[i][2][0]=jilu[i-1][z][0],jilu[i][2][1]=jilu[i-1][z][1],jilu[i][2][2]=jilu[i-1][z][2],jilu[i][2][2]++;
 }
 long long h=0;
 for(int i=0;i<3;i++){
	 h=max(h,dp[n-1][i]);
 }
 cout<<h<<endl;
 for(int i=0;i<n;i++)for(int j=0;j<3;j++)dp[i][j]=0,jilu[i][j][0]=0,jilu[i][j][1]=0,jilu[i][j][2]=0;
	}
return 0;
}
