#include <bits/stdc++.h>
using namespace std;
const int N =1e5+10;
struct P{
	int x,a,b,c;
}dp[N][4];
int t,n , a[N][4];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
	//	x=y=z=ans=cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1 ;i<=n;i++){
			for(int j =1 ;j<=3;j++)cin>>a[i][j];
		}
		for(int i =1;i<=n;i++){
			for(int j =1;j<=3;j++){
				for(int k =1 ;k<=3;k++){
					if(dp[i-1][k].a+(j==1)<=n/2 &&dp[i-1][k].b+(j==2)<=n/2 &&dp[i-1][k].c+(j==3)<=n/2){
						if(dp[i-1][k].x+a[i][j] >= dp[i][j].x){
							dp[i][j] = {dp[i-1][k].x+a[i][j],dp[i-1][k].a+(j==1),dp[i-1][k].b+(j==2) ,dp[i-1][k].c+(j==3)};
						}
					}
				}
			}
		}
//		cout<<dp[n][1].x<<dp[n][1].a<<dp[n][1].b<<dp[n][1].c<<'\n';
//		cout<<dp[n][2].x<<dp[n][2].a<<dp[n][2].b<<dp[n][2].c<<'\n';
//		cout<<dp[n][3].x<<dp[n][3].a<<dp[n][3].b<<dp[n][3].c<<'\n';
//		
		cout<<max(dp[n][1].x,max(dp[n][2].x,dp[n][3].x))<<'\n';
		
		for(int i =1;i<=n;i++)for(int j=1 ;j<=3;j++)dp[i][j]={0,0,0};
		
	}	
}
