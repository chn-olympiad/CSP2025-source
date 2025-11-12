//GZ-S00095 贵阳市观山湖区外国语实验中学 周一宸 
#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int T;
int n;
int a[N][4];
//int dp[N][N][N];
map<int,map<int,map<int,int> > > dp;
int ma;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ma = 0;
	cin>>T;
	for(int i =1;i<=T;i++){
		ma= 0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			for(int j =1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i = 0;i<=n/2;i++){
			for(int j =0;j<=min(n/2,n-j);j++){
				for(int x = 0;x<=min(n/2,n-i-j);x++){
					dp[i][j][x] = 0;
					if(i>0)dp[i][j][x] = max(dp[i-1][j][x]+a[i+j+x][1],dp[i][j][x]);
					if(j>0)dp[i][j][x] =max(dp[i][j-1][x]+a[i+j+x][2],dp[i][j][x]);
					if(x>0)dp[i][j][x] =max(dp[i][j][x-1]+a[i+j+x][3],dp[i][j][x]);
					ma = max(ma,dp[i][j][x]);
				}
			}
		}
		cout<<ma<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
