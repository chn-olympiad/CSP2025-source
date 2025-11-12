#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
//const int N=205;
int t,a[N][5],tt[N][5][5];
ll dp[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				for(int k=1;k<=3;k++)
					tt[i][j][k]=0;
				dp[i][j]=0;
			}
		}
		int mx=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){//xian
				for(int p=1;p<i;p++){
					for(int k=1;k<=3;k++){//qian
						if(tt[p][k][j]<mx){
							dp[i][j]=max(dp[p][k]+a[i][j],dp[i][j]);
							if(dp[p][k]+a[i][j]>=dp[i][j]){
								for(int o=1;o<=3;o++){
									tt[i][j][o]=tt[p][k][o];
								}
								tt[i][j][j]=tt[p][k][j]+1;
							}
						}
					}
				}
				if(i==1){
					dp[i][j]=a[i][j];
					tt[i][j][j]=1;
				}
			}
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
	return 0;
}
/*
*/
