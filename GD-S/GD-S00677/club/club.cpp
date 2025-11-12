#include<bits/stdc++.h>
using namespace std;

struct people{
	int h[4]={0};
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t=0;
	cin >> t;
	while(t--){
		int n=0;
		cin >> n;
		struct people num[n+1];
		
		for(int i=1;i<=n;i++){
			cin >> num[i].h[1] >> num[i].h[2] >> num[i].h[3];
		}
		
		
		vector<vector<int> > dp(n+1,vector<int>(4,0));
		
		int a=0,b=0,c=0;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j]=max(dp[i-1][1]+num[i].h[j] , max(dp[i-1][2]+num[i].h[j] , dp[i-1][3]+num[i].h[j]));
			}
		} 
		cout << max(dp[n][1], max(dp[n][2] , dp[n][3] )) << endl;
	}
	return 0;
}
