//GZ-S00250 毕节七星关东辰实验学校 杜启民 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define ll long long
#define heap priority_heap
using namespace std;

const int N=1e5+1;
int ans;
int n,s[N][4],dp[201][201][201];

inline void solve(){
	
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2]>>s[i][3];
	}
	
	//ta1
	int m=n/2;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i&&j<=(n/2);j++){
			for(int k=0;k<=i&&(j+k<=i)&&k<=(n/2);k++){
				
				if(i-j-k>m){continue;}
				
			//	cout<<"i:"<<i<<' '<<"j:"<<j<<' '<<"k:"<<k<<' ';
				if(j==0&&k==0){
					int a=dp[i-1][j][k]+s[i][3];
					dp[i][j][k]=a;
				}if(j==0&&k!=0&&k==i){
					int b=dp[i-1][j][k-1]+s[i][2];
					dp[i][j][k]=b;
				}if(j!=0&&k==0&&j==i){
					int c=dp[i-1][j-1][k]+s[i][1];
					dp[i][j][k]=c;
				}if(j!=0&&k==0&&j!=i){
					int a=dp[i-1][j][k]+s[i][3];
					int b=dp[i-1][j-1][k]+s[i][1];
					dp[i][j][k]=max(a,b);
				}if(j==0&&k!=0&&k!=i){
					int a=dp[i-1][j][k]+s[i][3];
					int c=dp[i-1][j][k-1]+s[i][2];
					dp[i][j][k]=max(a,c);
				}if(j!=0&&k!=0&&j+k==i){
				//	int a=dp[i-1][j][k]+s[i][3];
					int b=dp[i-1][j-1][k]+s[i][1];
					int c=dp[i-1][j][k-1]+s[i][2];
					dp[i][j][k]=max(b,c);
				}if(j!=0&&k!=0&&j+k<i){
					int a=dp[i-1][j][k]+s[i][3];
					int b=dp[i-1][j-1][k]+s[i][1];
					int c=dp[i-1][j][k-1]+s[i][2];
					dp[i][j][k]=max(max(a,b),c);
				}
				if(i==n){ans=max(ans,dp[i][j][k]);}
			//	cout<<dp[i][j][k]<<'\n';
			}
		}
	}
	//
	/*
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[n][i][j]<<' ';
		}cout<<'\n';
	}*/
	/*
	for(int i=0;i<=n;i++)cout<<dp[n][i][0]<<' ';
	cout<<'\n';
	for(int i=0;i<=n;i++)cout<<dp[n][0][i]<<' ';
	cout<<'\n';*/
	
	cout<<ans<<'\n';
	
	return;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int T=1;
	cin>>T;
	while(T--)solve();
	
	return 0;
}
