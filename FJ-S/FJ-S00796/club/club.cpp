#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a,b,c,d,e,f,g,h;
ll dp[100005][4][5];
ll fs[100005][4];
//int kj[50005][5005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>a; 
		memset(fs,0,sizeof(fs));
		for(int i=1;i<=a;i++){
			cin>>fs[i][1]>>fs[i][2]>>fs[i][3];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=a;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j==1&&dp[i-1][k][1]<a/2&&dp[i][j][4]<=dp[i-1][k][4]+fs[i][j]){
						dp[i][j][4]=dp[i-1][k][4]+fs[i][j];
						dp[i][j][1]=dp[i-1][k][1]+1;
						dp[i][j][2]=dp[i-1][k][2];
						dp[i][j][3]=dp[i-1][k][3];
//						cout<<"*1 ";
					}
					if(j==2&&dp[i-1][k][2]<a/2&&dp[i][j][4]<=dp[i-1][k][4]+fs[i][j]){
						dp[i][j][4]=dp[i-1][k][4]+fs[i][j];
						dp[i][j][1]=dp[i-1][k][1];
						dp[i][j][2]=dp[i-1][k][2]+1;
						dp[i][j][3]=dp[i-1][k][3];
//						cout<<"*2 ";
					}
					if(j==3&&dp[i-1][k][3]<a/2&&dp[i][j][4]<=dp[i-1][k][4]+fs[i][j]){
						dp[i][j][4]=dp[i-1][k][4]+fs[i][j];
						dp[i][j][1]=dp[i-1][k][1];
						dp[i][j][2]=dp[i-1][k][2];
						dp[i][j][3]=dp[i-1][k][3]+1;
//						cout<<"*3 ";
					}
				}
			}	
		}
		ll daan=0;
		for(int i=1;i<=3;i++){
			daan=max(daan,dp[a][i][4]);
		}
//		for(int i=1;i<=2;i++){
//			cout<<dp[i][1][4]<<" "<<dp[i][3][4]<<"\n";
//		}
//		for(int j=3;j<=4;j++){
//			cout<<dp[j][2][4]<<"\n";
//		}
		cout<<daan<<"\n";
	}
}
