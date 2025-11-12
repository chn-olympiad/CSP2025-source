#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int t,n,a[N][3];
struct club{
	int v,x,y,z;	
} dp[N][3];
void init(int i,int j,int k){
	dp[i][j].x=dp[i-1][k].x,dp[i][j].y=dp[i-1][k].y,dp[i][j].z=dp[i-1][k].z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;++i)
			for(int j=0;j<3;++j) cin>>a[i][j];
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				dp[i][j].v=dp[i-1][j].v,init(i,j,j);
				if(j==0){
					if(dp[i-1][0].x<m)
						if(dp[i-1][0].v+a[i][0]>dp[i][j].v) dp[i][j].v=dp[i-1][0].v+a[i][0],init(i,j,0);
					if(dp[i-1][1].x<m)
						if(dp[i-1][1].v+a[i][0]>dp[i][j].v) dp[i][j].v=dp[i-1][1].v+a[i][0],init(i,j,1);
					if(dp[i-1][2].x<m)
						if(dp[i-1][2].v+a[i][0]>dp[i][j].v) dp[i][j].v=dp[i-1][2].v+a[i][0],init(i,j,2);
					++dp[i][j].x;
				}
				if(j==1){
					if(dp[i-1][0].y<m)
						if(dp[i-1][0].v+a[i][1]>dp[i][j].v) dp[i][j].v=dp[i-1][0].v+a[i][1],init(i,j,0);
					if(dp[i-1][1].y<m)
						if(dp[i-1][1].v+a[i][1]>dp[i][j].v) dp[i][j].v=dp[i-1][1].v+a[i][1],init(i,j,1);
					if(dp[i-1][2].y<m)
						if(dp[i-1][2].v+a[i][1]>dp[i][j].v) dp[i][j].v=dp[i-1][2].v+a[i][1],init(i,j,2);
					++dp[i][j].y;
				}
				if(j==2){
					if(dp[i-1][0].z<m)
						if(dp[i-1][0].v+a[i][2]>dp[i][j].v) dp[i][j].v=dp[i-1][0].v+a[i][2],init(i,j,0);
					if(dp[i-1][1].z<m)
						if(dp[i-1][1].v+a[i][2]>dp[i][j].v) dp[i][j].v=dp[i-1][1].v+a[i][2],init(i,j,1);
					if(dp[i-1][2].z<m)
						if(dp[i-1][2].v+a[i][2]>dp[i][j].v) dp[i][j].v=dp[i-1][2].v+a[i][2],init(i,j,2);
					++dp[i][j].z;
				}
			}
		}
		cout<<max({dp[n][0].v,dp[n][1].v,dp[n][2].v})<<'\n';
		memset(dp,0,sizeof(dp));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
