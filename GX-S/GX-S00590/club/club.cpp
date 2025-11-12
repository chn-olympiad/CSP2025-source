#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
long long dp[100005][5];
int v[100005][5][5];
int main(){
	 freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		dp[1][1]=a[1][1];
		v[1][1][1]=1;
		dp[1][2]=a[1][2];
		v[1][2][2]=1;
		dp[1][3]=a[1][3];
		v[1][3][3]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				int mx=0,id=0;
				for(int k=1;k<=3;k++){
					if(dp[i-1][k]+a[i][j] > mx&&v[i-1][j][k]<n/2){
						mx=dp[i-1][k]+a[i][j];
						id = k;
					}
					v[i][j][k]=v[i-1][j][k];
				}
				if(id!=0){
					dp[i][j]=mx;
					v[i][j][id]++;
					
				}else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		for(int i = 1;i<= n;i++){
			for(int j = 1;j<=3;j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << max(dp[n][1],max(dp[n][2],dp[n][3])) << endl;;
	}
	return 0;
}
